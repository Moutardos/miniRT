/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:29:44 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/21 18:13:24 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "libft.h"
#include "minirt.h"

void	handle_rotations(int keycode,
			t_camera *camera, t_frame *frame, t_vector *direction)
{
	t_vector	diag_c_i;
	t_vector	diag_i_j;

	diag_c_i = sum_vectors(camera->vector, frame->dir_i);
	diag_i_j = sum_vectors(frame->dir_i, frame->dir_j);
	if (keycode == XK_Left)
		*direction = normalize_vector(
				sum_vectors(*direction, multiply_vector(-COEF,
						perform_cross_product(diag_c_i, *direction))));
	if (keycode == XK_Right)
		*direction = normalize_vector(
				sum_vectors(*direction, multiply_vector(COEF,
						perform_cross_product(diag_c_i, *direction))));
	if (keycode == XK_Up)
		*direction = normalize_vector(
				sum_vectors(*direction, multiply_vector(COEF,
						perform_cross_product(diag_i_j, *direction))));
	if (keycode == XK_Down)
		*direction = normalize_vector(
				sum_vectors(*direction, multiply_vector(-COEF,
						perform_cross_product(diag_i_j, *direction))));
}

void	handle_camera_rotations(int keycode, t_camera *camera,
			t_frame *frame)
{
	if (keycode == XK_Up)
	{
		camera->vector = normalize_vector(sum_vectors(camera->vector,
					multiply_vector(-COEF, frame->dir_i)));
		frame->dir_i = perform_cross_product(camera->vector, frame->dir_j);
	}
	else if (keycode == XK_Down)
	{
		camera->vector = normalize_vector(sum_vectors(camera->vector,
					multiply_vector(COEF, frame->dir_i)));
		frame->dir_i = perform_cross_product(camera->vector, frame->dir_j);
	}
	else if (keycode == XK_Right)
	{
		camera->vector = normalize_vector(sum_vectors(camera->vector,
					multiply_vector(COEF, frame->dir_j)));
		frame->dir_j = perform_cross_product(frame->dir_i, camera->vector);
	}
	else if (keycode == XK_Left)
	{
		camera->vector = normalize_vector(sum_vectors(camera->vector,
					multiply_vector(-COEF, frame->dir_j)));
		frame->dir_j = perform_cross_product(frame->dir_i, camera->vector);
	}
	frame->origin = get_frame_origin(frame, camera);
}
