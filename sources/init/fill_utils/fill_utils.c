/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:31:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 17:39:05 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_utils(t_camera *camera, t_light_array *light_array,
			t_object_array *object_array)
{
	int	object_index;

	object_index = 0;
	while (object_index < object_array->len)
	{
		if (object_array->array[object_index].type == SP)
			fill_sphere_utils(&object_array->array[object_index].sphere,
				camera, light_array);
		if (object_array->array[object_index].type == PL)
			fill_plane_utils(&object_array->array[object_index].plane,
				camera, light_array);
		if (object_array->array[object_index].type == CY)
			fill_cylinder_utils(&object_array->array[object_index].cylinder,
				camera, light_array);
		if (object_array->array[object_index].type == CO)
			fill_cone_utils(&object_array->array[object_index].cone,
				camera, light_array);
		object_index++;
	}
}
