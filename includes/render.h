/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:10:29 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/15 18:06:42 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "objects.h"

# define OFFSET 0.02
# define SPECULARITY 550

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
	t_vector	pc;
	double		cp_magnitude;
	t_object	*object;
	t_vector	normal;
	t_vector	surface_normal;
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

bool		is_camray_intersecting_obj(t_object *object,
				t_vector ray,
				t_point_info *point_info);
bool		is_camray_intersecting_disk(t_plane *induced_plane,
				double disk_radius,
				t_vector ray,
				t_point_info *point_info);
bool		is_camray_intersecting_cy(t_cylinder *cylinder,
				t_vector ray,
				t_point_info *point_info);
bool		is_camray_intersecting_pl(t_plane *plane,
				t_vector ray,
				t_point_info *point_info);
bool		is_camray_intersecting_sp(t_sphere *sphere,
				t_vector ray,
				t_point_info *point_info);
bool		is_camray_intersecting_co(t_cone *cone,
				t_vector ray,
				t_point_info *point_info);


bool		is_lightray_intersecting_obj(t_object *object,
				t_vector lightray,
				double t_max,
				int light_index);
bool		is_lightray_intersecting_disk(t_plane *induced_plane,
				double disk_radius,
				t_vector lightray,
				double t_max);
bool		is_lightray_intersecting_cy(t_cylinder *cylinder,
				t_vector lightray,
				double t_max);
bool		is_lightray_intersecting_co(t_cone *cone,
				t_vector lightray,
				double t_max);
bool		is_lightray_intersecting_pl(t_plane *plane,
				t_vector lightray,
				double t_max);
bool		is_lightray_intersecting_sp(t_sphere *sphere,
				t_vector lightray,
				double t_max);
	
void		apply_shader(t_color *point_color,
				t_data *data,
				t_point_info *p_info);

void		get_surface_normal(t_point_info *p_info);
t_vector	perturb_normal(t_vector normal_facing,
				t_point_info *point_info);
#endif
