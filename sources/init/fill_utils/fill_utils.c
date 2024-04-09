/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:31:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 18:36:08 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_utils(t_camera *camera, t_light *light,
			t_object_array *object_array)
{
	int	object_index;

	object_index = 0;
	while (object_index < object_array->len)
	{
		if (object_array->array[object_index].type == SP)
			fill_sphere_utils(&object_array->array[object_index].sphere,
				camera, light);
		if (object_array->array[object_index].type == PL)
			fill_plane_utils(&object_array->array[object_index].plane,
				camera, light);
		if (object_array->array[object_index].type == CY)
			fill_cylinder_utils(&object_array->array[object_index].cylinder,
				camera, light);
		object_index++;
	}
}
