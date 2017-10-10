
# # Compile for 32-bit:
# GCC=-m32
# LIBS=/usr/local/lib/libvisa.so
# INCLUDES=-I/usr/local/include

# 64-bit dependency locations
LIBS=/usr/local/lib64/libvisa.so
INCLUDES=-I/usr/local/include

all: example

example: main.o
	gcc main.o $(LIBS) $(GCC) -o example

main.o: main.c
	gcc -c -w main.c $(INCLUDES) $(GCC)

clean:
	rm *.o example
