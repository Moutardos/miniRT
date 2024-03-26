/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:52:50 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/26 02:11:15 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define EPSILON 0.0001

# include "colors.h"

typedef struct s_camera	t_camera;

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

typedef struct s_utils_pl
{
	t_vector		camera_point;
	double			dot_prod_const;
}	t_utils_pl;

typedef struct s_plane
{
	t_point			point;
	t_vector		vector;
	t_utils_pl		utils;
}	t_plane;

typedef struct s_utils_sp
{
	t_vector	center_camera;
	t_vector	center_origin;
	double		center_origin_magnitude;
	double		c_const;
}	t_utils_sp;

typedef struct s_sphere
{
	t_point		center;
	double		diameter;
	t_utils_sp	utils;
}	t_sphere;

typedef struct s_utils_cy
{
	double		halved_height;
	t_vector	center_camera;
	double		squared_mag_dir;
	double		dsquared_mag_dir;
	double		c_const;
	double		p_const;
}	t_utils_cy;

typedef struct s_cylinder
{
	t_point		center;
	t_vector	vector;
	double		diameter;
	double		height;
	t_utils_cy	utils;
}	t_cylinder;

enum e_object_type
{
	PL,
	SP,
	CY
};

typedef struct s_object
{
	enum e_object_type	type;
	t_color				color;
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_cylinder	cylinder;
	};
}	t_object;

typedef struct s_object_array
{
	t_object	*array;
	int			len;
}	t_object_array;

int		init_sphere(t_object *object, char *line);
int		init_plane(t_object *object, char *line);
int		init_cylinder(t_object *object, char *line);

void	fill_utils(t_camera *camera, t_object_array *object_array);

#endif
