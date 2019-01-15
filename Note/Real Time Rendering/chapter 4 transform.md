[TOC]


# 线性代数基础

## 矩阵

### 转置矩阵 Transposed matrix

在线性代数中，矩阵A的转置是另一个矩阵 $A^T$，由下列等价动作建立：

- 把A的横列写为$A^T$的纵列



   

- 把A的纵列写为$A^T$的横行

形式上说，*m* × *n*矩阵*A*的转置是*n* × *m*矩阵:

$ A^T_{ij} = A_{ij} for 1 \leq i \leq n, 1 \leq j \leq m $

注：$A^T$ (转置矩阵)与$A^{-1}$(逆矩阵)不同

### 逆矩阵 Inverse matrix

在线性代数中，给定一个n阶方阵A，若存在一n阶方阵B，使得$AB=BA=I_n$，其中$I_n$为n阶单位矩阵，则称A是可逆的，且B是A的逆矩阵，记作 $A ^{-1} $。

只有正方形（n×n）的矩阵，亦即方阵，才可能、但非必然有逆矩阵。

### 正交矩阵 orthogonal matrix

在矩阵论中，正交矩阵是一个方块矩阵Q，其元素为实数，而且行与列皆为正交的单位向量，使得该矩阵的转置矩阵为其逆矩阵：
$$
Q^T = Q^{-1} \Leftrightarrow Q^TQ = QQ^T = I
$$
其中，I为单位矩阵。正交矩阵的行列式值必定为+1或者-1，因为：
$$
1 = det(I) = det(Q^TQ) = det(Q^T)det(Q) = (det(Q))^2 \Rightarrow |Q| = \pm1
$$
伴随矩阵的一些重要性值：

- 作为一个线性映射（变换矩阵），正交矩阵保持距离不变，所以它是一个[保距映射](https://zh.wikipedia.org/wiki/%E7%AD%89%E8%B7%9D%E5%90%8C%E6%9E%84)，具体例子为旋转与镜射
- 行列式值为+1的正交矩阵，称为**特殊正交矩阵**，它是一个旋转矩阵
- 行列式值为-1的正交矩阵，称为[瑕旋转](https://zh.wikipedia.org/wiki/%E7%91%95%E6%97%8B%E8%BD%89)矩阵。瑕旋转是旋转加上镜射。镜射也是一种瑕旋转。






# Transforms

> What if angry vectors veer Round your sleeping head, and form.
> There’s never need to fear Violence of the poor world’s abstract storm.”
> ​		—Robert Penn Warren



A linear transform is one that preserves vector addition and scalar multiplication.
$$
f(x) + f(y) = f(x+y)
$$

$$
kf(x) = f(kx)
$$
Scaling and rotation transforms, in fact all linear transforms for three-element vectors, can be represented using a 3 × 3 matrix.

Adding a ﬁxed vector to another vector performs a **translation**

Combining **linear transforms** and **translations** can be done using an **aﬃne transform**（仿射变换）, typically stored as a 4 × 4 matrix. An aﬃne transform is one that performs a linear transform and then a translation. 

A direction vector is represented as  $ v = (v_x\quad v_y\quad v_z \quad 0)^T $ and a point as  $ v = (v_x\quad v_y\quad v_z \quad 1)^T $

All translation, rotation, scaling, reﬂection, and shearing matrices are aﬃne. The main characteristic of an aﬃne matrix is that it **preserves** the **parallelism of lines**, but not necessarily lengths and angles. 



## Basic Transforms

![](https://github.com/Uyouii/LearnOpenGL/raw/master/Real%20Time%20Rending%20Image/Summary%20of%20most%20of%20the%20transforms.PNG)

>  Summary of most of the transform.



### Translation

A change from one location to another is represented by a translation matrix, **T**. This matrix translates an entity by a vector  $ t = (t_x , t_y , t_z ) $

$$
T(t) = T(t_x , t_y , t_z )=
\begin{pmatrix}
 1 & 0 & 0 & t_x\\ 
 0 & 1 & 0 & t_y\\ 
 0 & 0 & 1 & t_z\\ 
 0 & 0 & 0 & 1\\ 
\end{pmatrix}
$$
the multiplication of a point $ p = (p_x , p_y , p_z , 1 ) $ with **T(t)** yields a new point $ p′ = (p_x +t_x , p_y +t_y , p_z +t_z , 1) $ Notice that a vector $ v = (v_x , v_y , v_z , 0 ) $ is left unaﬀected by a multiplication by T, because a direction vector cannot be translated.

The **inverse** of a translation matrix is $ T^{-1}(t) = T(-t) $ that is, the vector t is negated.

### Rotation

it is a **rigid-body transform**, it preserves the distances between points transformed, and preserves
handedness.

In two dimensions, the rotation matrix is simple to derive. Assume that we have a vector,  $ v = (v_x, v_y)=(rcos\theta, rsin\theta) $ if we rotate that vector by φ radians, then we get  $ u = (rcos(\theta + \phi),rsin(\theta + \phi)) $

This can be rewritten as
$$
u = 
\begin{pmatrix}
 rcos(\theta + \phi)\\ 
 rsin(\theta + \phi)\\  
\end{pmatrix} = 
\begin{pmatrix}
 r(cos\theta cos\phi - sin\theta sin\phi)\\ 
 r(sin\theta cos\phi + cos\theta sin\phi)\\  
\end{pmatrix} = 
\begin{pmatrix}
 cos\phi & -sin\phi\\ 
 sin\phi & cos\phi \\  
\end{pmatrix}
\begin{pmatrix}
 rcos\theta\\ 
 rsin\theta\\  
\end{pmatrix} = R(\phi)v
$$
In three dimensions, commonly used rotation matrices are Rx (φ), Ry (φ), and Rz (φ), which rotate an entity φ radians around the x-, y-, and z-axes, respectively.
$$
R_x(\phi) =
\begin{pmatrix}
 1 & 0 & 0 & 0 \\
 0 & cos\phi & -sin\phi & 0 \\
 0 & sin\phi & cos\phi & 0 \\
 0 & 0 & 0 & 1 \\
\end{pmatrix}
$$

$$
R_y(\phi) =
\begin{pmatrix}
 cos\phi & 0 & sin\phi & 0 \\
 0 & 1 & 0 & 0 \\
 -sin\phi & 0 & cos\phi & 0 \\
 0 & 0 & 0 & 1 \\
\end{pmatrix}
$$

$$
R_z(\phi) =
\begin{pmatrix}
 cos\phi & -sin\phi & 0 & 0 \\
 sin\phi & cos\phi & 0 & 0 \\
 0 & 0 & 1 & 0 \\
 0 & 0 & 0 & 1 \\
\end{pmatrix}
$$


There is another way to obtain the **inverse**: $ R_i^{-1}(\phi)=R_i(-\phi) $ rotate in the opposite direction around the same axis.

### Scaling

a scaling matrix , $ S(s) = S(s_x, s_y, s_z) $.  scales an entity with factors sx, sy and sz along the x-, y-, and z-directions.

$$
S(s) =
\begin{pmatrix}
s_x & 0 & 0 & 0 \\
0 & s_y & 0 & 0 \\
0 & 0 & s_z & 0 \\
0 & 0 & 0 & 1 \\
\end{pmatrix}
$$
The scaling operation is called **uniform** if s x = s y = s z and **nonuniform** otherwise.

The **inverse** is  $ S^{-1}(s) = S(1/s_x, 1/s_y, 1/s_z) $

A negative value on one or three of the components of s gives a type of **reﬂection matrix**, also called a **mirror matrix**. It should be noted that a rotation matrix concatenated with a reﬂection matrix is also a reﬂection matrix.

To detect whether a given matrix reﬂects in some manner, compute the determinant of the upper left 3 × 3 elements of the matrix. If the value is negative, the matrix is reﬂective. 

### Shearing

There are six basic shearing matrices, and they are denoted $ H_{xy}(s),H_{xz}(s),H_{yx}(s),H_{yz}(s),H_{zx}(s),H_{zy}(s), $

![](D:\projects\Learn OpenGL\Real Time Rending Image\The eﬀect of shearing the unit square with H xz (s).PNG)

> The eﬀect of shearing the unit square with H xz (s). Both the y- and z-values are unaﬀected by the transform, while the x-value is the sum of the old x-value and s multiplied by the z-value, causing the square to become slanted. This transform is area-preserving, which can be seen in that the dashed areas are the same.
$$
H_{xz}(s) =
\begin{pmatrix}
1 & 0 & s & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 1 & 0 \\
0 & 0 & 0 & 1 \\
\end{pmatrix}
$$
The eﬀect of multiplying this matrix with a point **p** yields a point: $ (p_x + sp_z \quad p_y \quad p_z) ^ T $

The inverse of Hij(s) is generated by shearing in the opposite direction: $ H_{ij}^{-1}(s) = H_{ij}(-s)$

### Concatenation of Transforms

Due to the **noncommutativity** of the multiplication operation on matrices, the order in which the matrices occur matters. Concatenation of transforms is therefore said to be **order-dependent**.

This composite matrix is **C = TRS**. Note the order here. The scaling matrix, **S**, should be applied to the vertices ﬁrst, and therefore appears to the right in the composition. 

### The Rigid-Body Transform

 Such a transform, consisting of concatenations of only translations and rotations, is called a **rigid-body transform**. It has the characteristic of preserving lengths, angles, and handedness.

Any rigid-body matrix, X, can be written as the concatenation of a translation matrix, T(t), and a rotation matrix, R. 
$$
X = T(t)R =
\begin{pmatrix}
r_{00} & r_{01} & r_{02} & t_x \\
r_{10} & r_{11} & r_{12} & t_y \\
r_{20} & r_{21} & r_{22} & t_z \\
0 & 0 & 0 & 1 \\
\end{pmatrix}
$$
The **inverse** of X is computed as:
$$
X^{-1} = (T(t)R)^{-1} = R^{-1}T(t)^{-1} = R^TT(-t)
$$
Another way to compute the inverse of **X** is to consider **R** (making R appear as 3 × 3 matrix) and **X** in the following notation
$$
\overline R = (r_{,0}\quad r_{,1}\quad r_{,2}) =
\begin{pmatrix}
r_0^T,\\
r_1^T,\\
r_2^T,\\
\end{pmatrix}, 
X = 
\begin{pmatrix}
\overline R & t\\
0^T & 1\\
\end{pmatrix},
$$
Some calculations yield the inverse in the expression shown:
$$
X^{-1} =
\begin{pmatrix}
r_0,& r_1, &r_2, &-{\overline R}^Tt\\
0 & 0 & 0 & 1
\end{pmatrix},
$$
### Normal Transform

Instead of multiplying by the matrix itself, the proper method is to use the **transpose of the matrix’s adjoint(伴随矩阵）**.





## Special Matrix Transforms and Operations

### The Euler Transform

The Euler transform is the multiplication of three matrices, More formally, the transform, denoted E: 
$$
E(h,p,r)=R_z(r)R_x(p)R_y(h)
$$

Since E is a concatenation of rotations, it is also clearly orthogonal(正交的). Therefore its inverse can be expressed as $E^{-1} = E^T = (R_zR_xR_y)^T = R_y^TR_x^TR_z^T$.

The Euler angles h, p, and r represent in which order and how much the **head**, **pitch**, and **roll** should rotate around their respective axes.  Also, “**head**” is sometimes known as “**yaw**”. 

![](D:\projects\Learn OpenGL\Real Time Rending Image\The Euler transform.PNG)

#### Limitations

It is difficult to work with two sets of Euler angles in combination.For example, interpolation between one set and another is not a simple matter of interpolating each angle. In fact, two diﬀerent sets of Euler angles can give the same orientation, so any interpolation should not rotate the object at all. 



When you use Euler transforms, something called **gimbal lock** may occur. This happens when rotations are made so that one degree of freedom is lost.