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

