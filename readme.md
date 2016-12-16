C VISA Example
==============

This is a simple "Hello world!" project for instrument control using C and the VISA library. Using this project as a starting point, you should be able to:

- Connect to an instrument
- Write a SCPI command to an instrument
- Read a SCPI command response from an instrument
- Close the instrument connection

VISA
----

VISA must be installed on your system, and R&S VISA is specifically recommended. It is available for free for many platforms from here:

[R&S VISA](https://www.rohde-schwarz.com/us/applications/r-s-visa-application-note_56280-148812.html)

Visual Studio 2015
------------------

The Visual Studio 2015 `c-visa-example` project should compile and run as-is on a 64-bit system. This project contains a copy of the headers and libraries that you need to compile the project. These are:

- `visa\include\visa.h`
- `visa\include\visatype.h`
- `visa\lib\visa.lib`

This is for convenience for the purposes of this tutorial, but it is not a best practice. In general, it is better to use the `include` and `lib` locations from your VISA installation so that you automatically include a current and compatible version.

For a 64-bit system, you can (usually) find these files at:

`C:\Program Files\IVI Foundation\VISA\Win64\Include\`

and

`C:\Program Files\IVI Foundation\VISA\Win64\Lib_x64\msc\`

MacOS
-----

#### Note:

c-visa-example for MacOS is a work in progress. Specifically, the make file needs to be completed and the relevant libraries either included or pointed to.

This project uses `make` and `clang`, which are typically already included with a mac.

To build, navigate into the project directory and type:

~~~bash
# build
make

# run
./example
~~~
