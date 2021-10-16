# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:45:42 by jna               #+#    #+#              #
#    Updated: 2021/10/16 16:14:20 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = ./codes/pipex.c \
	   ./codes/set_infos.c \
	   ./codes/set_fds.c \
	   ./codes/set_stdout_from_cmd.c \
	   ./codes/get_fd.c \
	   ./codes/error_msg.c

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
