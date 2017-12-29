# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arive-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 16:10:03 by arive-de          #+#    #+#              #
#    Updated: 2017/06/08 13:50:57 by arive-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= checker
NAME2= push_swap

SRC= ./srcs_ck/checker.c \
	 ./srcs_ck/ft_list.c \
	 ./srcs_ck/moves.c \
	 ./srcs_ck/moves2.c \
	 ./srcs_ck/moves3.c \
	 ./srcs_ck/solver.c

SRC2= ./srcs_ps/ft_list.c \
	  ./srcs_ps/helper2.c \
	  ./srcs_ps/moves.c \
	  ./srcs_ps/moves2.c \
	  ./srcs_ps/moves3.c \
	  ./srcs_ps/push_swap.c \
	  ./srcs_ps/init.c \
	  ./srcs_ps/solver.c \
	  ./srcs_ps/init_moves.c \
	  ./srcs_ps/calcul.c \
	  ./srcs_ps/brut.c \
	  ./srcs_ps/helper.c

OBJ= $(subst .c,.o, $(SRC))
OBJ2= $(subst .c,.o, $(SRC2))

CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I libft/

FILH= includes/checker.h
FILH2= includes/push_swap.h
INCDIR= -I includes/

all: $(LIBFT) $(NAME) $(NAME2)

$(NAME): $(OBJ) $(FILH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(INCDIR)

$(NAME2): $(OBJ2) $(FILH2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) $(LIBFT) $(INCDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<

$(LIBFT):
	make -C libft

clean:
	/bin/rm -rf $(OBJ) $(OBJ2)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME) $(NAME2)
	/bin/rm -rf ./libft/libft.a

re: fclean all
