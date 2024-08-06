# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 20:14:57 by jjhang            #+#    #+#              #
#    Updated: 2024/08/06 16:15:49 by yeoshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Imlx -Wall -Wextra -Werror
NAME = miniRT
LIBFT = libft/libft.a

MANDATORY_DIR = mandatory
PARSER_DIR = mandatory/rt_parser
OBJECTS_DIR = mandatory/objects
RAY_DIR = mandatory/ray
HIT_DIR = mandatory/hit
UTILES_DIR = mandatory/rt_utiles
VEC_DIR = mandatory/vector

OBJ_DIR = obj

HEADER_DIR = mandatory/include
LIBFT_DIR = libft

SRCS_FILES = main.c

PARSER_FILES = get_ambient_lightning.c \
				get_camera_data.c \
				get_triangle_data.c \
				get_cylinder_data.c \
				get_light_data.c \
				get_multi_data.c \
				get_next_vertex.c \
				get_plane_data.c \
				get_single_data.c \
				get_cone_data.c \
				get_sphere_data.c \
				is_comment.c \
				is_valid_file.c \
				minirt_parser.c \
				rt_error_handler.c \
				skip_white_space.c \
				get_type_data.c \
				get_img_file.c

VEC_FILES = vec_div_mul.c \
			vec_init.c \
			vec_plus_minus.c \
			vec_pro.c \
			vec_unit.c \
			vec_utile.c \
			random_in_unit_vec.c

RAY_FILES = cam.c \
			get_color_from_texture.c \
			light.c \
			phong_light.c \
			ray.c \
			set_face_normal.c \
			shadow.c \
			point_light_get.c

HIT_FILES = hit.c

OBJECTS_FILES = cylinder_utile.c \
				triangle.c \
				cylinder.c \
				object.c \
				plane.c \
				sphere.c \
				checker.c

UTILES_FILES = is_char_range.c \
				utile.c \
				clamp.c

PARSER_SRCS =  $(addprefix $(PARSER_DIR)/, $(PARSER_FILES))
VEC_SRCS = $(addprefix $(VEC_DIR)/, $(VEC_FILES))
RAY_SRCS = $(addprefix $(RAY_DIR)/, $(RAY_FILES))
HIT_SRCS = $(addprefix $(HIT_DIR)/, $(HIT_FILES))
UTILES_SRCS = $(addprefix $(UTILES_DIR)/, $(UTILES_FILES))
OBJECTS_SRCS = $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_FILES))
SRCS_SRCS =  $(addprefix $(MANDATORY_DIR)/, $(SRCS_FILES))

OBJS = $(PARSER_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(VEC_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(RAY_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(HIT_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(OBJECTS_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(UTILES_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(SRCS_FILES:%.c=$(OBJ_DIR)/%.o)

HEADER = $(HEADER_DIR)

#----------------------------------------------------------------------------------------------------------#

BONUS_DIR = bonus_file
BONUS_PARSER_DIR = bonus_file/rt_parser
BONUS_OBJECTS_DIR = bonus_file/objects
BONUS_RAY_DIR = bonus_file/ray
BONUS_HIT_DIR = bonus_file/hit
BONUS_UTILES_DIR = bonus_file/rt_utiles
BONUS_VEC_DIR = bonus_file/vector

BONUS_OBJ_DIR = obj

BONUS_HEADER_DIR = bonus_file/include

BONUS_SRCS_FILES = main_bonus.c

BONUS_PARSER_FILES = get_ambient_lightning_bonus.c \
				get_camera_data_bonus.c \
				get_triangle_data_bonus.c \
				get_cylinder_data_bonus.c \
				get_light_data_bonus.c \
				get_multi_data_bonus.c \
				get_next_vertex_bonus.c \
				get_plane_data_bonus.c \
				get_single_data_bonus.c \
				get_cone_data_bonus.c \
				get_sphere_data_bonus.c \
				is_comment_bonus.c \
				is_valid_file_bonus.c \
				minirt_parser_bonus.c \
				rt_error_handler_bonus.c \
				skip_white_space_bonus.c \
				get_type_data_bonus.c \
				get_img_file_bonus.c

BONUS_VEC_FILES = vec_div_mul_bonus.c \
			vec_init_bonus.c \
			vec_plus_minus_bonus.c \
			vec_pro_bonus.c \
			vec_unit_bonus.c \
			vec_utile_bonus.c \
			random_in_unit_vec_bonus.c

BONUS_RAY_FILES = cam_bonus.c \
			get_color_from_texture_bonus.c \
			light_bonus.c \
			phong_light_bonus.c \
			ray_bonus.c \
			set_face_normal_bonus.c \
			shadow_bonus.c \
			point_light_get_bonus.c

BONUS_HIT_FILES = hit_bonus.c

BONUS_OBJECTS_FILES = cylinder_utile_bonus.c \
				triangle_bonus.c \
				cylinder_bonus.c \
				object_bonus.c \
				plane_bonus.c \
				sphere_bonus.c \
				checker_bonus.c

BONUS_UTILES_FILES = is_char_range_bonus.c \
				utile_bonus.c \
				clamp_bonus.c

BONUS_PARSER_SRCS =  $(addprefix $(BONUS_PARSER_DIR)/, $(BONUS_PARSER_FILES))
BONUS_VEC_SRCS = $(addprefix $(BONUS_VEC_DIR)/, $(BONUS_VEC_FILES))
BONUS_RAY_SRCS = $(addprefix $(BONUS_RAY_DIR)/, $(BONUS_RAY_FILES))
BONUS_HIT_SRCS = $(addprefix $(BONUS_HIT_DIR)/, $(BONUS_HIT_FILES))
BONUS_UTILES_SRCS = $(addprefix $(BONUS_UTILES_DIR)/, $(BONUS_UTILES_FILES))
BONUS_OBJECTS_SRCS = $(addprefix $(BONUS_OBJECTS_DIR)/, $(BONUS_OBJECTS_FILES))
BONUS_SRCS_SRCS =  $(addprefix $(BONUS_MANDATORY_DIR)/, $(BONUS_SRCS_FILES))

BONUS_OBJS = $(BONUS_PARSER_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(BONUS_VEC_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(BONUS_RAY_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(BONUS_HIT_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(BONUS_OBJECTS_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(BONUS_UTILES_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(BONUS_SRCS_FILES:%.c=$(OBJ_DIR)/%.o)

BONUS_HEADER = $(HEADER_DIR)

all : $(LIBFT) $(NAME)

$(LIBFT) :
		@make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
		@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -L$(LIBFT_DIR) -o $(NAME) $^
		@echo ✅[miniRT] has been built

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

$(OBJ_DIR)/%.o : $(MANDATORY_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

#------------------------------------------------------------------------------------#

$(OBJ_DIR)/%.o : $(BONUS_PARSER_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(BONUS_HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(BONUS_VEC_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(BONUS_HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(BONUS_RAY_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(BONUS_HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(BONUS_HIT_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(BONUS_HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(BONUS_UTILES_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(BONUS_HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(BONUS_OBJECTS_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(BONUS_HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(BONUS_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(BONUS_HEADER_DIR) -I $(LIBFT_DIR)


$(OBJ_DIR) :
		@mkdir -p $@

bonus : $(LIBFT) $(BONUS_OBJS)
		@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -L$(LIBFT_DIR) -o $(NAME) $^
		@echo ✅[miniRT bonus] has been built
		touch bonus

clean :
		@rm -f $(OBJS)
		@rm -f bonus
		@rm -f $(BONUS_OBJS)
		@rm -rf $(OBJ_DIR)
		@make -C $(LIBFT_DIR) clean

fclean : clean
		@rm -f $(NAME)
		@make -C $(LIBFT_DIR) fclean

re :
		$(MAKE) fclean
		$(MAKE) all

.PHONY : all clean fclean re