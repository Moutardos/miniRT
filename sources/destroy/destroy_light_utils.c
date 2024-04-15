/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_light_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:49:17 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 16:50:33 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_light_utils(t_object_array *objects, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (objects->array[i].type == SP)
			free(objects->array[i].sphere.utils.light_utils_array.array);
		else if (objects->array[i].type == PL)
			free(objects->array[i].plane.utils.light_utils_array.array);
		else if (objects->array[i].type == CY)
		{
			free(objects->array[i].cylinder.utils.light_utils_array.array);
			free(objects->array[i].cylinder.utils.induced_plane1
				.utils.light_utils_array.array);
			free(objects->array[i].cylinder.utils.induced_plane2
				.utils.light_utils_array.array);
		}
		else
		{
			free(objects->array[i].cone.utils.light_utils_array.array);
			free(objects->array[i].cone.utils.induced_plane2
				.utils.light_utils_array.array);
		}
		i++;
	}
}
