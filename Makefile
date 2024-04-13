# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 14:04:37 by ekhaled           #+#    #+#              #
#    Updated: 2024/04/13 19:50:40 by ekhaled          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	miniRT


LIBS				:=	mlx Xext X11 m ft
LIBS_TARGET			:=	\
						libraries/minilibx-linux/libmlx.a \
						libraries/libft/libft.a


SRC_DIR				:=	sources

SRCS_COLORS			:=	\
						color_img_pix.c \
						get_intensified_color.c

SRCS_DESTROY		:=	\
						destroy_data.c \
						destroy_mlx_info.c

SRCS_EVENTS			:=	\
						call_handlers.c \
						handle_rotations.c \
						handle_translations.c \
						init_hooks.c \
						reload_scene.c \
						update_objects.c 

SRCS_FILL_UTILS		:=	\
						fill_utils_cylinder.c \
						fill_utils_plane.c \
						fill_utils_sphere.c \
						fill_utils.c 

SRCS_INIT			:=	\
						${addprefix fill_utils/, ${SRCS_FILL_UTILS}} \
						init_data.c \
						init_frame.c \
						init_mlx_info.c \
						init_object.c \
						init_settings.c \
						update_settings.c

SRCS_PARSING		:=	\
						extract_params.c \
						extract_values.c \
						file_check.c \
						fill_data.c \
						ignore_space.c \
						is_single_argument.c \
						str_to_obj.c


SRCS_CAMRAY			:=	\
						is_camray_intersecting_cy.c \
						is_camray_intersecting_disk.c \
						is_camray_intersecting_obj.c \
						is_camray_intersecting_pl.c \
						is_camray_intersecting_sp.c 

SRCS_LIGHTRAY		:=	\
						is_lightray_intersecting_cy.c \
						is_lightray_intersecting_obj.c \
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

SRCS_EQUATION_UTILS	:=	\
						get_min_positive_root.c \
						solve_quadratic_equation.c

SRCS_VECTOR_UTILS	:=	\
						create_vector.c \
						get_vector_magnitude.c \
						is_unit_vector.c \
						multiply_vector.c \
						normalize_vector.c \
						perform_dot_product.c \
						sum_vectors.c \
						translate_point.c 

SRCS_UTILS			:=	\
						${addprefix equation_utils/, ${SRCS_EQUATION_UTILS}} \
						${addprefix vector_utils/, ${SRCS_VECTOR_UTILS}}


SRCS				:=	\
						${addprefix colors/, ${SRCS_COLORS}} \
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

clean: 
	${MAKE} clean -C libraries/minilibx-linux/
	${MAKE} fclean -C libraries/libft/
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean
	${MAKE} all

.PHONY: clean fclean re
