CC = gcc 
CFLGAS = -Wall -O2

all : main.o sys.o
	$(CC) -o learnc main.o sys.o
main.o : main.c sys.h
	$(CC) -c -o main.o main.c
sys.o : sys.c sys.h
	$(CC) -c -o sys.o sys.c
clean:
	rm -f *.o
tag:
	ctags -R

