CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = parsing_errors.c \
	  sort.c \
	  sort_utils.c \
	  stack_limits.c \
	  utils.c \
	  stacks_init.c \
	  stacks_init_2.c \
	  ft_split.c \
	  commands/push.c \
	  commands/swap.c \
	  commands/rotate.c \
	  commands/r_rotate.c

OBJ = $(SRC:.c=.o)
MAIN = main.c
MAIN_OBJ = $(MAIN:.c=.o)

all: $(NAME)

%.o: %.cc
	$(CC) $(FLAGS) -c $< -o $@

$(MAIN_OBJ) : $(MAIN)
	$(CC) $(FLAGS) -c $(MAIN) -o $(MAIN_OBJ)

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MAIN_OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re