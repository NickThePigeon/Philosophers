# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nicky <nicky@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/06 13:41:49 by nicky         #+#    #+#                  #
#    Updated: 2022/03/01 13:46:10 by nduijf        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =			philo
VPATH =			./src/ ./obj/
SRCS = 			main.c		\
				cycle.c		\
				initialize.c	\
				mutex.c		\
				thread.c	\
				monitor.c	\
				time.c		\
				philo_utils_one.c \
				philo_utils_two.c \
				error.c		\

OBJS			= $(SRCS:.c=.o)
OBJ_DIR			= ./obj/
INCL_DIR		= ./includes/
CFLAGS			= -g -Wall -Wextra -Werror -I${INCL_DIR} -fsanitize=thread
CC				= gcc

all:	$(NAME)

$(NAME): $(OBJS)
	mkdir -p $(OBJ_DIR)
	mv *.o $(OBJ_DIR)
	${CC} ${CFLAGS} -o ${NAME} $(addprefix $(OBJ_DIR), $(OBJS))

clean:
	rm -f $(addprefix $(OBJ_DIR), $(OBJS))

fclean:	clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re:	fclean $(NAME)

.PHONY: all clean fclean re
