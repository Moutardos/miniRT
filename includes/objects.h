/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:52:50 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/07 19:34:40 by ekhaled          ###   ########.fr       */
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
	t_vector		point_camera;
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
	double		radius;
	t_vector	center_camera;
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
	double		radius;
	t_vector	center_camera;
	double		c_const;
	double		p_const;
	t_point		disk1_center;
	t_point		disk2_center;
	t_plane		induced_plane1;
	t_plane		induced_plane2;
	t_vector	disk1_center_camera;
	t_vector	disk2_center_camera;
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

int		init_object(t_object *object, char *line);

void	fill_utils(t_camera *camera, t_object_array *object_array);

#endif
