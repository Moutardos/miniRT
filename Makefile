# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 14:04:37 by ekhaled           #+#    #+#              #
#    Updated: 2024/04/01 10:37:04 by ekhaled          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	miniRT


LIBS				:=	mlx Xext X11 m
LIBS_TARGET			:=	libraries/minilibx-linux/libmlx.a


SRC_DIR				:=	sources

SRCS_COLORS			:=	\
						color_img_pix.c \
						get_intensified_color.c

SRCS_DESTROY		:=	\
						destroy_data.c \
						destroy_mlx_info.c

SRCS_EVENTS			:=	\
						call_handlers.c \
						handle_camera.c \
						init_hooks.c \
						reload_scene.c

SRCS_INIT			:=	\
						fill_utils.c \
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

SRCS_RENDER			:=	\
						${addprefix equation_utils/, ${SRCS_EQUATION_UTILS}} \
						${addprefix vector_utils/, ${SRCS_VECTOR_UTILS}} \
						compute_ray.c \
						find_pix_color.c \
						get_lightintensity.c \
						is_ray_intersecting_obj.c \
						run_rt.c

SRCS_GNL			:=	\
						ft_calloc.c \
						ft_strchri.c \
						ft_strcpy.c \
						ft_strdup.c \
						ft_strjoin.c \
						ft_substrrange.c \
						get_next_line.c

SRCS_UTILS			:=	\
						${addprefix get_next_line/, ${SRCS_GNL}} \
						are_doubles_equals.c \
						ft_dabs.c \
						ft_dmin.c \
						ft_max.c \
						ft_isdigit.c \
						ft_putstr_fd.c \
						ft_strcmp.c \
						ft_strlen.c \
						is_same_first_word.c 

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
CPPFLAGS			:=	-I includes -I libraries/minilibx-linux
LDFLAGS				:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS				:=	${addprefix -l, ${LIBS}}


RM					:=	${RM} -r
DIR_DUP				=	mkdir -p ${@D}

all: ${NAME}

${NAME}: $(LIBS_TARGET) ${OBJS}
	${CC} ${LDFLAGS} $^ ${LDLIBS} -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $< -gdwarf-4

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

clean:
	${MAKE} clean -C $(dir $(LIBS_TARGET))
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean
	${MAKE} all
