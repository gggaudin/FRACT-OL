# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 09:04:24 by ggaudin-          #+#    #+#              #
#    Updated: 2017/07/07 16:13:54 by ggaudin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = srcs/

SRC = main.c\
      		more.c\
		celtic.c\
		mandelbrot.c\
		julia.c\
		calcfdf.c\
		calcfdf2.c\
		keyhookfdf.c\
		keyhookfdf2.c\
		keyhookfract.c\
		keyhookfract2.c\
		error.c\
		initcolor.c\
		batman.c\
		checkmap.c\
		fdf.c\
		fdf2.c\
		fdf3.c

FLAGS = -Wall -Wextra -Werror -Ofast -O2 -O3

OBJ = $(SRC:.c=.o)

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

INC = -I ./includes -I ./libft/

LIB = -L minilibx -lmlx -framework OpenGL -framework Appkit -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(OBJ) $(INC) $(LIB) -o $(NAME)
	@echo "$(GREEN)[✓] FRACTOL: READY!$(NC)"

%.o: $(SRC_PATH)%.c
	@gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	@rm -f $(OBJ)
	@echo "$(RED)[-] FRACTOL: SUPPRESSION DES FICHIERS OBJETS.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[-] FRACTOL: SUPPRESSION DE L'EXECUTABLE.$(NC)"
	@make fclean -C ./libft/

re: fclean all

.PHONY : all re clean fclean
