# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 15:58:37 by ivan-mel          #+#    #+#              #
#    Updated: 2022/11/09 15:11:16 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a
RM 			=	rm -rf
FLAGS 		=	-Wall -Werror -Wextra
CC 			= 	gcc
AR 			=	ar -rc
SRC			=	ft_printf.c \
				printfunctions.c \
				hexafunctions.c \
#SRCB		=	
OBJ_FILES	=	${SRC:.c=.o}
#OBJB_FILES	=	${SRCB:.c=.o}
OBJ_DIR	=	./obj/
# Reset
Color_Off	=	"\033[0m"			# Text Reset
# Regular Colors
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White
# Avoid relinking in bonus
ifdef WITH_BONUS
	OBJ_RAW = $(OBJ_FILES) $(OBJB_FILES)
else
	OBJ_RAW = $(OBJ_FILES)
endif
# Add obj directory to obj path
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_RAW))
all:	${NAME}
${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${AR} ${NAME} $?
	@echo ${Green} Complete 😊 ${Color_off}
$(OBJ_DIR)%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} -c $< -o $@
# Set 'WITH_BONUS' option to make with bonus
#bonus:
#	@$(MAKE) WITH_BONUS=true all
clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
	@${RM} ${OBJ_DIR}
fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${RM} ${NAME}
re:	fclean all
.PHONY: all bonus clean fclean re