# Introduction

## Graphics Areas

 major areas of computer graphics:

- **Modeling** deals with the mathematical speciﬁcation of shape and appearance properties in a way that can be stored on the computer.
- **Rendering** is a term inherited from art and deals with the creation of shaded images from 3D computer models.
- **Animation** is a technique to create an illusion of motion through sequences of images.  Animation uses modeling and rendering but adds the key issue of movement over time, which is not usually dealt with in basic modeling and rendering.

 related areas include the following:

- **User interaction** deals with the interface between input devices such as mice and tablets, the application, feedback to the user in imagery, and other sensory feedback. 

- **Virtual reality** attempts to immerse the user into a 3D virtual world.
- **Visualization**  attempts to give users insight into complex information via visual display. Often there are graphic issues to be addressed in a visualization problem.
- **Image processing** deals with the manipulation of 2D images and is used in both the ﬁelds of graphics and vision.
- **3D scanning** uses range-ﬁnding technology to create measured 3D models.
- **Computational photography**  is the use of computer graphics, computer vision, and image processing methods to enable new ways of photographically capturing objects, scenes, and environments.



## Graphics Pipeline

Every desktop computer today has a powerful 3D **graphics pipeline**. This is a special software/hardware subsystem that efﬁciently draws 3D primitives in perspective. Usually these systems are optimized for processing 3D triangles with shared vertices.

The basic operations in the pipeline map the 3D vertex locations to 2D screen positions and shade the triangles so that they both look realistic and appear in proper back-to-front order.

Although drawing the triangles in valid back-to-front order was once the most important research issue in computer graphics, it is now almost always solved using the **z-buffer**, which uses a special memory buffer to solve the problem in a brute-force manner.

