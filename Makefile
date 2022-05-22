# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 15:00:38 by afaby             #+#    #+#              #
#    Updated: 2022/05/22 15:17:43 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

FT_PTF = ft_printf/
PTF_LIB = -L$(FT_PTF) -lftprintf -I$(FT_PTF)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):
	make -C $(FT_PTF)
	gcc $(CFLAGS) $(SRCS_CLIENT) -o $(NAME_CLIENT) $(PTF_LIB)

$(NAME_SERVER):
	make -C $(FT_PTF)
	gcc $(CFLAGS) $(SRCS_SERVER) -o $(NAME_SERVER) $(PTF_LIB)

clean:
	make clean -C $(FT_PTF)

fclean: clean
	make fclean -C $(FT_PTF)
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
