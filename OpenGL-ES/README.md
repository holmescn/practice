OpenGL ES 2.0 Learn & Practice
==============================

Introduction
------------

The practice is based on the book __OpenGL ES 2.0 Programming Guide__. I want
to do something on mobile and do it cross-platform. Originally, I used cocos2d-x.
But it is for game。I could use Qt-Quick, but I think it is too big (10M of
the QT-Core.so). And I also want to make something cool. So I decided to learn
OpenGL, and build my own library and framework.

After tried AMD OpenGL ES SDK which is only worked on AMD GPUs, PowerVR SDK
which could not work under Win8.1 and Angle Project which is part of chromium,
the only one could satisfied my develop environment is Angle Project. I code
the practice by VS2013 (perhaps soon 2014, or use CMake). Code will based on
C++11 which is my favourite programming language, so VS less than 2013 could
not run the code.


Leason-1
--------

This is a startup program from PowerVR SDK. Pretty well and simple. I copied it
just for testing my develop environment, and learn how to create native window.
Next leason is my beginning.

Leason-2
--------

### Start

I will split the native window create func into another file, and isolate it.
Then a GLES namespace will be created. GLProgram class which represent a OpenGL
program will be created. It is the startup. No individual shader class will be
created. Most OpenGL type will be recreated for call the OpenGL API by overload
function, such as vec\*, mat\*.

After leason-2, the main.cpp will just handle draw function, other things will
move out.

