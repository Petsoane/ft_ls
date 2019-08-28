# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 08:07:20 by lpetsoan          #+#    #+#              #
#    Updated: 2019/08/28 16:45:26 by lpetsoan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = ft_ls

SRC = cleanup.c\
	  main.c\
	  add_node.c\
	  create_path.c\
	  get_file_info.c\
	  parse_flags.c\
	  print_contents.c\
	  print_perms.c\
	  sort_insert.c\
	  print_form.c\
	  sort_t_checks.c\

OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) libft/libft.a

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
