default: prog

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c	

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o prog cirListDeque.o testCirListDeque.o
		
linkedList.o: linkedList.h linkedList.c 
	gcc -Wall -g -std=c99 -c linkedList.c

testLinkedList.o: linkedList.h testLinkedList.c
	gcc -Wall -g -std=c99 -c test testLinkedList.c

test: linkedList.o testLinkedList.o
	gcc -Wall -g -std=c99 -o test linkedList.o testLinkedList.o 

clean:
	rm cirListDeque.o
	rm testCirListDeque.o
	rm linkedList.o
	rm testLinkedList.o
