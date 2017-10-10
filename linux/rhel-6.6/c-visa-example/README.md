C/C++ VISA Example for Red Hat Enterprise Linux 6
=================================================

A C/C++ VISA instrument connection example for Red Hat Enterprise Linux (RHEL) 6.6 using NI VISA 15.0 for Linux.

Setup
-----

Setup requires an internet connection.

Because NI-VISA requires a restart, setup is split into two parts.

### Setup step 1

Bash script `setup-step-1` installs the development dependencies, downloads and installs NI-VISA 15.0 and updates the NI-VISA drivers.

Then it restarts

### Setup step 2

This step clones the git repo for this project and opens `main.c` in a text editor.

Make
----

Before compiling, edit `main.c` to include the correct instrument address and VISA resource string.

```c++
// Connection info
ViChar resource_string[] = "TCPIP::<instrument_address>::INSTR";
```

Then compile this project via make:

```shell
cd /path/to/c-visa-example/
make
```

Make should produce an executable, `example`, that should connect to the instrument and read the id string.

NI-VISA 15.0 for Linux
----------------------

`setup-step-1` automatically downloads NI-VISA 15.0 from:

[http://www.ni.com/download/ni-visa-15.0/5410/en/](http://www.ni.com/download/ni-visa-15.0/5410/en/)

This version of NI-VISA supports both 32- and 64-bit applications. This project assumes 64 bit, but there are hints on how to compile for 32-bit in the `setup-step-1` and `makefile`.
