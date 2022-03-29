# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 07:00:06 by alevasse          #+#    #+#              #
#    Updated: 2022/03/29 09:11:16 by alevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libftprintf.a

SRCS 		= 	ft_printf.c

OBJS 		=	${SRCS:.c=.o}

CC 			= 	gcc
CFLAGS 		= 	-Wall -Wextra -Werror

AR 			= 	ar rc
RM 			= 	rm -f

%.o: 			%.c
				@${CC} ${CFLAGS} -o ${@} -c ${@:.o=.c}

${NAME}: 		${OBJS}
				@${AR} ${NAME} ${OBJS}

all: 			${NAME}		

clean:
				${RM} ${OBJS} ${BONUS_OBJS} bonus
				@echo ${CYAN}"Cleaned objects with success"${RESET}


fclean: 		clean
				@${RM} ${NAME}
				@echo ${CYAN}"Removed '${NAME}' with success"${RESET}

re: 			fclean all

.PHONY: 		all clean fclean re 