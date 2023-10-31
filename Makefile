NAME		:= push_swap
INC_DIR		:= include
SRC_DIR		:= source
LIB_DIR		:= library
BUILD_DIR	:= build
LIBFT_DIR	:= $(LIB_DIR)/libft
DPRINTF_DIR	:= $(LIB_DIR)/ftdprintf
GNL_DIR		:= $(LIB_DIR)/get_next_line

SRCS		:= push_swap.c \
			parse_input.c \
			stack.c \
			sort.c \
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

CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address -I$(INC_DIR) -I$(LIBFT_DIR) -I$(DPRINTF_DIR)/includes -I$(GNL_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

.PHONY:		all bonus clean fclean re

$(NAME):	$(OBJS)
			@make -C $(LIBFT_DIR) bonus
			@make -C $(DPRINTF_DIR) all
			@make -C $(GNL_DIR) all
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(DPRINTF_DIR)/libftdprintf.a $(GNL_DIR)/gnl.a -o $(NAME)

all:		$(NAME)

clean:
			@make -C $(LIBFT_DIR) clean
			@make -C $(DPRINTF_DIR) clean
			@make -C $(GNL_DIR) clean
			$(RM) $(BUILD_DIR)/*.o

fclean:		clean
			@make -C $(LIBFT_DIR) fclean
			@make -C $(DPRINTF_DIR) fclean
			@make -C $(GNL_DIR) fclean
			$(RM) $(NAME)

re: 		fclean all
