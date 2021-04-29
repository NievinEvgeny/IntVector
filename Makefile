all: IntVector.c main.c IntVector.h
		gcc -Wall -o vector main.c IntVector.c
clean:
		rm vector
