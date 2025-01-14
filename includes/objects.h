/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:52:50 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/19 16:05:01 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "textures.h"

typedef struct s_camera			t_camera;
typedef struct s_light			t_light;
typedef struct s_light_array	t_light_array;
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_light_utils_pl
{
	t_vector	point_light;
	double		dot_prod_const_light;
}	t_light_utils_pl;

typedef struct s_light_utils_pl_array
{
	t_light_utils_pl	*array;
	int					len;
}	t_light_utils_pl_array;

typedef struct s_utils_pl
{
	t_vector				point_camera;
	double					dot_prod_const_camera;
	t_light_utils_pl_array	light_utils_array;
	t_light_utils_pl		*light_utils;
}	t_utils_pl;

typedef struct s_plane
{
	t_point		point;
	t_vector	vector;
	t_utils_pl	utils;
}	t_plane;

typedef struct s_light_utils_sp
{
	t_vector	center_light;
	double		lc_const;
}	t_light_utils_sp;

typedef struct s_light_utils_sp_array
{
	t_light_utils_sp	*array;
	int					len;
}	t_light_utils_sp_array;

typedef struct s_utils_sp
{
	double					radius;
	t_vector				center_camera;
	double					cc_const;
	t_light_utils_sp_array	light_utils_array;
	t_light_utils_sp		*light_utils;
}	t_utils_sp;

typedef struct s_sphere
{
	t_point		center;
	double		diameter;
	t_utils_sp	utils;
}	t_sphere;

typedef struct s_light_utils_cy
{
	t_vector	center_light;
	double		lc_const;
	double		lp_const;
}	t_light_utils_cy;

typedef struct s_light_utils_cy_array
{
	t_light_utils_cy	*array;
	int					len;
}	t_light_utils_cy_array;

typedef struct s_utils_cy
{
	double					halved_height;
	double					radius;
	t_vector				center_camera;
	double					cc_const;
	double					cp_const;
	t_point					disk1_center;
	t_point					disk2_center;
	t_plane					induced_plane1;
	t_plane					induced_plane2;
	t_light_utils_cy_array	light_utils_array;
	t_light_utils_cy		*light_utils;
}	t_utils_cy;

typedef struct s_cylinder
{
	t_point		center;
	t_vector	vector;
	double		diameter;
	double		height;
	t_utils_cy	utils;
}	t_cylinder;

typedef struct s_light_utils_co
{
	t_vector	disk1_center_light;
	double		la_const;
	double		lb_const;
	double		lc_const;
	double		dot_prod_disk1_center_light_dir;
}	t_light_utils_co;

typedef struct s_light_utils_co_array
{
	t_light_utils_co	*array;
	int					len;
}	t_light_utils_co_array;

typedef struct s_utils_co
{
	double					radius;
	t_point					disk1_center;
	t_point					disk2_center;
	t_vector				disk1_center_camera;
	double					ca_const;
	double					cb_const;
	double					cc_const;
	double					dot_prod_disk1_center_camera_dir;
	t_plane					induced_plane2;
	t_light_utils_co_array	light_utils_array;
	t_light_utils_co		*light_utils;
}	t_utils_co;

typedef struct s_cone
{
	t_point		center;
	t_vector	vector;
	double		diameter;
	double		height;
	t_utils_co	utils;
}	t_cone;

enum e_object_type
{
	PL,
	SP,
	CY,
	CO
};

typedef struct s_object
{
	enum e_object_type	type;
	t_texture			texture;
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_cone		cone;
	};
}	t_object;

typedef struct s_object_array
{
	t_object	*array;
	int			len;
}	t_object_array;

int		init_object(t_data *data, t_object *object, char *line);

int		init_light_utils(t_object_array *objects, t_light_array *lights);
int		init_light_utils_co(t_cone *cone, int len);
int		init_light_utils_cy(t_cylinder *cylinder, int len);
int		init_light_utils_pl(t_plane *plane, int len);
int		init_light_utils_sp(t_sphere *sphere, int len);
void	destroy_light_utils(t_object_array *objects, int stop);

void	fill_utils(t_camera *camera,
			t_light_array *light_array,
			t_object_array *object_array);

void	fill_plane_utils(t_plane *plane,
			t_camera *camera,
			t_light_array *light_array);

void	fill_sphere_utils(t_sphere *sphere,
			t_camera *camera,
			t_light_array *light_array);

void	fill_cylinder_utils(t_cylinder *cylinder,
			t_camera *camera,
			t_light_array *light_array);

void	fill_cone_utils(t_cone *cone,
			t_camera *camera,
			t_light_array *light_array);

#endif
