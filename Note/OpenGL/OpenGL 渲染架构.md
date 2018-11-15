# GPU

GPU从诞生到现在，虽然结构和性能都有很大的优化，但是有三点一直没有变过：

1. CPU和GPU是两个独立的硬件
2. CPU和GPU是主从关系
3. CPU和GPU之间的数据交换成本很高
   - 建立和维护通信连接
   - 通信带宽



### CPU和GPU的数据交换（From StackOverflow）

- GPU的一系列寄存器经过BIOS映射，可以使CPU可以访问GPU的显存，指示GPU执行操作。CPU在这些寄存器中插入一些值就可以将显存映射到内存地址空间，从而可以被CPU访问。接着CPU将指令加载到该空间，然后再问寄存器写一个值告知GPU执行由CPU加载的指令
- CPU写的信息包括了GPU运行所需的“软件”，或者可称为GPU上的一个迷你操作系统。这个“软件”捆绑在驱动中，从而驱动可以处理CPU和GPU间的只能分配（在两个设备中各运行自己的部分代码）
- 总之，CPU和GPU的通信模式就是CPU向映射到内存地址的显存写指令和信息，然后在通过一个寄存器告诉GPU去执行这些指令或者处理这些信息。

### 通用的优化策略

- 减少数据传输量
- 减少数据传输次数
- 提高并行度
- 与网络编程的Client-Server结构下做优化有异曲同工之妙
- OpenGL就是基于Client-Server结构设计的 



# OpenGL框架概述

### 函数式API

- OpenGL的所有命令都是C-Style函数
- 统一GL标准的好处是，不同平台不同厂商的不同GPU驱动可以使用同一份头文件
- OpenGL和OpenGLES的函数形式互相兼容
- 便于扩展（GLEW：OpenGL Extension Wrangler），扩展升级对于向前兼容有天然亲和性



## GLContext

- OpenGL的API系统基于状态机，所有的状态记录在一个上下文中，称为 GLContext

- GLContext是线程绑定的，一个Context不可能同时是两个线程的当前上下文。

- 虽然OpenGL是跨平台的，但GLContext的创建和管理是平台相关(EGL、EAGL、WGL、 GLX)

- 所有的GLCommand只影响当前的Context的状态

- Context之间可以完全独立，也可以共享数据。但共享只能存在于同一 GL驱动实现，我们不能对NVidia独显创建的Context和Intel集显创建的Context进行共享，即使他们都运行在同一台计算机上。 

- 只有用用数据的对象才能进行共享：比如顶点和索引，shader，纹理，但FrameBuffer是不能共享的。



# OpenGL的同步机制



## GLCommand的三种状态

- unissued： CPU已经执行该命令，将其交给驱动，但驱动尚未交给显卡
- issued but not complete：驱动将命令交给显卡，但显卡还没有执行此命令。所有的显卡都会有一块Buffer存放Command队列，除非出错，Command队列的所有命令都会被执行。
- Complete：队列中的命令被显卡执行完成。



## Flush 和Complete

![](C:\Users\dongtaiyou\Desktop\实时渲染\OpenGL Flush and Finish.PNG)

OpenGL提供了两种不同的同步机制: glFlush和glComplete，两者都会阻塞Client：

- glFlush：等所有Unissued Command都写入显卡才返回

- glFlinish：等所有Unissued、Issued Command都Complete才返回

## 隐式同步

- 除了主动调用Flush和Finish之外，一些Command自身也会隐式同步
- Swap framebuffer
- Read from framebuffer to CU memory
- Write to OpenGL buffer object
- Update part of texture from CPU memory
- 然后OpenGL并没有对哪些Command需要同步哪些不需要同步做出明确规范，更多依赖驱动的实现



## Fence——细粒度同步

- glFenceSync
- glClientWaitSync
- glWaitSync



# 多线程之惑

## 资源流向

- CPU传入GPU除了Command还有各种资源
- 资源的流向：
  - CPU->CPU
  - CPU->GPU
  - GPU->CPU
  - GPU->GPU
- 除了CPU->CPU，其他三种的调度都依赖驱动。



## OpenGL的内存模型

- 内存和显存泾渭分明
- 共享内存的显存：从内存中划出一块专用于显存，但可用内存变小。
- 用户数据存放在Pageable Host Memory中（可被交换到虚拟的内存），GOU无法直接访问。
- Transfer Data时，驱动将Pageable Memroy中的数据拷贝到Pinned Memory（不会被交换到虚存，好像用图钉别住一样）中。
- GL驱动通过DMA(Direct Memory Access)将数据传输给GPU，这就是glBufferData的执行模式