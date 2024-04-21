# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 14:04:37 by ekhaled           #+#    #+#              #
#    Updated: 2024/04/22 01:56:13 by lcozdenm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	miniRT


LIBS				:=	mlx Xext X11 m ft
LIBS_TARGET			:=	\
						libraries/minilibx-linux/libmlx.a \
						libraries/libft/libft.a


SRC_DIR				:=	sources

SRCS_DESTROY		:=	\
						destroy_data.c \
						destroy_mlx_info.c \
						destroy_object_array.c \
						destroy_light_array.c \
						destroy_light_utils.c

SRCS_EVENTS			:=	\
						call_handlers.c \
						handle_rotations.c \
						handle_translations.c \
						init_hooks.c \
						reload_scene.c \
						update_object_color.c \
						update_object_properties.c

SRCS_FILL_UTILS		:=	\
						fill_utils_cone.c \
						fill_utils_cylinder.c \
						fill_utils_plane.c \
						fill_utils_sphere.c \
						fill_utils.c 

SRCS_INIT_L_UTILS	:=	\
						init_light_utils_co.c \
						init_light_utils_cy.c \
						init_light_utils_pl.c \
						init_light_utils_sp.c \
						init_light_utils.c

SRCS_INIT			:=	\
						${addprefix fill_utils/, ${SRCS_FILL_UTILS}} \
						${addprefix init_light_utils/, ${SRCS_INIT_L_UTILS}} \
						init_data.c \
						init_frame.c \
						init_mlx_info.c \
						init_object.c \
						init_settings.c \
						update_settings.c

SRCS_NORMAL_MAP		:=	\
						extract_image.c \
						extract_path.c

SRCS_PARSING		:=	\
						${addprefix normal_map/, ${SRCS_NORMAL_MAP}} \
						extract_params.c \
						extract_values.c \
						file_check.c \
						fill_data.c \
						ignore_space.c \
						is_single_argument.c \
						str_to_obj.c \
						str_to_texture.c


SRCS_CAMRAY			:=	\
						is_camray_intersecting_co.c \
						is_camray_intersecting_cy.c \
						is_camray_intersecting_disk.c \
						is_camray_intersecting_obj.c \
						is_camray_intersecting_pl.c \
						is_camray_intersecting_sp.c 

SRCS_LIGHTRAY		:=	\
						is_lightray_intersecting_co.c \
						is_lightray_intersecting_cy.c \
						is_lightray_intersecting_obj.c \
						is_lightray_intersecting_disk.c \
						is_lightray_intersecting_pl.c \
						is_lightray_intersecting_sp.c 

SRCS_OBJ_INTER		:=	\
						${addprefix camray/, ${SRCS_CAMRAY}} \
						${addprefix lightray/, ${SRCS_LIGHTRAY}}

SRCS_RENDER			:=	\
						${addprefix object_intersections/, ${SRCS_OBJ_INTER}} \
						apply_shader.c \
						compute_ray.c \
						find_pix_color.c \
						init_point_info.c \
						run_rt.c

SRCS_BUMP_MAP		:=	\
						destroy_bump_maps.c \
						get_bump_map.c \
						perturb_normal.c

SRCS_MAPPING_OBJECT	:=	\
						get_co_coord.c \
						get_cy_coord.c \
						get_pl_coord.c \
						get_sp_coord.c \
						point_to_texture_coord.c

SRCS_TEXTURES		:=	\
						${addprefix bump_map/, ${SRCS_BUMP_MAP}} \
						${addprefix mapping_object/, ${SRCS_MAPPING_OBJECT}} \
						checker.c \
						color_img_pix.c \
						get_colored_intensity.c \
						get_point_color.c \
						init_color_intensity.c \
						intensify_color.c \
						init_texture.c

SRCS_MATRIX_UTILS	:=	\
						get_matrix_rotation.c \
						multiply_vector_by_matrix.c \
						rotate_vector_upside.c

SRCS_EQUATION_UTILS	:=	\
						get_min_positive_root.c \
						solve_quadratic_equation.c

SRCS_VECTOR_UTILS	:=	\
						create_vector.c \
						get_surface_normal.c \
						get_vector_magnitude.c \
						is_unit_vector.c \
						multiply_vector.c \
						normalize_vector.c \
						perform_cross_product.c \
						perform_dot_product.c \
						rotate_point.c \
						rotate_point.c \
						sum_vectors.c \
						translate_point.c 


SRCS_UTILS			:=	\
						${addprefix equation_utils/, ${SRCS_EQUATION_UTILS}} \
						${addprefix matrix_utils/, ${SRCS_MATRIX_UTILS}} \
						${addprefix vector_utils/, ${SRCS_VECTOR_UTILS}} 

SRCS				:=	\
						${addprefix textures/, ${SRCS_TEXTURES}} \
						${addprefix destroy/, ${SRCS_DESTROY}} \
						${addprefix events/, ${SRCS_EVENTS}} \
						${addprefix init/, ${SRCS_INIT}} \
						${addprefix parsing/, ${SRCS_PARSING}} \
						${addprefix render/, ${SRCS_RENDER}} \
						${addprefix utils/, ${SRCS_UTILS}} \
						main.c

SRCS				:=	${SRCS:%=${SRC_DIR}/%}


OBJ_DIR				:=	objects
OBJS				:=	${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

CFLAGS				:=	-Wall -Wextra -Werror
CPPFLAGS			:=	-I includes -I libraries/minilibx-linux -I libraries/libft/includes
LDFLAGS				:=	${addprefix -L, ${dir ${LIBS_TARGET}}}
LDLIBS				:=	${addprefix -l, ${LIBS}}


RM					:=	${RM} -r
DIR_DUP				=	mkdir -p ${@D}

all: ${NAME}

${NAME}: $(LIBS_TARGET) ${OBJS}
	${CC} ${LDFLAGS} $^ ${LDLIBS} -o $@ 

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

bonus: all

clean: 
	${MAKE} clean -C libraries/minilibx-linux/
	${MAKE} fclean -C libraries/libft/
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean
	${MAKE} all

.PHONY: clean fclean re
