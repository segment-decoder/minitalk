# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/24 20:56:19 by gyun              #+#    #+#              #
#    Updated: 2026/08/27 00:51:43 by gyun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c

SRCS_CLIENT_BN = client_bonus.c utils_bonus.c
SRCS_SERVER_BN = server_bonus.c utils_bonus.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT_BN = $(SRCS_CLIENT_BN:.c=.o)
OBJS_SERVER_BN = $(SRCS_SERVER_BN:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBDIR = libft
LIBFT = $(LIBDIR)/libft.a
INCLUDE = -I. -I$(LIBDIR)
HEADER = minitalk.h $(LIBDIR)/libft.h

ifdef WITH_BONUS
	CLIENT_OBJ_FILES = $(OBJS_CLIENT_BN)
	SERVER_OBJ_FILES = $(OBJS_SERVER_BN)
else
	CLIENT_OBJ_FILES = $(OBJS_CLIENT)
	SERVER_OBJ_FILES = $(OBJS_SERVER)
endif

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(CLIENT_OBJ_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ_FILES) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER) : $(SERVER_OBJ_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(SERVER_OBJ_FILES) $(LIBFT) -o $(NAME_SERVER)

$(LIBFT) :
	$(MAKE) -s -C $(LIBDIR) all

bonus :
	$(MAKE) WITH_BONUS=1 all

clean :
	$(MAKE) -s -C $(LIBDIR) clean
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BN) $(OBJS_SERVER_BN)

fclean : clean
	$(MAKE) -s -C $(LIBDIR) fclean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re : fclean all

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re bonus