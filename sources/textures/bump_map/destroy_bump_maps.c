/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bump_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:43:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/19 18:43:44 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "minirt.h"

void	destroy_bump_maps(t_data *data, t_object_array *objects, int len)
{
	int			i;
	t_bump_map	*node;
	t_bump_map	*prev_node;

	i = 0;
	while (i < len)
	{
		if (objects->array[i].texture.bump_maps
			&& *(objects->array[i].texture.bump_maps) != NULL)
		{
			node = *(objects->array[i].texture.bump_maps);
			while (node)
			{
				free(node->path_name);
				mlx_destroy_image(data->mlx_info.mlx_ptr, node->img.img_ptr);
				free(node->map);
				prev_node = node;
				node = node->next;
				free(prev_node);
			}
			*(objects->array[i].texture.bump_maps) = NULL;
			return ;
		}
		i++;
	}
}
