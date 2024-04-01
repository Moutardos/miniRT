/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:08:05 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/01 09:46:13 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "minirt.h"

void	handle_camera_point(int keycode, t_point *camera_point)
{
	if (keycode == XK_w)
		camera_point->z += STEP;
	if (keycode == XK_s)
		camera_point->z -= STEP;
	if (keycode == XK_d)
		camera_point->x += STEP;
	if (keycode == XK_a)
		camera_point->x -= STEP;
	if (keycode == XK_r)
		camera_point->y += STEP;
	if (keycode == XK_f)
		camera_point->y -= STEP;
}

void	handle_camera(int keycode, t_camera *camera)
{
	handle_camera_point(keycode, &camera->point);
}
