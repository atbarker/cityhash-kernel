dependencies:
	gcc -g -O2 -c city.c

main: dependencies
	gcc -g -O2 -c main.c
	gcc -g -O2 -o main main.o city.o

test: dependencies
	gcc -g -O2 -c city-test.c
	gcc -g -O2 -o city-test city-test.o city.o
	./city-test
clean:
	rm *.o
	rm main
	rm city-test

