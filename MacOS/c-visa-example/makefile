# Dependency locations for R&S VISA on MacOS
LIBS=/Library/Frameworks/RsVisa.framework/Versions/A/RsVisa/librsvisa.dylib
INCLUDES=-I/Library/Frameworks/RsVisa.framework/Versions/A/Headers

all: example

example: main.o
	gcc main.o $(LIBS) -o example

main.o: main.c
	gcc -c -w main.c $(INCLUDES)

clean:
	rm *.o example
