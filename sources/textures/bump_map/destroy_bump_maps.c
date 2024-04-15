/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bump_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:43:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 16:40:21 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_bump_maps(t_object_array *objects, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (objects->array[i].texture.type == BUMP)
		{
			if (*(objects->array[i].texture.bump_map.map) != NULL)
			{
				free(*(objects->array[i].texture.bump_map.map));
				*(objects->array[i].texture.bump_map.map) = NULL;
			}
		}
		i++;
	}
}
