# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 16:22:56 by afaby             #+#    #+#              #
#    Updated: 2022/05/22 15:10:44 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	ft_printf.c \
		ft_process.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_putnbr_base_u.c \
		ft_putptr.c \
		ft_strlen.c \
		ft_putnbr_base_ull.c

OBJS =	$(SRCS:.c=.o)

HDRS =	ft_print.h

CC   =	gcc

CFLAGS = -Wall -Wextra -Werror

RM     = rm -f

AR     = ar rcs

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
