SRCS	=	sources/main.cpp \
			sources/Phonebook.cpp \
			sources/Contact.cpp

OBJS	= ${SRCS:.cpp=.o}
INCS	= includes
NAME	= phonebook
CC		= c++
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

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