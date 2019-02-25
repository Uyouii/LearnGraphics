[TOC]

# Miscellaneous Math

## Solving Quadratic Equations

A quadratic equation has the form
$$
Ax^2 + Bx + C = 0
$$

To solve the quadratic equation analytically, we ﬁrst divide by A:
$$
x^2 + \frac{B}{A}x + \frac{C}{A} = 0
$$
Then we “complete the square” to group terms:
$$
{(x + \frac{B}{2A})}^2 - \frac{B^2}{4A^2} + \frac{C}{A} = 0
$$
Moving the constant portion to the right-hand side and taking the square root gives
$$
x + \frac{B}{2A} = \pm \sqrt{\frac{B^2}{4A^2} - \frac{C}{A}}
$$
Subtracting B/(2A) from both sides and grouping terms with the denominator
2A gives the familiar form: 
$$
x = \frac{-B \pm \sqrt{B^2 - 4AC}}{2A} \\
D \equiv B^2 - 4AC
$$
which is called the discriminant of the quadratic equation. If D > 0, there are two real solutions (also called roots). If D = 0, there is one real solution (a “double” root). If D < 0, there are no real solutions.

## Trigonometry

### Angles

An **angle** is deﬁned by the length of the arc segment it cuts out on the unit circle.A common convention is that the smaller arc length is used, and the sign of the angle is determined by the order in which the two half-lines are speciﬁed. 

Each of these angles is *the length of the arc of the unit circle that is “cut” by the two directions*. 

 The conversion between degrees and radians is
$$
degrees = \frac{180}{\pi}radians \\
radians = \frac{\pi}{180}degrees \\
$$

### Useful Identities

**Shifting identities**
$$
sin( − A) = − sin A \\
cos( − A) = cos A	\\
tan( − A) = − tan A	\\
sin(π/2 − A) = cos A \\
cos(π/2 − A) = sin A \\
tan(π/2 − A) = cot A 
$$
**Pythagorean identities**
$$
{sin}^2A + {cos}^2A = 1 \\
{sec}^2A - {tan}^2A = 1 \\
{csc}^2A - {cot}^2A = 1 \\
$$
**Addition and subtraction identities**
$$
sin(A + B) = sin A cos B + sin B cos A	\\
sin(A − B) = sin A cos B − sin B cos A	\\
sin(2A) = 2 sin A cos A	\\
cos(A + B) = cos A cos B − sin A sin B	\\
cos(A − B) = cos A cos B + sin A sin B	\\
cos(2A) = {cos}^2A - {sin}^2A	\\
tan(A + B) = \frac{tanA + tanB}{1 - tanAtanB} \\
tan(A - B) = \frac{tanA - tanB}{1 + tanAtanB} \\
tan(2A) = \frac{2tanA}{1 - {tan}^2A}
$$
**Half-angle identities**
$$
{sin}^2(A/2) = (1 - cosA) /2 \\
{cos}^2(A/2) = (1 + cosA) / 2\\
$$
**Product identities**
$$
sin A sin B = − (cos(A + B) − cos(A − B))/2 \\
sin A cos B = (sin(A + B) + sin(A − B))/2 \\
cos A cos B = (cos(A + B) + cos(A − B))/2 \\
$$
![](https://github.com/Uyouii/LearnGraphics/raw/master/Real%20Time%20Rending%20Image/Geometry%20for%20triangle%20laws.PNG)

> Geometry for triangle laws

The following identities are for arbitrary triangles with side lengths a, b, and c, each with an angle opposite it given by A, B, C, respectively 
$$
\frac{sinA}{a} = \frac{sinB}{b} = \frac{sinC}{c}
$$

$$
c^2 = a^2 + b^2 - 2ab cosC
$$

$$
\frac{a + b}{a - b} = \frac{tan(\frac{A + B}{2})}{tan(\frac{A - B}{2})}
$$

The area of a triangle can also be computed in terms of these side lengths:

triangle area = $\frac{1}{4} \sqrt{(a + b + c)(-a + b + c)(a - b + c)(a + b - c)}$

## Vectors

A **vector** describes a length and a direction.

Two vectors are equal if they have the same length and direction even if we think of them as being located in different places

 Vectors will be represented as bold characters, e.g., $\mathbf{a}$. 

A vector’s length is denoted$\left \| a \right \| $. 

A **unit vector** is any vector whose length is one. 

The **zero vector** is the vector of zero length. The direction of the zero vector is undeﬁned.



Vectors can be used to store an **offset**, also called a **displacement**. Vectors can also be used to
store a **location**, another word for **position** or **point**. 

### Vector Operations

Two vectors are equal if and only if they have the same length and direction.  Two vectors are added according to the **parallelogram rule**(平行四边形定则). 

vector addition is commutative: $\mathbf{a} + \mathbf{b} = \mathbf{b} + \mathbf{a}$

subtraction: $\mathbf{b} - \mathbf{a} =- \mathbf{a} + \mathbf{b}$

also: $\mathbf{a} + (\mathbf{b} - \mathbf{a}) = \mathbf{b}$

### Cartesian Coordinates of a Vector

a vector $\mathbf{a}$ might be represented as:
$$
\mathbf{a} = x_a\mathbf{x} + y_a\mathbf{y}
$$
where $x_a$ and $ y_a$ are the real Cartesian coordinates of the 2D vector **a**  

by the Pythagorean theorem, the length of a is:
$$
\left \| \mathbf{a} \right \| = \sqrt{{x_a}^2 + {y_a}^2}
$$
By convention we write the coordinates of **a** either as an ordered pair $(x_a , y_a )$ or a column matrix:
$$
\mathbf{a} = 
\begin{bmatrix}
x_a \\
y_a	\\
\end{bmatrix}
$$
We will also occasion- ally write the vector as a row matrix, which we will indicate as $ \mathbf{a}^T$ :
$$
\mathbf{a}^T =
\begin{bmatrix}
x_a & y_a
\end{bmatrix}
$$

### Dot Product

The dot product of **a** and **b** is denoted **a · b** and is often called the *scalar* product because it returns a scalar. 
$$
\mathbf{a} . \mathbf{b} = \left \| \mathbf{a} \right \| \left \| \mathbf{b} \right \| cos\phi
$$
![](E:\projects\Uyouii git\LearnOpenGL\Real Time Rending Image\The dot product.PNG)

> The dot product is related to length and angle and is one of the most important formulas in graphics.

The most common use of the dot product in graphics programs is to compute the **cosine** of the angle between two vectors. 

The dot product can also be used to ﬁnd the **projection** of one vector onto another. This is the length **a → b** of a vector a that is projected at right angles onto a vector **b** 
$$
\mathbf{a}→\mathbf{b} = \left \| \mathbf{a} \right \|cos\phi = \frac{\mathbf{a}.\mathbf{b}}{ \left \| \mathbf{b} \right \|}
$$
![](E:\projects\Uyouii git\LearnOpenGL\Real Time Rending Image\The projection of a onto b is a length found by Equation.PNG)

>  The projection of a onto b is a length found by Equation

The dot product obeys the familiar associative and distributive properties（结合律和分配律) we have in real arithmetic:
$$
\mathbf{a}.\mathbf{b} = \mathbf{b}.\mathbf{a} \\
\mathbf{a} . (\mathbf{b} + \mathbf{c}) = \mathbf{a}.\mathbf{b} + \mathbf{a}.\mathbf{c} \\
(k\mathbf{a}).\mathbf{b} = \mathbf{a}.(k\mathbf{b}) = k\mathbf{a}.\mathbf{b} \\
$$
If 2D vectors **a** and **b** are expressed in Cartesian coordinates, we can take ad- vantage of **x · x** = **y · y** = 1 and **x · y** = 0 to derive that their dot product is
$$
\mathbf{a}.\mathbf{b} = (x_a\mathbf{x} + y_a\mathbf{y}) . (x_b\mathbf{x} + y_b\mathbf{y}) \\
= x_ax_b(\mathbf{x}.\mathbf{x}) + x_ay_b(\mathbf{x}.\mathbf{y}) + x_by_a(\mathbf{y}.\mathbf{x}) + y_ay_b(\mathbf{y}.\mathbf{y}) \\
= x_ax_b + y_ay_b
$$
in 3D we can find:
$$
\mathbf{a}.\mathbf{b} = x_ax_b + y_ay_b + z_az_b
$$

### Cross Product

The cross product **a** × **b** is usually used only for three-dimensional vectors; 

The cross product returns a 3D vector that is perpendicular(垂直的) to the two arguments of the cross product.  The length of the resulting vector is related to $sin \phi$:
$$
\left \| \mathbf{a \times b} \right \| = \left \| \mathbf{a} \right \| \left \| \mathbf{b} \right \| sin\phi
$$
The magnitude$  \left \| \mathbf{a \times b} \right \|$ is equal to the area of the parallelogram(平行四边形) formed by vectors **a** and **b**. In addition, **a × b** is perpendicular(垂直的) to both **a** and **b**.

it is standard to assume that
$$
\mathbf{z} = \mathbf{x} \times \mathbf{y}
$$
The cross product has the nice property that:
$$
\mathbf{a}\times\mathbf{b} =-( \mathbf{b}\times\mathbf{a} )\\
\mathbf{a} \times (\mathbf{b} + \mathbf{c}) = \mathbf{a}\times\mathbf{b} + \mathbf{a}\times\mathbf{c} \\
\mathbf{a}\times(k\mathbf{b}) = k(\mathbf{a}\times\mathbf{b}) \\
$$
In Cartesian coordinates, we can use an explicit expansion to compute the cross product:
$$
\mathbf{a} \times \mathbf{b} = \\
(x_a\mathbf{x} + y_a\mathbf{y} + z_a\mathbf{z}) \times (x_b\mathbf{x} + y_b\mathbf{y} + z_b\mathbf{z}) = \\
x_ax_b\mathbf{x} \times \mathbf{x} + 
x_ay_b\mathbf{x} \times \mathbf{y} +
x_az_b\mathbf{x} \times \mathbf{z} + \\
y_ax_b\mathbf{y} \times \mathbf{x} + 
y_ay_b\mathbf{y} \times \mathbf{y} + 
y_az_b\mathbf{y} \times \mathbf{z} + \\
z_ax_b\mathbf{z} \times \mathbf{x} + 
z_ay_b\mathbf{z} \times \mathbf{y} +
z_az_b\mathbf{z} \times \mathbf{z} = \\
(y_az_b - z_ay_b)\mathbf{x} + (z_ax_b - x_az_b)\mathbf{y} + (x_ay_b - y_ax_b)\mathbf{z}
$$
so in coordinate form,
$$
\mathbf{a} \times \mathbf{b} = (y_az_b - z_ay_b, z_ax_b - x_az_b, x_ay_b - y_ax_b)
$$


## Curves and Surfaces

### 2D Implicit Curves

Intuitively, a **curve**(曲线) is a set of points that can be drawn on a piece of paper without lifting the pen. A common way to describe a curve is using an implicit equation. An **implicit equation** in two dimensions has the form
$$
f(x,y) = 0So you evaluate f to decide whether a point is “inside” a curve.
$$
So you evaluate f to decide whether a point is “inside” a curve. 

### The 2D Gradient

The gradient（梯度） vector ∇ f(x, y) is given by：
$$
∇f(x,y) = (\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y})
$$
The gradient vector evaluated at a point on the implicit curve f(x, y) = 0 is perpendicular(垂直) to the **tangent** (切线) vector of the curve at that point. This perpendicular vector is usually called the **normal** vector to the curve.



#### Implicit 2D Lines

a more general form is often useful:

$$
Ax + By + C = 0, 
$$
for real numbers A, B, C.

the distance from a point to the line is the length of the vector $k(A, B)$, which is
$$
distance = k \sqrt{A^2 + B^2} .
$$
For the point $(x, y) + k(A, B)$, the value of $f(x, y) = Ax + By + C$ is
$$
f(x + kA, y + kB) = Ax + kA^2+ By + kB^2 + C= k(A^2+ B^2).
$$

$$
distance = \frac{f(a,b)}{\sqrt{A^2 + B^2}}
$$

