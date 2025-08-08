n=42

WFLAGS=-Wall -Wextra -Werror -DBUFFER_SIZE=$(n)

COMPILER=cc

SRC=get_next_line.c\
	get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all:	libgnl.a

$(OBJ):	$(SRC)
	$(COMPILER) $(WFLAGS) $(SRC) -g -c

libgnl.a: $(OBJ)
	ar -rcs $@ $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f libgnl.a
	rm -f main

main: libgnl.a main.c
	gcc -static -g main.c $< -o $@
