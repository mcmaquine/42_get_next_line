n=1

WFLAGS=-Wall -Wextra -Werror -DBUFFER_SIZE=$(n)

COMPILER=cc

SRC=get_next_line_utils.c get_next_line.c main.c
OBJ=$(SRC:.c=.o)

$(OBJ):	$(SRC)
	$(COMPILER) $(WFLAGS) -g -c $(SRC)

main:	$(OBJ)
	$(COMPILER) $(OBJ) -o $@

all:	main

clean:
	rm -f *.o

fclean: clean
	rm -f main