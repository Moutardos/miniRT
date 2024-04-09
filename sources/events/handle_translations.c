/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_translations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:29:32 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 12:51:53 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "minirt.h"

void	handle_translations(int keycode,
			t_camera *camera, t_frame *frame, t_point *point)
{
	if (keycode == XK_w)
		*point = translate_point(*point,
				multiply_vector(STEP, camera->vector));
	else if (keycode == XK_s)
		*point = translate_point(*point,
				multiply_vector(-STEP, camera->vector));
	else if (keycode == XK_d)
		*point = translate_point(*point,
				multiply_vector(STEP, frame->dir_j));
	else if (keycode == XK_a)
		*point = translate_point(*point,
				multiply_vector(-STEP, frame->dir_j));
	else if (keycode == XK_r)
		*point = translate_point(*point,
				multiply_vector(-STEP, frame->dir_i));
	else if (keycode == XK_f)
		*point = translate_point(*point,
				multiply_vector(STEP, frame->dir_i));
}

void	handle_camera_translations(int keycode, t_camera *camera,
			t_frame *frame)
{
	if (keycode == XK_w)
		camera->point = translate_point(camera->point, camera->vector);
	if (keycode == XK_s)
		camera->point = translate_point(camera->point,
				multiply_vector(-1, camera->vector));
	if (keycode == XK_d)
		camera->point = translate_point(camera->point, frame->dir_j);
	if (keycode == XK_a)
		camera->point = translate_point(camera->point,
				multiply_vector(-1, frame->dir_j));
	if (keycode == XK_f)
		camera->point = translate_point(camera->point, frame->dir_i);
	if (keycode == XK_r)
		camera->point = translate_point(camera->point,
				multiply_vector(-1, frame->dir_i));
	frame->origin = get_frame_origin(frame, camera);
}
