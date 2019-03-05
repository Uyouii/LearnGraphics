# Ray Tracing

Fundamentally, ***rendering*** is a process that takes as its input a set of objects and produces as its output an array of pixels.

 rendering involves considering how each object contributes to each pixel; it can be organized in two
general ways:

- In ***object-order rendering***, each object is considered in turn, and for each object all the pixels that it inﬂuences are found and updated. 
-  In ***image-order rendering***, each pixel is considered in turn, and for each pixel all the objects that inﬂuence it are found and the pixel value is computed.

Image-order and object-order rendering approaches can compute exactly the same images, but they lend themselves to computing different kinds of effects and have quite different performance characteristics.

broadly speaking, image-order rendering is simpler to get working and more ﬂexible in the effects that can be produced, and usually (though not always) takes much more execution time to produce a comparable image.

## The Basic Ray-Tracing Algorithm

