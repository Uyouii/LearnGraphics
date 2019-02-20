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
![](E:\projects\Uyouii git\LearnOpenGL\Real Time Rending Image\Geometry for triangle laws.PNG)

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



