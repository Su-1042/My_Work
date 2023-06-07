all: 1/main.o 1/hash.o 2/main.o 2/hash.o 3/main.o 3/heap.o 4/main.o 4/heap.o
	gcc -o 1/q1.o 1/main.o 1/hash.o
	gcc -o 2/q2.o 2/main.o 2/hash.o
	gcc -o 3/q3.o 3/main.o 3/heap.o
	gcc -o 4/q4.o 4/main.o 4/heap.o		

q1: 1/main.o 1/hash.o
	gcc -o 1/q1.o 1/main.o 1/hash.o

q2: 2/main.o 2/hash.o
	gcc -o 2/q2.o 2/main.o 2/hash.o	

q3: 3/main.o 3/heap.o
	gcc -o 3/q3.o 3/main.o 3/heap.o
	
q4: 4/main.o 4/heap.o
	gcc -o 4/q4.o 4/main.o 4/heap.o

clean: 
	rm -rf 1/*.o 2/*.o 3/*.o 4/*.o

