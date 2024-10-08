# Project03 makefile

all: project03 run

project03: stack.o main.o
	clang++ stack.o main.o -o project03

stack.o: stack.h stack.cpp
	clang++ -c stack.cpp

main.o: stack.h main.cpp
	clang++ -c main.cpp

run: project03
	./project03 p03input1.txt

clean:
	rm *.o project03
