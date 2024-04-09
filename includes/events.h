/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:31:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 12:01:30 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define STEP 1
# define DIM 1
# define RGB_INCR 50

typedef struct s_point			t_point;
typedef struct s_vector			t_vector;

typedef struct s_plane			t_plane;
typedef struct s_sphere			t_sphere;
typedef struct s_cylinder		t_cylinder;

typedef struct s_data			t_data;

typedef struct s_mlx_info		t_mlx_info;
typedef struct s_frame			t_frame;

typedef struct s_camera			t_camera;

void	init_hooks(t_data *data);

int		call_destroynotify_handler(t_mlx_info *mlx_info);
int		call_keypress_handler(int keycode, t_data *data);

void	handle_translations(int keycode, t_point *point);
void	handle_rotations(int keycode,
			t_camera *camera,
			t_frame *frame,
			t_vector *direction);
void	handle_camera_translations(int keycode,
			t_camera *camera,
			t_frame *frame);
void	handle_camera_rotations(int keycode,
			t_camera *camera,
			t_frame *frame);

void	update_object_color(t_color *og_color, t_color *object_color);
void	update_plane_properties(int keycode,
			t_camera *camera,
			t_frame *frame,
			t_plane *plane);
void	update_sphere_properties(int keycode,
			t_sphere *sphere);
void	update_cylinder_properties(int keycode,
			t_camera *camera,
			t_frame *frame,
			t_cylinder *cylinder);

void	reload_scene(t_data *data);

#endif
