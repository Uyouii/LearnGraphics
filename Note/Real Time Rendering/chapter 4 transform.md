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

.A direction vector is represented as 
$$
v = (v_x\quad v_y\quad v_z \quad 0)^T
$$
and a point as 
$$
v = (v_x\quad v_y\quad v_z \quad 1)^T
$$
All translation, rotation, scaling, reﬂection, and shearing matrices are aﬃne. The main characteristic of an aﬃne matrix is that it **preserves** the **parallelism of lines**, but not necessarily lengths and angles. 



## Basic Transforms

![](https://github.com/Uyouii/LearnOpenGL/raw/master/Real%20Time%20Rending%20Image/Summary%20of%20most%20of%20the%20transforms.PNG)

>  Summary of most of the transform.



### Translation

A change from one location to another is represented by a translation matrix, **T**. This matrix translates an entity by a vector 
$$
t = (t_x , t_y , t_z )
$$

$$
T(t) = T(t_x , t_y , t_z )=
\begin{pmatrix}
 1 & 0 & 0 & t_x\\ 
 0 & 1 & 0 & t_y\\ 
 0 & 0 & 1 & t_z\\ 
 0 & 0 & 0 & 1\\ 
\end{pmatrix}
$$

the multiplication of a point 

$$
p = (p_x , p_y , p_z , 1 )
$$

with **T(t)** yields a new point

$$
p′ = (p_x +t_x , p_y +t_y , p_z +t_z , 1)
$$

Notice that a vector

$$
v = (v_x , v_y , v_z , 0 )
$$

is left unaﬀected by a multiplication by T, because a direction vector cannot be translated.

The **inverse** of a translation matrix is
$$
T^{-1}(t) = T(-t)
$$


that is, the vector t is negated.

### Rotation

it is a **rigid-body transform**, it preserves the distances between points transformed, and preserves
handedness.

In two dimensions, the rotation matrix is simple to derive. Assume that we have a vector, 

$$
v = (v_x, v_y)=(rcos\theta, rsin\theta)
$$

if we rotate that vector by φ radians, then we get 

$$
u = (rcos(\theta + \phi),rsin(\theta + \phi))
$$

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



There is another way to obtain the **inverse**:
$$
R_i^{-1}(\phi)=R_i(-\phi)
$$
rotate in the opposite direction around the same axis.

### Scaling

a scaling matrix ,
$$
S(s) = S(s_x, s_y, s_z)
$$
scales an entity with factors sx, sy and sz along the x-, y-, and z-directions.
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

The **inverse** is 
$$
S^{-1}(s) = S(1/s_x, 1/s_y, 1/s_z)
$$
A negative value on one or three of the components of s gives a type of **reﬂection matrix**, also called a **mirror matrix**. It should be noted that a rotation matrix concatenated with a reﬂection matrix is also a reﬂection matrix.

To detect whether a given matrix reﬂects in some manner, compute the determinant of the upper left 3 × 3 elements of the matrix. If the value is negative, the matrix is reﬂective. 

### Shearing

There are six basic shearing matrices, and they are denoted
$$
H_{xy}(s),H_{xz}(s),H_{yx}(s),H_{yz}(s),H_{zx}(s),H_{zy}(s),
$$
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

The eﬀect of multiplying this matrix with a point **p** yields a point:
$$
(p_x + sp_z \quad p_y \quad p_z) ^ T
$$
The inverse of Hij(s) is generated by shearing in the opposite direction:
$$
H_{ij}^{-1}(s) = H_{ij}(-s)
$$
