/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:36:31 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/05 19:44:34 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_sphere_utils_l(t_sphere *sphere, t_light *light)
{
	sphere->utils.center_light = create_vector(light->point, sphere->center);
	sphere->utils.center_light_magnitude
		= get_vector_magnitude(sphere->utils.center_light);
	sphere->utils.l_const = 
		sphere->utils.center_light_magnitude
		* sphere->utils.center_light_magnitude
		- sphere->utils.radius * sphere->utils.radius;
}

void	fill_utils_light(t_light *light, t_object_array *object_array)
{
	int	object_index;

	object_index = 0;
	while (object_index < object_array->len)
	{
		if (object_array->array[object_index].type == SP)
			fill_sphere_utils_l(
				&object_array->array[object_index].sphere, light);
		object_index++;
	}
}
