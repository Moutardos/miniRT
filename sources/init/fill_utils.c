/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:31:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/25 23:37:36 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_sphere_utils(t_sphere *sphere, t_camera *camera)
{
	sphere->utils.center_camera = create_vector(sphere->center, camera->point);
	sphere->utils.center_origin
		= create_vector(sphere->center, (t_point){0, 0, 0});
	sphere->utils.center_origin_magnitude
		= get_vector_magnitude(sphere->utils.center_origin);
	sphere->utils.c_const
		= sphere->utils.center_origin_magnitude
		* sphere->utils.center_origin_magnitude
		- (sphere->diameter * sphere->diameter) / 4;
}

void	fill_plane_utils(t_plane *plane, t_camera *camera)
{
	plane->utils.camera_point = create_vector(camera->point, plane->point);
	plane->utils.dot_prod_const
		= perform_dot_product(plane->utils.camera_point, plane->vector);
}

void	fill_utils(t_camera *camera, t_object_array *object_array)
{
	int	object_index;

	camera->utils.co = create_vector(camera->point, (t_point){0, 0, 0});
	object_index = 0;
	while (object_index < object_array->len)
	{
		if (object_array->array[object_index].type == SP)
			fill_sphere_utils(
				&object_array->array[object_index].sphere, camera);
		if (object_array->array[object_index].type == PL)
			fill_plane_utils(&object_array->array[object_index].plane, camera);
		object_index++;
	}
}
