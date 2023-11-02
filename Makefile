NAME		:= push_swap
INC_DIR		:= include
SRC_DIR		:= source
LIB_DIR		:= library
BUILD_DIR	:= build

SRCS		:= push_swap.c \
			parse_input.c \
			stack.c \
			stack_utils.c \
			sort.c \
			sort_special.c \
			sort_utils.c \
			op_swap.c \
			op_push.c \
			op_rotate.c \
			op_rev_rotate.c \
			error.c \
			free.c \
			utils.c

SRCS 		:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS 		:= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

CC			= cc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address -I$(INC_DIR) -I$(LIB_DIR)/build

.PHONY:		all bonus clean fclean re

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			@make -C $(LIB_DIR) all
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/build/*.a -o $(NAME)

all:		$(NAME)

clean:
			@make -C $(LIB_DIR) clean
			$(RM) $(BUILD_DIR)/*.o

fclean:		clean
			@make -C $(LIB_DIR) fclean
			$(RM) $(NAME)

re: 		fclean all
