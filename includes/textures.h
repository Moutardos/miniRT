/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:56:05 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/15 18:19:28 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# define CHECKER_W 2
# define CHECKER_H 2

# define BM_WOOD_W 1024
# define BM_WOOD_H 1024
# define BM_WOOD_SIZE 1048576
# define BM_SAND_W 736
# define BM_SAND_H 736
# define BM_SAND_SIZE 541696

# define BLACK 0x000000

# include <stdint.h>
# include <stdbool.h>

typedef struct s_data			t_data;
typedef struct s_img			t_img;
typedef struct s_point			t_point;
typedef struct s_object			t_object;
typedef struct s_vector			t_vector;
typedef struct s_point_info		t_point_info;
typedef struct s_object_array	t_object_array;
typedef struct s_sphere			t_sphere;
typedef struct s_cylinder		t_cylinder;
typedef struct s_cone			t_cone;
typedef struct s_plane			t_plane;

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

enum e_bump_map_type
{
	WOOD,
	SAND
};
typedef struct s_texture_coordinates
{
	double	x;
	double	y;
}	t_texture_coordinates;

typedef struct s_bump_map
{
	enum e_bump_map_type	type;
	int						height;
	int						width;
	t_vector				**map;
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
		t_bump_map	map;
	};
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
int						init_texture(t_texture *texture, char **line);

int						init_bump_map(t_bump_map *map, char **line);
void					destroy_bump_maps(t_object_array *objects);

bool					init_checker(t_checker *checker, char **line);
t_color					get_checker_pattern(t_texture_coordinates point,
							t_texture *texture);

#endif
