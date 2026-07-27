# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 21:45:08 by gyun              #+#    #+#              #
#    Updated: 2026/07/28 01:42:56 by gyun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memmove.c\
 ft_strchr.c ft_strlcat.c ft_strlen.c ft_strnstr.c ft_tolower.c\
 ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_memset.c\
 ft_strdup.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_toupper.c\
 ft_memchr.c ft_memcmp.c ft_calloc.c ft_substr.c ft_strjoin.c\
 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
 ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
 ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
 ft_printf.c ft_printf_form_check.c\
 ft_printf_utility.c ft_printf_help.c\
 ft_printf_str.c ft_printf_char.c\
 ft_printf_ptr.c ft_printf_struct.c\
 ft_printf_dec.c ft_printf_un_dec.c\
 ft_printf_lower_hex.c ft_printf_upper_hex.c\
 get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
.PHONY: all clean fclean re