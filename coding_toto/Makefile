
CC := g++

SOURCE := main.cpp library.cpp toto.cpp
HEADER := library.h toto.h

.PHONY:all
all: clean $(SOURCE)
	$(CC) $(SOURCE) -o prog
	time ./prog

.PHONY:clean
clean:
	rm -rf *.o *.exe *.out prog
