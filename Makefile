# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 11:32:26 by wfoulon           #+#    #+#              #
#    Updated: 2017/12/12 11:34:15 by wfoulon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= srcs/convertion.c \
		srcs/draw_line.c \
		srcs/draw_line2.c \
		srcs/error.c \
		srcs/function_event.c \
		srcs/init_env.c \
		srcs/init_img.c \
		srcs/init_map.c \
		srcs/init_node.c \
		srcs/main.c \
		srcs/print_image.c \
		srcs/print_image2.c \
		srcs/reinitialise.c \
		srcs/rt.c \
		srcs/tools.c \

OBJ= $(SRCS:.c=.o)

INCLUDES= -I libft/includes -I includes -I mlx/

LIBS= -L./libft/ -lft -L./mlx/ -lmlx -lm

FLAGS = -Wall -Werror -Wextra

FRAMEWORK= -framework OpenGL -framework Appkit

all: 		$(NAME)

$(NAME):	$(OBJ)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJ) $(LIBS) $(FRAMEWORK)
	@echo "		\033[31;1m"
	@echo "		  ,__________,  ,____________,     "
	@echo "		  |          |  |             \    "
	@echo "		  |____.     |  |    ,___,     \   "
	@echo "		      /     /   |    |    \     \  "
	@echo "		     /     /    |    |     \     \ "
	@echo "		    /_____/     |____|     /     / "
	@echo "		  ,______________________./     /  "
	@echo "		  |                            /   "
	@echo "		  |__________________________./    "
	@echo "\033[0m"
	@echo "		  ZDTEAM                   2018"
	@echo "\n"

$(OBJ): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@


clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	@rm -f $(OBJ)
	@echo "\033[37mall FDF_files.o are deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m$(NAME) is deleted\033[0m"

re:			fclean all

.PHONY: all clean fclean re
