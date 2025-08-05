n=5

WFLAGS=-Wall -Wextra -Werror -DBUFFER_SIZE=$(n)

COMPILER=cc

SRC=get_next_line.c

a:	$(SRC)
	$(COMPILER) $(WFLAGS) -g $< -o $@

all:	a

clean:
	rm -f *.o

fclean: clean
	rm -f a
