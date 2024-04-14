/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:29:44 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 15:25:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "libft.h"
#include "minirt.h"

void	handle_dir_j_rotation(int keycode,
			t_frame *frame, t_vector *direction)
{
	if (perform_dot_product(frame->dir_j, *direction) == 1)
	{
		if (keycode == XK_Right)
			*direction = frame->dir_i;
		if (keycode == XK_Left)
			*direction = multiply_vector(-1, frame->dir_i);
	}
	else
	{
		if (keycode == XK_Right)
			*direction = multiply_vector(-1, frame->dir_i);
		if (keycode == XK_Left)
			*direction = frame->dir_i;
	}
}

void	handle_dir_i_rotation(int keycode,
			t_camera *camera, t_frame *frame, t_vector *direction)
{
	if (perform_dot_product(frame->dir_i, *direction) == 1)
	{
		if (keycode == XK_Down)
			*direction = camera->vector;
		if (keycode == XK_Up)
			*direction = multiply_vector(-1, camera->vector);
		if (keycode == XK_Left)
			*direction = frame->dir_j;
		if (keycode == XK_Right)
			*direction = multiply_vector(-1, frame->dir_j);
	}
	else
	{
		if (keycode == XK_Down)
			*direction = multiply_vector(-1, camera->vector);
		if (keycode == XK_Up)
			*direction = camera->vector;
		if (keycode == XK_Left)
			*direction = multiply_vector(-1, frame->dir_j);
		if (keycode == XK_Right)
			*direction = frame->dir_j;
	}
}

void	handle_dir_c_rotation(int keycode,
			t_camera *camera, t_frame *frame, t_vector *direction)
{
	if (perform_dot_product(camera->vector, *direction) == 1)
	{
		if (keycode == XK_Up)
			*direction = frame->dir_i;
		if (keycode == XK_Down)
			*direction = multiply_vector(-1, frame->dir_i);
	}
	else
	{
		if (keycode == XK_Up)
			*direction = multiply_vector(-1, frame->dir_i);
		if (keycode == XK_Down)
			*direction = frame->dir_i;
	}
}

void	handle_rotations(int keycode,
			t_camera *camera, t_frame *frame, t_vector *direction)
{
	if (ft_dabs(perform_dot_product(frame->dir_j, *direction)) == 1)
		handle_dir_j_rotation(keycode, frame, direction);
	else if (ft_dabs(perform_dot_product(frame->dir_i, *direction)) == 1)
		handle_dir_i_rotation(keycode, camera, frame, direction);
	else if (ft_dabs(perform_dot_product(camera->vector, *direction)) == 1)
		handle_dir_c_rotation(keycode, camera, frame, direction);
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
