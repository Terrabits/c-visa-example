# Note:
#   NI VISA for linux only supports 32-bit applications.
#   Make sure gcc 32 bit dev tools are installed.
#   On Scientific Linux/RHEL 6 x64:
#     sudo yum install glibc-devel.i686 libgcc.i686 libstdc++-devel.i686 ncurses-devel.i686

# Compile for 32-bit
GCC=-m32

# Dependency locations
LIBS=/usr/local/lib/libvisa.so
INCLUDES=-I/usr/local/include

all: example

example: main.o
	gcc main.o $(LIBS) $(GCC) -o example

main.o: main.c
	gcc -c -w main.c $(INCLUDES) $(GCC)

clean:
	rm *.o example
