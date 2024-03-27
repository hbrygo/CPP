SRCS	=	src/main.cpp \
			src/A.cpp \
			src/B.cpp \
			src/C.cpp \
			src/Base.cpp

OBJS	= ${SRCS:.cpp=.o}
INCS	= includes
NAME	= NAME
CC		= c++
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o} -I ${INCS}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re