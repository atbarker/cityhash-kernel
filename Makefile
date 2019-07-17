All:
	gcc -g -O2 -c city.c
	gcc -g -O2 -c main.c
	gcc -g -O2 -o main main.o city.o
clean:
	rm *.o main

