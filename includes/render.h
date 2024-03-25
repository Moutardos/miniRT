/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:10:29 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/25 11:20:41 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "objects.h"

typedef struct s_frame
{
	t_point		origin;
	t_vector	dir_j;
	t_vector	dir_i;
	double		width;
	double		height;
	double		delta_x;
	double		delta_y;
}	t_frame;

typedef struct s_data	t_data;
typedef struct s_camera	t_camera;

void		init_frame(t_frame *frame, t_camera *camera);

void		run_rt(t_data *data);

void		find_pix_color(unsigned int i, unsigned int j, t_data *data);

t_vector	compute_ray(unsigned int i, unsigned int j,
				t_camera *camera,
				t_frame *frame);
bool		is_ray_intersecting_obj(t_object *object,
				t_vector ray);

t_vector	create_vector(t_point start_point, t_point end_point);
double		get_vector_magnitude(t_vector v);
bool		is_unit_vector(t_vector v);
t_vector	multiply_vector(double scalar, t_vector vector);
t_vector	normalize_vector(t_vector vector);
double		perform_dot_product(t_vector vector1, t_vector vector2);
t_vector	sum_vectors(t_vector vector1, t_vector vector2);
t_point		translate_point(t_point point, t_vector vector);


#endif
