/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:53:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 16:49:06 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_light_utils(t_object_array *objects, t_light_array *lights)
{
	int			i;

	i = -1;
	while (++i < objects->len)
	{
		if (objects->array[i].type == PL)
		{
			if (init_light_utils_pl(&objects->array[i].plane, lights->len))
				return (destroy_light_utils(objects, i), 1);
		}
		else if (objects->array[i].type == SP)
		{
			if (init_light_utils_sp(&objects->array[i].sphere, lights->len))
				return (destroy_light_utils(objects, i), 1);
		}
		else if (objects->array[i].type == CO)
		{
			if (init_light_utils_co(&objects->array[i].cone, lights->len))
				return (destroy_light_utils(objects, i), 1);
		}
		else
			if (init_light_utils_cy(&objects->array[i].cylinder, lights->len))
				return (destroy_light_utils(objects, i), 1);
	}
	return (0);
}
