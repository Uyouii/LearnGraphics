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

![](https://github.com/Uyouii/LearnGraphics/raw/master/Real%20Time%20Rending%20Image/The%20ray%20from%20the%20eye%20to%20a%20point%20on%20the%20image%20plane..PNG)

the 3D parametric line from the eye e to a point s on the image plane (Figure 4.6) is given by 
$$
\mathbf{p}(t) = \mathbf{e} + t(\mathbf{s} - \mathbf{e})
$$
The point **e** is the ray’s origin, and **s** − **e** is the ray’s direction.

Note that **p**(0) = **e**, and **p**(1) = **s**, and more generally, if 0 < $t_1 $< $t_2 $, then $\mathbf{p}(t_1 )$ is closer to the eye than $\mathbf{p}(t_2)$. Also, if t < 0, then **p**(t) is “behind” the eye.

> These facts will be useful when we search for the closest object hit by the ray that is not behind the eye.

All of our ray-generation methods start from an orthonormal coordinate frame known as the ***camera frame***,  which we’ll denote by **e**, for the *eye point*, or *view- point*, and **u**, **v**, and **w** for the three basis vectors, organized with **u** pointing rightward (from the camera’s view), **v** pointing upward, and **w** pointing backward, so that { **u**, **v**, **w** } forms a right-handed coordinate system.

![](https://github.com/Uyouii/LearnGraphics/raw/master/Real%20Time%20Rending%20Image/The%20vectors%20of%20the%20camera%20frame%2C%20together%20with%20the%20view%20direction%20and%20up%20direction..PNG)

> Since **v** and **w** have to be perpendicular, the up vector and **v** are not generally the same. But setting the up vector to point straight upward in the scene will orient the camera in the way we would think of as “upright.”

### Orthographic Views

For an orthographic view, all the rays will have the direction$ −\mathbf{w}$. 

The viewing rays should start on the plane deﬁned by the point e and the vectors u and v; the only remaining information required is where on the plane the image is supposed to be. 

We’ll deﬁne the image dimensions with four numbers, for the four sides of the image: l and r are the positions of the left and right edges of the image, as measured from e along the **u** direction; and b and t are the positions of the bottom and top edges of the image, as measured from e along the **v** direction.

to fit an image with $n_x \times n_y$ pixels into a rectangle of size (r- l) x (t - b), the pixel at position (i, j) in the raster image has the position
$$
u = l + (r - l)( i + 0.5) / nx, \\
v = b + (t - b)(j + 0.5) / ny, \\
$$
In an orthographic view, we can simply use the pixel’s image-plane position as the ray’s starting point, and we already know the ray’s direction is the view direction. The procedure for generating orthographic viewing rays is then:

```
compute u and v
ray.direction <-- -W
ray.origin <-- E + u U + v V
```

It’s very simple to make an oblique parallel view: just allow the image plane normal **w** to be speciﬁed separately from the view direction **d**. The procedure is then exactly the same, but with **d** substituted for − **w**. Of course w is still used to construct **u** and **v**.

![](https://github.com/Uyouii/LearnGraphics/raw/master/Real%20Time%20Rending%20Image/Ray%20generation%20using%20the%20camera%20frame.JPG)

### Perspective Views

For a perspective view, all the rays have the same origin, at the viewpoint; it is the directions that are different for each pixel.

The image plane is no longer positioned at **e**, but rather some distance d in front of **e**; this distance is the image ***plane distance***, often loosely called the ***focal length***, because choosing *d* plays the same role as choosing focal length in a real camera.

The direction of each ray is deﬁned by the viewpoint and the position of the pixel on the image plane.

 resulting procedure：

```
compute u and v using (4.1)
ray.direction <-- d W + u U + v V
ray.origin <-- E
```

As with parallel projection, oblique perspective views can be achieved by specifying the image plane normal separately from the projection direction, then replacing − d**w** with d**d** in the expression for the ray direction.

## Ray-Object Intersection

### Ray-Sphere Intersection

Intersection points occur when points on the ray satisfy the implicit equation, so we solve the equation:
$$
f(\mathbf{p}(t)) = 0 \space \space or \space \space f(e + t\mathbf{d}) = 0
$$
A sphere with center c = (x c , y c , z c ) and radius R can be represented by the implicit equation
$$
(x - x_c)^2 + (y - y_c)^2 +(z - z_c)^2 - R^2 = 0
$$
We can write this same equation in vector form:
$$
(\mathbf{p} - \mathbf{c}) . (\mathbf{p} - \mathbf{c}) - R^2 = 0
$$
Any point p that satisﬁes this equation is on the sphere. If we plug points on the ray **p**(t) = **e** + t**d** into this equation, 
$$
(\mathbf{e} + t\mathbf{d}- \mathbf{c}) . (\mathbf{e} + t\mathbf{d} - \mathbf{c}) - R^2 = 0
$$
Rearranging terms yields:
$$
(\mathbf{d}.\mathbf{d})t^2 + 2\mathbf{d}.(\mathbf{e} - \mathbf{c})t + (\mathbf{e} - \mathbf{c})(\mathbf{e} - \mathbf{c}) - R^2 = 0
$$
 a classic quadratic equation in t, meaning it has the form
$$
AT^2 + Bt + C = 0
$$
The term under the square root sign in the quadratic solution, $B^2 − 4AC$, is called the ***discriminant*** and tells us how many real solutions there are.

- If the discriminant is negative, its square root is imaginary and the line and sphere do not intersect.
-  If the discriminant is positive, there are two solutions: one solution where the ray enter the sphere and one where it leaves.
- If the discriminant is zero, the ray grazes the sphere, touching it at exactly one point.

Plugging in the actual terms for the sphere and canceling a factor of two, we get:
$$
t = \frac{-\mathbf{d}.(\mathbf{e} - \mathbf{c})\pm \sqrt{(\mathbf{d}.(\mathbf{e} - \mathbf{c})^2) - (\mathbf{d}.\mathbf{d})((\mathbf{e} - \mathbf{c}).(\mathbf{e} - \mathbf{c}) - R^2)}}{(\mathbf{d}.\mathbf{d})}
$$
the normal vector at point p is given by the gradient n = 2(**p** − **c**). The unit normal is (**p** − **c**)/R.

### Ray-Triangle Intersection

We will present the form that uses **barycentric coordinates**（重心坐标系） for the parametric plane containing the triangle, because it requires no long-term storage other than the vertices of the triangle
$$
\left.\begin{matrix}
x_e + tx_d = f(u,v)\\ 
y_e + ty_d = g(u,v)\\ 
z_e + tz_d = h(u,v)\\
\end{matrix}\right\} or,
\mathbf{e} + t\mathbf{d} = \mathbf{f}(u,v)
$$

![](https://github.com/Uyouii/LearnGraphics/raw/master/Real%20Time%20Rending%20Image/The%20ray%20hits%20the%20plane%20containing%20the%20triangle%20at%20point%20p.JPG)

> the ray hits the plane containing the triangle at point p

the intersection will occur when:
$$
\mathbf{e} + t\mathbf{d} = \mathbf{a} + \beta(\mathbf{b} - \mathbf{a}) + \gamma(\mathbf{c} - \mathbf{a})
$$

from section 2.7.2, we know that the intersection is inside the triangle if and only if β > 0, γ > 0 and β + γ < 1.

expand the equation from its vector form into three equations for the three coordinates:
$$
x_e + tx_d = x_a + \beta(x_b - x_a) + \gamma(x_c - x_a) \\
y_e + ty_d = y_a + \beta(y_b - y_a) + \gamma(y_c - y_a) \\
z_e + tz_d = z_a + \beta(z_b - z_a) + \gamma(z_c - z_a) \\
$$
......

The algorithm for the ray-triangle intersection for which we need the linear solution can have some conditions for early termination. Thus, the function should look something like:

```c
boolean raytri (ray r, vector3 a, vector3 b, vector3 c,interval [t0 , t1 ])
compute t
if (t < t0 ) or (t > t1 ) then
	return false
compute γ
if (γ < 0) or (γ > 1) then
	return false
compute β
if (β < 0) or (β > 1 − γ) then
	return false
return true
```

### Ray-Polygon(多边形) Intersection

