/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:23:16 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 17:28:17 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_plane_light_utils(t_plane *plane, t_light *light)
{
	plane->utils.light_utils->point_light
		= create_vector(plane->point, light->point);
	plane->utils.light_utils->dot_prod_const_light
		= -perform_dot_product(
			plane->utils.light_utils->point_light,
			plane->vector);
}

void	fill_plane_camera_utils(t_plane *plane, t_camera *camera)
{
	plane->utils.point_camera = create_vector(plane->point, camera->point);
	plane->utils.dot_prod_const_camera
		= -perform_dot_product(plane->utils.point_camera, plane->vector);
}

void	fill_plane_utils(t_plane *plane, t_camera *camera,
		t_light_array *light_array)
{
	int	i;

	i = 0;
	fill_plane_camera_utils(plane, camera);
	while (i < light_array->len)
	{
		plane->utils.light_utils = &plane->utils.light_utils_array.array[i];
		fill_plane_light_utils(plane, &light_array->array[i]);
		i++;
	}
}
