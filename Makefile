# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 18:11:29 by lgaultie          #+#    #+#              #
#    Updated: 2020/02/17 17:49:08 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = @clang
CFLAGS = -Wall -Werror -Wextra -g
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
OBJDIR = obj
SRCDIR = src
INC = ./includes/

SRCS =	main.c			\
		flag.c			\
		free.c			\
		get_elements.c	\
		create_list.c	\
		print.c

OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#voir GNU 8.3 Functions for File Names

_GREEN=\e[32m
_PURPLE=\e[35m
_BLUE=\e[34m
_BLUE1=\e[1;34m
_YELLOW=\e[33m
_CYAN=\e[36m
_CYAN1=\e[1;36m
_RED=\e[31m
_END=\e[0m

all: $(NAME)
	@printf "$(_CYAN1)    _                   _ _   _      _       __ _       _      \n"
	@printf "$(_CYAN1)   | | __ _  __ _ _   _| | |_(_) ___( )__   / _| |_    | |___  \n"
	@printf "$(_CYAN1)   | |/ _'  / _' | | | | | __| |/ _ \/ __| | |_| __|   | / __| \n"
	@printf "$(_CYAN1)   | | (_| | (_| | |_| | | |_| |  __/\__ \ |  _| |_    | \__ \ \n"
	@printf "$(_CYAN1)   |_|\__, |\__,_|\__,_|_|\__|_|\___||___/ |_|  \__|___|_|___/ \n"
	@printf "$(_CYAN1)      |___/                                       |_____|     $(_END)\n\n"
#http://patorjk.com/software/taag/#p=display&f=Ogre&t=lgaultie's%20ft_ls

$(NAME): $(OBJ)
	@printf "$(_YELLOW)Compiling libft... $(_END)"
	@make -C $(LIBDIR)
	@printf "$(_YELLOW)Compilation... $(_END)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -I$(INC) -o $(NAME)
	@printf "$(_GREEN)ft_ls done [✓]$(_END)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c includes/ft_ls.h
	@$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(OBJDIR) :
	@printf "$(_YELLOW)Creating $(_PURPLE)ft_ls$(_YELLOW) obj folder $(_END)"
	@mkdir $@
	@printf "$(_CYAN)done$(_END)\n"

$(OBJ) : | $(OBJDIR)
#voir GNU make 4.3 Types of Prerequisites

clean:
	@printf "$(_YELLOW)clean... $(_END)"
	@cd $(LIBDIR) && make clean
	@rm -rf $(OBJDIR)
	@printf "$(_CYAN)done$(_END)\n"

fclean: clean
	@printf "$(_YELLOW)fclean... $(_END)"
	@cd $(LIBDIR) && make fclean
	@rm -rf $(NAME)
	@printf "$(_CYAN)done $(_END)\n"

re: fclean all clean

.PHONY: clean fclean all re
