/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:52:50 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/08 11:23:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "colors.h"

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

typedef struct s_plane
{
	t_point		point;
	t_vector	vector;
}	t_plane;

typedef struct s_sphere
{
	t_point		center;
	double		diameter;
}	t_sphere;

typedef struct s_cylinder
{
	t_point		center;
	t_vector	vector;
	double		diameter;
	double		height;
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

int	init_sphere(t_object *object, char *line);
int	init_plane(t_object *object, char *line);
int	init_cylinder(t_object *object, char *line);

double	get_magnitude(t_vector v);
bool	is_vector_normalized(t_vector v);

#endif
