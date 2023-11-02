NAME		:= lib42.a
LIBFT_DIR	:= libft
DPRINTF_DIR	:= ftdprintf
GNL_DIR		:= get_next_line
BUILD_DIR	:= build

AR_FILES	:= $(LIBFT_DIR)/libft.a \
			$(DPRINTF_DIR)/libftdprintf.a \
			$(GNL_DIR)/libgnl.a


AR			= ar
RM			= rm -f

ARFLAGS		= -crs

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):
			@make -C $(LIBFT_DIR) bonus
			@make -C $(DPRINTF_DIR) all
			@make -C $(GNL_DIR) all
			@mkdir -p $(BUILD_DIR)
			@cp $(LIBFT_DIR)/*.a $(DPRINTF_DIR)/*.a $(GNL_DIR)/*.a $(BUILD_DIR)
			@cp $(LIBFT_DIR)/libft.h $(DPRINTF_DIR)/includes/ft_dprintf.h $(GNL_DIR)/get_next_line.h $(BUILD_DIR)
			$(AR) $(ARFLAGS) $(NAME) $(AR_FILES)

clean:
			@make -C $(LIBFT_DIR) clean
			@make -C $(DPRINTF_DIR) clean
			@make -C $(GNL_DIR) clean
			$(RM) -r $(BUILD_DIR)

fclean:
			@make -C $(LIBFT_DIR) fclean
			@make -C $(DPRINTF_DIR) fclean
			@make -C $(GNL_DIR) fclean
			$(RM) $(NAME)

re: fclean all
