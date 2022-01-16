SRCS_M	= mandatory/so_long.c mandatory/moves.c
OBJS_M	= ${SRCS_M:.c=.o}
NAME	= so_long

SRCS	= mandatory/check.c
OBJS	= ${SRCS:.c=.o}

SRCS_B	= bonus/animation_bonus.c bonus/moves_bonus.c bonus/so_long_bonus.c bonus/enemy_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}

HDRS	= -I./includes/so_long.h

CC		= gcc

LIB		= -L./libft/ -lft

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror ${HDRS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${OBJS_M}
				@make -C ./libft/
				${CC} ${LIB} ${HDRS} ${OBJS} ${OBJS_M} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all:		${NAME}

bonus:
				@make OBJS_M="$(OBJS_B)" all

clean:
			@make fclean -C ./libft
			${RM} ${OBJS_B} ${OBJS} ${OBJS_M}

fclean:		clean
			@make fclean -C ./libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
