CC=clang++
INC=-I..
FLAGS=-std=c++11 -stdlib=libc++ -Weverything

all: main.m.o
	$(CC) $(FLAGS) main.m.o -o a.out

main.m.o: main.m.cpp
	$(CC) $(FLAGS) $(INC) -c main.m.cpp

clean:
	rm -rf *.o a.out
