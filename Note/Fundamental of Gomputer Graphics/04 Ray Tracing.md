# Ray Tracing

Fundamentally, ***rendering*** is a process that takes as its input a set of objects and produces as its output an array of pixels.

 rendering involves considering how each object contributes to each pixel; it can be organized in two
general ways:

- In ***object-order rendering***, each object is considered in turn, and for each object all the pixels that it inﬂuences are found and updated. 
-  In ***image-order rendering***, each pixel is considered in turn, and for each pixel all the objects that inﬂuence it are found and the pixel value is computed.

Image-order and object-order rendering approaches can compute exactly the same images, but they lend themselves to computing different kinds of effects and have quite different performance characteristics.

broadly speaking, image-order rendering is simpler to get working and more ﬂexible in the effects that can be produced, and usually (though not always) takes much more execution time to produce a comparable image.

## The Basic Ray-Tracing Algorithm

A ray tracer works by computing one pixel at a time, and for each pixel the basic task is to ﬁnd the object that is seen at that pixel’s position in the image.

Each pixel “looks” in a different direction, and any object that is seen by a pixel must intersect the ***viewing ray***, a line that emanates from the viewpoint in the direction that pixel is looking. 

The particular object we want is the one that intersects the viewing ray nearest the camera, since it blocks the view of any other objects behind it. 

Once that object is found, a ***shading*** computation uses the intersection point, surface normal, and other information (depending on the desired type of rendering) to determine the color of the pixel.

A basic ray tracer therefore has three parts:

1. ***ray generation***, which computes the origin and direction of each pixel’s viewing ray based on the camera geometry;
2.  ***ray intersection***, which ﬁnds the closest object intersecting the viewing ray;
3. ***shading***, which computes the pixel color based on the results of ray intersection.

The structure of the basic ray tracing program is:

```
for each pixel do
	compute viewing ray
	ﬁnd ﬁrst object hit by ray and its surface normal n
	set pixel color to value computed from hit point, light, and n
```

## Perspective

**Parallel Projection**

The simplest type of projection is ***parallel projection***, in which 3D points are mapped to 2D by moving them along a projection direction until they hit the image plane.  

The view that is produced is determined by the choice of projection direction and image plane.  If the image plane is perpendicular to the view direction, the projection is called ***orthographic***; otherwise it is called ***oblique***.

Parallel projections are often used for mechanical and architectural drawings because they keep parallel lines parallel and they preserve the size and shape of planar objects that are parallel to the image plane.

**Perspective Projection**

***perspective projection***: we simply project(投影) along lines that pass through a single point, the ***viewpoint***, rather than along parallel lines.

A perspective view is determined by the choice of viewpoint (rather than projection direction) and image plane. 

As with parallel views, there are oblique and non-oblique perspective views; the distinction is made based on the projection direction at the center of the image.

A surprising fact about perspective is that all the rules of perspective drawing will be followed automatically if we follow the simple mathematical rule underlying perspective: objects are projected directly toward the eye, and they are drawn where they meet a view plane in front of the eye.

## Computing Viewing Rays

A ray is really just an origin point and a propagation direction; a 3D parametric line is ideal for this. 

![](E:\projects\Uyouii git\LearnOpenGL\Real Time Rending Image\The ray from the eye to a point on the image plane..PNG)

the 3D parametric line from the eye e to a point s on the image plane (Figure 4.6) is given by 
$$
\mathbf{p}(t) = \mathbf{e} + t(\mathbf{s} - \mathbf{e})
$$
The point **e** is the ray’s origin, and **s** − **e** is the ray’s direction.

Note that **p**(0) = **e**, and **p**(1) = **s**, and more generally, if 0 < $t_1 $< $t_2 $, then $\mathbf{p}(t_1 )$ is closer to the eye than $\mathbf{p}(t_2)$. Also, if t < 0, then **p**(t) is “behind” the eye.

> These facts will be useful when we search for the closest object hit by the ray that is not behind the eye.

