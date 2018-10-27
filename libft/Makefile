# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 19:02:29 by aburdeni          #+#    #+#              #
#    Updated: 2017/12/25 19:30:08 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMPLFLAGS = -Wall -Wextra -Werror
NAME = libft.a
RM = rm -rf
FTC = ft_bzero.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strsub.c
OBJ = $(FTC:.c=.o)

$(NAME):
	@gcc $(CMPLFLAGS) -c $(NAME:.a=.h) $(FTC)
	@ar rc $(NAME) $(OBJ)
	@echo "Libft: $(NAME) was created."

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	
fclean:	clean
	@$(RM) $(NAME)
	@$(RM) libft.h.gch

re: fclean all

.PHONY: all clean fclean re libft

.NOTPARALLEL: all clean fclean re libft
