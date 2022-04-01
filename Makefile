# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 07:00:06 by alevasse          #+#    #+#              #
#    Updated: 2022/03/31 13:39:13 by alevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libftprintf.a

DIR_SRCS 			= srcs
DIR_SRCS_B			= bonus
DIR_OBJS 			= objs
SUB_DIRS 			= printf
SUB_DIRS_B			=

SRCS_DIRS 			= ${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_SRCS}/, ${dir}}}
SRCS_DIRS_B			= ${foreach dir, ${SUB_DIRS_B}, ${addprefix ${DIR_SRCS_B}/, ${dir}}}
SRCS 				= ${foreach dir, ${SRCS_DIRS}, ${wildcard ${dir}/*.c}}
SRCS_B				= ${foreach dir, ${SRCS_DIRS_B}, ${wildcard ${dir}/*.c}}
OBJS_DIRS 			= ${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_OBJS}/, ${dir}}}

ifndef ADD_BONUS
		OBJS 	= ${subst ${DIR_SRCS}, ${DIR_OBJS}, ${SRCS:.c=.o}}
else
		OBJS	= ${subst ${DIR_SRCS_B}, ${DIR_OBJS}, ${SRCS_B:.c=.o}}
endif

TEST 			= main.c

INCLUDES 		= -I./includes

MAKE			= ./libft/

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

AR 				= ar rcs
RM 				= rm -f

REC 			= -r
CC_FLAGS 		= -L.
CC_LIBS 		= -lft

GREEN			:= "\033[0;32m"
CYAN			:= "\033[0;36m"
RESET			:= "\033[0m"

all: 			${NAME}

${NAME}: 		${OBJS}
				make all -C ${MAKE}
				echo ${GREEN}"Successfully updated 'libft'" ${RESET}
				cp libft/libft.a ${NAME}
				${AR} ${NAME} ${OBJS}
				echo ${GREEN}"Compiled '${NAME}' with success" ${RESET}

bonus:
				make ADD_BONUS=1 all

${DIR_OBJS}/%.o:	${DIR_SRCS}/%.c
				mkdir -p ${DIR_OBJS} ${OBJS_DIRS}
				${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${@:.c=.o}

test: 			all
				${CC} ${CFLAGS} ${TEST} ${CC_FLAGS} ${CC_LIBS} ${INCLUDES}
				echo ${GREEN}"Compiled '${TEST}' with success"${RESET}

clean:
				${RM} ${SRCS:.c=.o} ${SRCS_B:.c=.o} ./a.out
				echo ${CYAN}"Cleaned objects with success"${RESET}
				${RM} ${REC} ${DIR_OBJS}
				echo ${CYAN}"Cleaned '${DIR_OBJS}' with success"${RESET}
				make clean -C ${MAKE}

fclean: 		clean
				${RM} ${NAME}
				echo ${CYAN}"Removed '${NAME}' with success"${RESET}

re: 			fclean all

retest: 		re test

.PHONY: 		all bonus clean fclean re test retest
