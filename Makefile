# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 20:14:57 by jjhang            #+#    #+#              #
#    Updated: 2024/07/29 20:20:13 by jjhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Imlx -Wall -Wextra -Werror -g -g3 #-fsanitize=address
NAME = miniRT
LIBFT = libft/libft.a

PARSER_DIR = rt_parser
OBJECTS_DIR = objects
RAY_DIR = ray
HIT_DIR = hit
UTILES_DIR = rt_utiles
SRCS_DIR = mandatory
VEC_DIR = vector

OBJ_DIR = obj

HEADER_DIR = include
LIBFT_DIR = libft

SRCS_FILES = main.c

PARSER_FILES = edit_objects_vector.c \
				get_ambient_lightning.c \
				get_camera_data.c \
				get_triangle_data.c \
				get_cylinder_data.c \
				get_light_data.c \
				get_multi_data.c \
				get_plane_data.c \
				get_single_data.c \
				get_cone_data.c \
				get_sphere_data.c \
				is_comment.c \
				is_valid_file.c \
				minirt_parser.c \
				rt_error_handler.c \
				skip_white_space.c \
				get_type_data.c

VEC_FILES = vec_div_mul.c \
			vec_init.c \
			vec_plus_minus.c \
			vec_pro.c \
			vec_unit.c \
			vec_rotate.c \
			vec_utile.c

RAY_FILES = cam.c \
			light.c \
			phong_light.c \
			ray.c \
			shadow.c

HIT_FILES = hit.c

OBJECTS_FILES = cylinder_utile.c \
				triangle.c \
				cylinder.c \
				object.c \
				plane.c \
				sphere.c \
				checker.c

UTILES_FILES = is_char_range.c \
				utile.c

PARSER_SRCS = $(addprefix $(PARSER_DIR)/, $(PARSER_FILES))
VEC_SRCS = $(addprefix $(VEC_DIR)/, $(VEC_FILES))
RAY_SRCS = $(addprefix $(RAY_DIR)/, $(RAY_FILES))
HIT_SRCS = $(addprefix $(HIT_DIR)/, $(HIT_FILES))
UTILES_SRCS = $(addprefix $(UTILES_DIR)/, $(UTILES_FILES))
OBJECTS_SRCS = $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_FILES))
SRCS_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(PARSER_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(VEC_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(RAY_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(HIT_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(OBJECTS_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(UTILES_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(SRCS_FILES:%.c=$(OBJ_DIR)/%.o) \

HEADER = $(HEADER_DIR)

all : $(LIBFT) $(NAME)

$(LIBFT) :
		@make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
		@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -L$(LIBFT_DIR) -o $(NAME) $^
		@echo ✅[miniRT_parser] has been built

$(OBJ_DIR)/%.o : $(PARSER_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(VEC_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(RAY_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(HIT_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(UTILES_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(OBJECTS_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)


$(OBJ_DIR) :
		@mkdir -p $@

clean :
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)
		@make -C $(LIBFT_DIR) clean

fclean : clean
		@rm -f $(NAME)
		@make -C $(LIBFT_DIR) fclean

re :
		$(MAKE) fclean
		$(MAKE) all

.PHONY : all clean fclean re