n=10000000

WFLAGS=-Wall -Wextra -Werror

COMPILER=cc

SRC=get_next_line_utils.c get_next_line.c main.c

SRC_BONUS=get_next_line_utils_bonus.c get_next_line_bonus.c mainbonus.c

BUF=-DBUFFER_SIZE=$(n)

OBJ=$(SRC:.c=.o)

BONUS_OBJ=$(SRC_BONUS:.c=.o)

.PHONY: main all bonus mainbonus nobuffer nobufferbonus clean fclean

%.o:	$(SRC)
	$(COMPILER) $(WFLAGS) $(BUF) -g -c $(SRC)

main:	$(OBJ)
	$(COMPILER) $(OBJ) -g -o $@

bonus: $(BONUS_OBJ)
	$(COMPILER) $(BONUS_OBJ) -g -o main

all:	main

nobuffer: $(SRC) main
	$(COMPILER) $(WFLAGS) -g -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f main
