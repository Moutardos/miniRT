# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 20:55:42 by ekhaled           #+#    #+#              #
#    Updated: 2024/04/17 18:15:47 by lcozdenm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft

SRC_DIR		:=	sources

SRCS		:=	\
				are_doubles_equals.c \
				ft_calloc.c \
				ft_dabs.c \
				ft_dmax.c \
				ft_dclamp.c \
				ft_dmin.c \
				ft_isdigit.c \
				ft_iswhitespace.c \
				ft_max.c \
				ft_min.c \
				ft_putstr_fd.c \
				ft_strchri.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_substrrange.c \
				get_next_line.c \
				is_same_first_word.c

SRCS			:=	${SRCS:%=${SRC_DIR}/%}

OBJ_DIR			:=	objects
OBJS			:=	${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	-I includes 

RM					:=	${RM} -r
AR					:=	ar -rc
DIR_DUP				=	mkdir -p ${@D}

all: ${addsuffix .a, ${NAME}}

${addsuffix .a, ${NAME}}: ${OBJS}
	${AR} ${addsuffix .a, ${NAME}} ${OBJS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

clean: 
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${addsuffix .a, ${NAME}}

re: fclean
	${MAKE} all

.PHONY: clean fclean re
