C/C++ VISA Example for Linux
============================

A C/C++ VISA instrument connection example for Scientific Linux / Red Hat Enterprise Linux (RHEL) 6 using NI VISA 5.

The example should work on other versions of linux with some small modification of the `Makefile`. Specifically, the `lib` and `include` paths.

NI VISA for linux is 32-bit
---------------------------

NI VISA for linux only supports 32-bit applications. Make sure gcc 32 bit dev tools are installed. On Scientific Linux/RHEL 6 x64, this can be done with the command:

`sudo yum install glibc-devel.i686 libgcc.i686 libstdc++-devel.i686 ncurses-devel.i686`

