NAME	:= gnl.a
SRCS	:= get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJS	= ${SRCS:.c=.o}

CC			= cc
AR			= ar
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g
ARFLAGS		= -crs

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

.PHONY:		all clean fclean re

$(NAME):	${OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
