# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:45:42 by jna               #+#    #+#              #
#    Updated: 2021/10/17 02:06:05 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = ./codes/pipex.c \
	   ./codes/check_argc.c \
	   ./codes/set_infos.c \
	   ./codes/get_cmds.c \
	   ./codes/get_fds.c \
	   ./codes/send_output_as_input.c \
	   ./codes/free_infos.c \

INCLUDE = ./headers

SUBDIR = ./libft

all: $(NAME)

$(NAME): Libft
		$(CC) $(CFLAGS) $(SRCS) libft/*.c -I $(INCLUDE) -o $(NAME)

Libft:
		cd $(SUBDIR); $(MAKE)

clean :
		cd $(SUBDIR); $(MAKE) clean
		rm -f *.o

fclean : clean
		cd $(SUBDIR); $(MAKE) fclean
		rm -f $(NAME)

re : fclean all
