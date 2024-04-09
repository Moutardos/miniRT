/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:10:29 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 15:57:30 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "objects.h"

# define HITPOINT_OFFSET 0.001

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

typedef struct s_point_info
{
	t_point		point;
	t_vector	cp;
	double		cp_magnitude;
	t_object	*object;
	t_vector	normal;
}	t_point_info;

typedef struct s_data	t_data;
typedef struct s_camera	t_camera;

void		init_frame(t_frame *frame, t_camera *camera);

t_point		get_frame_origin(t_frame *frame, t_camera *camera);

void		run_rt(t_data *data);

void		init_point_info(t_point_info *point_info);

void		find_pix_color(unsigned int i, unsigned int j, t_data *data);

t_vector	compute_ray(unsigned int i, unsigned int j,
				t_camera *camera,
				t_frame *frame);

bool		is_ray_intersecting_obj(t_object *object,
				t_vector ray,
				t_point_info *point_info);
bool		is_ray_intersecting_cy(t_cylinder *cylinder,
				t_vector ray,
				t_point_info *point_info);
bool		is_ray_intersecting_pl(t_plane *plane,
				t_vector ray,
				t_point_info *point_info);
bool		is_ray_intersecting_sp(t_sphere *sphere,
				t_vector ray,
				t_point_info *point_info);

bool		is_lightray_intersecting_obj(t_object *object,
				t_vector lightray, double t_max);
bool		is_lightray_intersecting_cy(t_cylinder *cylinder, t_vector lightray,
				double t_max);
bool		is_lightray_intersecting_pl(t_plane *plane,
				t_vector lightray, double t_max);
bool		is_lightray_intersecting_sp(t_sphere *sphere,
				t_vector lightray, double t_max);

double		get_lightintensity(t_data *data, t_point_info *p_info);

t_vector	create_vector(t_point start_point, t_point end_point);
double		get_vector_magnitude(t_vector v);
bool		is_unit_vector(t_vector v);
t_vector	multiply_vector(double scalar, t_vector vector);
t_vector	normalize_vector(t_vector vector);
double		perform_dot_product(t_vector vector1, t_vector vector2);
t_vector	sum_vectors(t_vector vector1, t_vector vector2);
t_point		translate_point(t_point point, t_vector vector);

#endif
