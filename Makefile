CFLAGS += -g
LFLAGS +=

all: daemon

daemon: daemon.o
	$(CC) $(LFLAGS) -o $@ $^

clean:
	rm -rf daemon *.o

dep:
	$(CC) $(CFLAGS) -M *.c *.h > .depend

.c.o:
	$(CC) $(CFLAGS) -c $< 

include .depend
