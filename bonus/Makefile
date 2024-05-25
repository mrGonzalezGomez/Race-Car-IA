##
## EPITECH PROJECT, 2023
## iaiaiiaiaaiiaaa
## File description:
## Makefile
##


NAME	=	ai

SRCS	=	main.c	\
			mstwa.c	\
			libcomm.c	\
			playsong.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I./includes

CPPFLAGS	=	-W -Wextra -Wall -lSDL2 -lSDL2_mixer

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
	@find -name "*.o" -delete
	@find -name "*~" -delete
	@find -name "vgcore.*" -delete
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	@echo "\e[32m[OK] Done\e[0m"


fclean:	clean
	@rm -rf $(NAME)
	@rm -rf n4s_package/$(NAME)
re:	fclean all

l:  all
	cp $(NAME) n4s_package
	cd n4s_package && ./$(NAME) | ./n4s
