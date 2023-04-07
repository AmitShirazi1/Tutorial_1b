all: basic-pointer-practice

basic-pointer-practice: basic-pointer-practice.o
	cc -g -o basic-pointer-practice basic-pointer-practice.o

basic-pointer-practice.o: basic-pointer-practice.c
	cc -c -Wall -g basic-pointer-practice.c

clean:
	rm basic-pointer-practice.o basic-pointer-practice