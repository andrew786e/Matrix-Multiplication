main: matrixMultiplication.o lab1_IO.o matrixgen.o
	g++ -g lab1_IO.o matrixMultiplication.o -o main -lpthread

lab1_IO.o: lab1_IO.c
	g++ -g -c lab1_IO.c -o lab1_IO.o

matrixgen.o: matrixgen.c
	g++ -g matrixgen.c -o matrixgen

matrixMultiplication.o: matrixMultiplication.cpp
	g++ -g -c matrixMultiplication.cpp -o matrixMultiplication.o -lpthread

clean:
	rm -f *.o main matrixgen