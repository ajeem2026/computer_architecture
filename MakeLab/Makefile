F2C: main.o convert.o
	gcc -o F2C main.o convert.o
	./F2C
main.o: main.c convert.h
	gcc -c main.c
convert.o: convert.c convert.h
	gcc -c convert.c
clean:
	rm -f *.o F2C
