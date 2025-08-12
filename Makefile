n=100

WFLAGS=-Wall -Wextra -Werror -DBUFFER_SIZE=$(n)

COMPILER=cc

SRC=get_next_line.c get_next_line_utils.c main.c

main:	$(SRC)
	$(COMPILER) $(WFLAGS) -g $< -o $@

all:	main

clean:
	rm -f *.o

fclean: clean
	rm -f main
