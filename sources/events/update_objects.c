/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:03:33 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 21:20:00 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "libft.h"
#include "minirt.h"

void	update_object_color(t_color *og_color, t_color *object_color)
{
	*og_color = *object_color;
	*object_color = (t_color){
		.r = ft_min(og_color->r + RGB_INCR, 255),
		.g = ft_min(og_color->g + RGB_INCR, 255),
		.b = ft_min(og_color->b + RGB_INCR, 255)
	};
}

void	update_plane_properties(int keycode,
			t_camera *camera, t_frame *frame, t_plane *plane)
{
	handle_translations(keycode, camera, frame, &plane->point);
	handle_rotations(keycode, camera, frame, &plane->vector);
}

void	update_sphere_properties(int keycode,
			t_camera *camera, t_frame *frame, t_sphere *sphere)
{
	handle_translations(keycode, camera, frame, &sphere->center);
	if (keycode == XK_equal)
		sphere->diameter += DIM;
	else if (keycode == XK_minus)
		sphere->diameter = ft_max(0, sphere->diameter - DIM);
}

void	update_cylinder_properties(int keycode,
			t_camera *camera, t_frame *frame, t_cylinder *cylinder)
{
	static int	target_keycode = XK_h;

	if (keycode == target_keycode)
		return ;
	if (keycode == XK_h || keycode == XK_t)
	{
		target_keycode = keycode;
		return ;
	}
	handle_translations(keycode, camera, frame, &cylinder->center);
	handle_rotations(keycode, camera, frame, &cylinder->vector);
	if (target_keycode == XK_h)
	{
		if (keycode == XK_equal)
			cylinder->height += DIM;
		if (keycode == XK_minus)
			cylinder->height = ft_max(0, cylinder->height - DIM);
	}
	else if (target_keycode == XK_t)
	{
		if (keycode == XK_equal)
			cylinder->diameter += DIM;
		if (keycode == XK_minus)
			cylinder->diameter = ft_max(0, cylinder->diameter - DIM);
	}
}
