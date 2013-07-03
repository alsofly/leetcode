CC=clang++
INC=-I..
FLAGS=-std=c++11 -stdlib=libc++ -Weverything

all: main.m.o
	$(CC) $(FLAGS) main.m.o -o a.out

main.m.o: main2.m.cpp
	$(CC) $(FLAGS) $(INC) -c main2.m.cpp -o main.m.o

clean:
	rm -rf *.o a.out
