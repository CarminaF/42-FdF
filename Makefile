# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 18:44:40 by cfamilar          #+#    #+#              #
#    Updated: 2023/02/23 16:31:14 by cfamilar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#cc -Wall -Wextra -Werror  -lmlx -L ./libraries/libft/ -L ./libraries/minilibx/ -framework OpenGL -framework AppKit -I ./includes/ -I ./libraries/minilibx/ ./sources/main.c
NAME			=	fdf

LIBFT_DIR		=	./libraries/libft/
LIBFT			=	$(LIBFT_DIR)libft.a

MINILIBX_DIR	=	./libraries/minilibx/
MINILIBX		=	$(MINILIBX_DIR)libmlx.a

HEADER			=	$(INC_DIR)/fdf.h

SRCS_DIR		=	sources
INC_DIR			=	includes
OBJS_DIR		=	objects

SRCS			=	$(SRCS_DIR)/colour.c\
					$(SRCS_DIR)/controls.c\
					$(SRCS_DIR)/draw.c\
					$(SRCS_DIR)/error.c\
					$(SRCS_DIR)/free.c\
					$(SRCS_DIR)/init.c\
					$(SRCS_DIR)/key_input.c\
					$(SRCS_DIR)/lines.c\
					$(SRCS_DIR)/main.c\
					$(SRCS_DIR)/map.c\
					$(SRCS_DIR)/menu.c\
					$(SRCS_DIR)/projection.c\
					$(SRCS_DIR)/utils.c	\

OBJS			=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC				=	gcc
RM				=	rm -rf

LIBS			=	-lmlx -lft -L $(LIBFT_DIR) -L $(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES		=	-I $(INC_DIR) -I $(MINILIBX) -I$(LIBFT_DIR)
FLAGS			=	-Wall -Wextra -Werror 

all:				$(LIBFT) $(MINILIBX) $(OBJS_DIR) $(OBJS)
					@echo Compiling wireframe program...
					$(CC) $(FLAGS) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)
					@echo Wireframe program ready.

$(OBJS_DIR):
					mkdir -p $(OBJS_DIR)
					
$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADER)
					$(CC) $(FLAGS) -c $< -o $@
					
$(LIBFT):
					$(MAKE) -sC $(LIBFT_DIR) bonus

$(MINILIBX):
					$(MAKE) -sC $(MINILIBX_DIR)

clean:
					$(MAKE) -sC $(LIBFT_DIR) fclean
					$(MAKE) -sC $(MINILIBX_DIR) clean
					$(RM) $(OBJS_DIR)
					@echo "Clean complete."

fclean:				clean
					$(RM) $(NAME)
					@echo "Fclean complete."

re:					fclean all

.PHONY:				all clean fclean re 