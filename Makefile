# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 14:10:10 by eunlee            #+#    #+#              #
#    Updated: 2021/12/22 14:14:03 by eunlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .c .o

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
LEAKS	=	-g3 -fsanitize=address
RM		=	rm -f

NAME	=	philo

SRCS	=	philo.c \
			action.c \
			free.c \
			life.c \
			message.c \
			monitor.c \
			parsing.c \
			time.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

leaks: $(OBJS)
	$(CC) $(CFLAGS) $(LEAKS) -o $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re:	fclean all

.PHONY: clean fclean all re
