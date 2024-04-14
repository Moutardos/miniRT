/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_objects_properties.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:03:33 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 15:31:21 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "libft.h"
#include "minirt.h"

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

void	update_cone_properties(int keycode,
			t_camera *camera, t_frame *frame, t_cone *cone)
{
	static int	target_keycode = XK_h;

	if (keycode == target_keycode)
		return ;
	if (keycode == XK_h || keycode == XK_t)
	{
		target_keycode = keycode;
		return ;
	}
	handle_translations(keycode, camera, frame, &cone->center);
	handle_rotations(keycode, camera, frame, &cone->vector);
	if (target_keycode == XK_h)
	{
		if (keycode == XK_equal)
			cone->height += DIM;
		if (keycode == XK_minus)
			cone->height = ft_max(0, cone->height - DIM);
	}
	else if (target_keycode == XK_t)
	{
		if (keycode == XK_equal)
			cone->diameter += DIM;
		if (keycode == XK_minus)
			cone->diameter = ft_max(0, cone->diameter - DIM);
	}
}

void	update_object_properties(int keycode,
			t_camera *camera, t_frame *frame, t_object *object)
{
	if (object->type == PL)
		update_plane_properties(keycode, camera,
			frame, &object->plane);
	else if (object->type == SP)
		update_sphere_properties(keycode, camera,
			frame, &object->sphere);
	else if (object->type == CY)
		update_cylinder_properties(keycode, camera,
			frame, &object->cylinder);
	else if (object->type == CO)
		update_cone_properties(keycode, camera,
			frame, &object->cone);
}
