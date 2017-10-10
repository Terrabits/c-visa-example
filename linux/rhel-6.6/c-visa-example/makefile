
# Compile for 32-bit:
# GCC=-m32

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
