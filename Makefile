# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 07:00:06 by alevasse          #+#    #+#              #
#    Updated: 2022/03/30 19:31:37 by Anthony          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a

DIR_SRCS 		= srcs
DIR_OBJS 		= objs

SRCS 			= ${foreach dir, ${SRCS_DIRS}, ${wildcard ${dir}/*.c}}
OBJS 			= ${subst ${DIR_SRCS}, ${DIR_OBJS}, ${SRCS:.c=.o}}

TEST 			= main.c

INCLUDES 		= -I./includes

CC 			= gcc
CFLAGS 			= -Wall -Wextra -Werror

AR 			= ar rcs
RM 			= rm -f

REC 			= -r
CC_FLAGS 		= -L.
CC_LIBS 		= -lft

GREEN			:= "\033[0;32m"
CYAN			:= "\033[0;36m"
RESET			:= "\033[0m"

${DIR_OBJS}/%.o: 	${DIR_SRCS}/%.c
			@mkdir -p ${DIR_OBJS} ${OBJS_DIRS}
			@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: 		${OBJS}
			${AR} ${NAME} ${OBJS}
			@echo ${GREEN}"Compiled '${NAME}' with success" ${RESET}

all: 			${NAME}

test: 			all
			${CC} ${CFLAGS} ${TEST} ${CC_FLAGS} ${CC_LIBS} ${INCLUDES}
			@echo ${GREEN}"Compiled '${TEST}' with success"${RESET}

clean:
			${RM} ${OBJS}
			@echo ${CYAN}"Cleaned objects with success"${RESET}
			${RM} ${REC} ${DIR_OBJS}
			@echo ${CYAN}"Cleaned '${DIR_OBJS}' with success"${RESET}

fclean: 		clean
			${RM} ${NAME}
			echo ${CYAN}"Removed '${NAME}' with success"${RESET}

re: 			fclean all

retest: 		re test
