CC=g++
CFLAGS = -c -Wall -Wextra -Wpedantic

all: StringSort

StringSort: main.o sort.o
	$(CC) main.o sort.o -o StringSort

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

sort.o: sort.cpp
	$(CC) $(CFLAGS) sort.cpp

clean:
	rm -rf *.o StringSort