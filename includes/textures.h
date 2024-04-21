/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:56:05 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/21 21:15:31 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# define CHECKER_PL_W 2
# define CHECKER_PL_H 2
# define CHECKER_CY_W 4
# define CHECKER_CY_H 4
# define CHECKER_CO_W 6
# define CHECKER_CO_H 6
# define CHECKER_SP_W 6
# define CHECKER_SP_H 6

# define BLACK 0x000000

# include <stdint.h>
# include <stdbool.h>

# include "mlx_info.h"

typedef struct s_data			t_data;
typedef struct s_point			t_point;
typedef struct s_object			t_object;
typedef struct s_vector			t_vector;
typedef struct s_point_info		t_point_info;
typedef struct s_object_array	t_object_array;
typedef struct s_sphere			t_sphere;
typedef struct s_cylinder		t_cylinder;
typedef struct s_cone			t_cone;
typedef struct s_plane			t_plane;
typedef struct s_bump_map		t_bump_map;

enum							e_object_type;

typedef double					t_color_intensity[3];

typedef union u_color
{
	uint32_t	hex;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
}	t_color;

enum e_texture_type
{
	NONE,
	BUMP,
	CH
};

typedef struct s_texture_coordinates
{
	double	x;
	double	y;
}	t_texture_coordinates;

typedef struct s_bump_map
{
	char					*path_name;
	t_img					img;
	t_vector				*map;
	t_bump_map				*next;
}	t_bump_map;

typedef struct s_checker
{
	int		width;
	int		height;
	t_color	color_b;
}	t_checker;

typedef struct s_texture
{
	enum e_texture_type	type;
	t_color				color;
	union
	{
		t_checker	checker;
		t_bump_map	*bump_map;
	};
	t_bump_map			**bump_maps;
}	t_texture;

void					find_pix_color(unsigned int i, unsigned int j,
							t_data *data);

t_color					get_point_color(t_point_info *point_info);

void					init_color_intensity(t_color_intensity color_intensity);
void					get_colored_intensity(
							t_color_intensity color_intensity,
							t_color light_color, double intensity);
void					intensify_color(t_color *color,
							t_color_intensity color_intensity);

void					color_img_pix(t_img *img, int x, int y, int color);

t_texture_coordinates	get_cy_coord(t_cylinder *cylinder,
							t_point_info *point_info);
t_texture_coordinates	get_co_coord(t_cone *cone, t_point_info *point_info);
t_texture_coordinates	get_pl_coord(t_plane *plane,
							t_point_info *point_info);
t_texture_coordinates	get_sp_coord(t_sphere *sphere,
							t_point_info *point_info);

t_texture_coordinates	point_to_texture_coordinates(t_point_info *point_info);
int						init_texture(t_data *data, t_texture *texture,
							enum e_object_type type,
							char **line);

int						get_bump_map(t_data *data, t_texture *texture,
							char **ptr_line);
void					destroy_bump_maps(t_data *data,
							t_object_array *objects,
							int len);

bool					init_checker(t_checker *checker,
							enum e_object_type type,
							char **line);
t_color					get_checker_pattern(t_texture_coordinates point,
							t_texture *texture);

#endif
