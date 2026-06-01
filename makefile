CC=gcc
CFLAGS=-Wall

OBJS=main.o list.o add.o sub.o mul.o div.o compare.o print.o

apc: $(OBJS)
	$(CC) -o apc $(OBJS)

clean:
	rm -f *.o apc
