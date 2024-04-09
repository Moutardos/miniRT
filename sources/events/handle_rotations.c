/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:29:44 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 12:09:28 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "minirt.h"

void	handle_rotations(int keycode,
			t_camera *camera, t_frame *frame, t_vector *direction)
{
	if (ft_dabs(perform_dot_product(frame->dir_j, *direction)) == 1)
	{
		if (keycode == XK_Right || keycode == XK_Left)
			*direction = frame->dir_i;
	}
	else if (ft_dabs(perform_dot_product(frame->dir_i, *direction)) == 1)
	{
		if (keycode == XK_Right || keycode == XK_Left)
			*direction = frame->dir_j;
		if (keycode == XK_Up || keycode == XK_Down)
			*direction = camera->vector;
	}
	else if (ft_dabs(perform_dot_product(camera->vector, *direction)) == 1)
	{
		if (keycode == XK_Up || keycode == XK_Down)
			*direction = frame->dir_i;
	}
}

void	handle_camera_rotations(int keycode, t_camera *camera,
			t_frame *frame)
{
	t_vector	old_cam_dir;

	old_cam_dir = camera->vector;
	if (keycode == XK_Up)
	{
		camera->vector = multiply_vector(-1, frame->dir_i);
		frame->dir_i = old_cam_dir;
	}
	else if (keycode == XK_Down)
	{
		camera->vector = frame->dir_i;
		frame->dir_i = multiply_vector(-1, old_cam_dir);
	}
	else if (keycode == XK_Right)
	{
		camera->vector = frame->dir_j;
		frame->dir_j = multiply_vector(-1, old_cam_dir);
	}
	else if (keycode == XK_Left)
	{
		camera->vector = multiply_vector(-1, frame->dir_j);
		frame->dir_j = old_cam_dir;
	}
	frame->origin = get_frame_origin(frame, camera);
}
