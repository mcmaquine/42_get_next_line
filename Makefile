n=42

WFLAGS=-Wall -Wextra -Werror -D BUFFER_SIZE=$(n) TFILE="testfile"

COMPILER=cc

SRC=get_next_line.c main.c

a:	$(SRC:.c=.o)
	$(COMPILER) $(WFLAGS) -c -g -o $@

all:	a

clean:
	rm -f *.o

fclean: clean
	rm -f a