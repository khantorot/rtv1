# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glychest <glychest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 06:44:55 by glychest          #+#    #+#              #
#    Updated: 2020/11/20 16:18:19 by hinterfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC			:=	\
sources/algos/col.c             sources/algos/plane.c           sources/parser/init.c \
sources/algos/cone.c            sources/algos/render.c          sources/parser/light.c \
sources/algos/cylinder.c        sources/algos/rotation.c        sources/parser/object.c \
sources/algos/helpers.c         sources/algos/small_func.c      sources/parser/parse.c \
sources/algos/helpers2.c        sources/algos/sphere.c          sources/parser/read.c \
sources/algos/helpers3.c        sources/main/main.c             sources/parser/smfunc.c \
sources/algos/normals.c         sources/parser/error.c          sources/parser/utils.c \
sources/algos/nrmls.c           sources/parser/hook.c

FLAGS			=	-Wall -Werror -Wextra
framework		=	-L minilibx_macos -lmlx -framework OpenCL -framework OpenGL -framework AppKit -L libft -lft -O2
BUILD_DIR		=   build
LIB_DIR			=	libft
SRC_DIR			=	sources
RT_INC			=	-I includes -I libft -I minilibx_macos
# LIB_INC			=	-I libft
# OBJECTS			=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
OBJECTS			=	$(patsubst sources%.c, build%.o, $(SRC))
LIB_MLX_FILE	=	minilibx_macos/libmlx.a
LIB_FT_FILE		=   $(LIB_DIR)/libft.a


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(LIB_MLX_FILE) $(BUILD_DIR) $(OBJECTS)
	gcc $(OBJECTS) -o $@ $(framework)

$(BUILD_DIR):
	mkdir -vp build/main
	mkdir -vp build/parser
	mkdir -vp build/algos

$(LIB_FT_FILE):
	make -C $(LIB_DIR)

$(LIB_MLX_FILE):
	make -C minilibx_macos

build/%.o: sources/%.c Makefile includes/rtv1.h
	gcc $(FLAGS) -c $< $(RT_INC) -o $@

clean:
	make clean -C $(LIB_DIR)
	make clean -C minilibx_macos
	rm -rf $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re: fclean all
