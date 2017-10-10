C/C++ VISA Example for Linux
============================

A C/C++ VISA instrument connection example for Red Hat Enterprise Linux (RHEL) 6.6 using NI VISA 15.0 for Linux.

The example should work on other versions of linux with some small modification of the `Makefile`. Specifically, the `lib` and `include` paths.

NI-VISA 15.0 for Linux
----------------------

NI-VISA 15.0 can be downloaded from:

[http://www.ni.com/download/ni-visa-15.0/5410/en/](http://www.ni.com/download/ni-visa-15.0/5410/en/)

This version of NI-VISA supports both 32- and 64-bit applications. This project assumes 64 bit, but there are hints on how to compile for 32-bit in the `setup-step-1` and `makefile`.

Setup
-----

To compile this project, follow the steps in the shell scripts `setup-step-1` and `setup-step-2`. The setup steps are split because NI-VISA must be installed in the middle. You can follow these steps either by manually executing them in a terminal, or by cloning the repo first and running the scripts directly.

Make, run
---------

Before compiling, edit `main.c` to include the correct instrument address and VISA resource string.

Then, to compile and run this project:

```shell
cd /path/to/c-visa-example/
make
./example
```
