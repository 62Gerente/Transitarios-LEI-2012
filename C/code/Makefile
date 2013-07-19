OPT_OR_DEBUG=-O9
CFLAGS=-g -Wall -Wextra -ansi $(OPT_OR_DEBUG)
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))


transitarios: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)
clean:
	rm transitarios $(wildcard *.o) $(wildcard *.h.ghc) $(wildcard *.c.ghc)
