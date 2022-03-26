##
## EPITECH PROJECT, 2021
## 102architect
## File description:
## Makefile
##

SRC	=	main.c	\
		transform_simple_cases.c	\

CFLAGS	=	-Wall -Wextra

LDFLAGS	=	-L. -lmy -lm

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

all:	$(NAME)

$(NAME):	$(OBJ)
	make	-C	lib/my/
	gcc	-o	$(NAME)	$(SRC) $(LDFLAGS)

clean:
	rm -f	$(OBJ)
	rm -f *~
	rm -f '#'*'#'
	make	-C	lib/my/	clean

fclean:	clean
	rm	-f	$(NAME)
	make	-C	lib/my/	fclean

re:	fclean all

.PHONY = $(NAME) clean fclean re
