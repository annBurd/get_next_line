CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = get_next_line.c
OBJ = $(SRCS:.c=.o)

OBJ_DIR = ./obj/
LIB_DIR = ./libft/

M = main.c
MO = $(M:.c=.o)

BIN = test_gnl

all:
	@make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -I $(LIB_DIR) -o $(OBJ_DIR)$(OBJ) -c $(SRCS)
	@$(CC) $(CFLAGS) -I l$(LIB_DIR) -o $(OBJ_DIR)$(MO) -c $(M)
	@$(CC) -o $(BIN) $(OBJ_DIR)$(OBJ) $(OBJ_DIR)$(MO) -I $(LIB_DIR) -L $(LIB_DIR) -lft
	@echo "GNL: got $(BIN)"

clean:
	@$(RM) $(OBJ_DIR)$(OBJ)
	@$(RM) $(OBJ_DIR)$(MO)
	
fclean:	clean
	@$(RM) $(BIN)
	@make -C $(LIB_DIR) fclean
	@echo "GNL: fcleaned"


re: fclean all

.PHONY: all clean fclean re libft 

.NOTPARALLEL: all clean fclean re libft 
