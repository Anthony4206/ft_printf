NAME 				= libft.a

DIR_SRCS 			= srcs
DIR_OBJS 			= objs
SUB_DIRS 			= put str mem to is lst

SRCS_DIRS 			= ${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_SRCS}/, ${dir}}}
OBJS_DIRS 			= ${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_OBJS}/, ${dir}}}
SRCS 				= ${foreach dir, ${SRCS_DIRS}, ${wildcard ${dir}/*.c}}
OBJS 				= ${subst ${DIR_SRCS}, ${DIR_OBJS}, ${SRCS:.c=.o}}

INCLUDES 			= -I./../includes

CC 					= gcc
CFLAGS 				= -Wall -Wextra -Werror

AR 					= ar rc
RM 					= rm -f
REC 				= -r

GREEN				:= "\033[0;32m"
CYAN				:= "\033[0;36m"
RESET				:= "\033[0m"

${DIR_OBJS}/%.o: 	${DIR_SRCS}/%.c
					mkdir -p ${DIR_OBJS} ${OBJS_DIRS}
					${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: 			${OBJS}
					${AR} ${NAME} ${OBJS}
					echo ${GREEN}"Compiled '${NAME}' with success" ${RESET}

all: 				${NAME}

clean:
					${RM} ${OBJS}
					echo ${CYAN}"Cleaned 'libft' objects with success"${RESET}
					${RM} ${REC} ${DIR_OBJS}
					echo ${CYAN}"Cleaned '${DIR_OBJS}' 'libft' with success"${RESET}

fclean: 			clean
					${RM} ${NAME}
					echo ${CYAN}"Removed '${NAME}' with success"${RESET}

re: 				fclean all

.PHONY: 			all clean fclean re
