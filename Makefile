# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcochin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 13:54:33 by mcochin           #+#    #+#              #
#    Updated: 2022/09/12 14:37:35 by mcochin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
	parsing.c \
	psa_utils.c \
	psb_utils.c \
	error_utils.c \
	a_instructs.c \
	b_instructs.c \
	main_sort.c \
	sort_utils.c \
	sort_big.c \
	radix.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFTPATH = libft/libft.a

CC = gcc
CFLAGS = -g -Werror -Wextra -Wall
RM = rm -f
MAKE = make -C

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFTPATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPATH)

$(LIBFTPATH) :
	$(MAKE) $(LIBFT)

clean :
	$(RM) $(OBJS)
	$(MAKE) $(LIBFT) clean

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re : fclean $(NAME)

f : fclean

r : all
	@clear
	@./$(NAME)

.PHONY : all fclean re clean
