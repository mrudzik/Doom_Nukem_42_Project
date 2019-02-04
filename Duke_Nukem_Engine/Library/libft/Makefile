# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylesik <ylesik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 11:50:52 by mrudzik           #+#    #+#              #
#    Updated: 2018/11/08 13:12:43 by ylesik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#SRC_DIR = ./src/
#OBJ_DIR = ./obj_dir/

INC =	libft.h

FILES = 	ft_atoi.c			ft_itoa.c			ft_bzero.c \
			ft_isalpha.c		ft_isascii.c		ft_isdigit.c \
			ft_isprint.c		ft_isalnum.c 		ft_lstadd.c \
			ft_lstdel.c			ft_lstdelone.c 		ft_lstiter.c \
			ft_lstmap.c 		ft_lstnew.c			ft_memalloc.c \
			ft_memccpy.c 		ft_memchr.c 		ft_memcmp.c \
			ft_memcpy.c 		ft_memdel.c 		ft_memmove.c \
			ft_memset.c 		ft_putchar.c 		ft_putstr.c \
			ft_putendl.c 		ft_putnbr.c 		ft_putchar_fd.c \
			ft_putstr_fd.c 		ft_putendl_fd.c		ft_putnbr_fd.c \
			ft_strcat.c 		ft_strchr.c 		ft_strclr.c \
			ft_strcmp.c 		ft_strcpy.c 		ft_strdel.c \
			ft_strdup.c 		ft_strequ.c 		ft_striter.c \
			ft_striteri.c 		ft_strjoin.c 		ft_strlcat.c \
			ft_strlen.c 		ft_strmap.c 		ft_strmapi.c \
			ft_strncat.c 		ft_strncmp.c 		ft_strncpy.c \
			ft_strnequ.c 		ft_strnew.c 		ft_strnstr.c \
			ft_strrchr.c 		ft_strsplit.c 		ft_strstr.c \
			ft_strsub.c 		ft_strtrim.c 		ft_tolower.c \
			ft_toupper.c 		ft_iswhite.c 		ft_foreach.c \
			ft_range.c 			ft_count_if.c 		ft_sqrt.c \
			ft_abs.c 			

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

#HDR = libft.h

FLAGS = -Wall -Wextra -Werror -I $(INC) 

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)


# This won't run if the .o files don't exist or are not modified
$(NAME): $(OBJ)
	@ echo "\n===== Creating lib archive $(NAME) =====\n"
	@ ar rcs $(NAME) $(OBJ)

# This won't run if the source files don't exist or are not modified

$(OBJ_DIR)%.o: %.c
	@ gcc -c $< -o $@ $(FLAGS)

re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
# .PHONY: clean fclean all re
