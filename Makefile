CFLAGS += -g
LFLAGS +=

all: daemon

daemon: daemon.o
	$(CC) $(LFLAGS) -o $@ $^

clear:

dep:
	$(CC) $(CFLAGS) -M *.c *.h > .depend

.c.o:
	$(CC) $(CFLAGS) -c $< 

include .depend
