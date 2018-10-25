all: fileio.o
	gcc -o go fileio.o

fileio.o: fileio.c
	gcc -c fileio.c

run:
	./go

clear:
	rm go
	rm *.o
	rm test.txt
