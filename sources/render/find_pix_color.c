/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:35:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/25 23:58:55 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	find_pix_color(unsigned int i, unsigned int j, t_data *data)
{
	t_vector	ray;
	int			object_index;

	ray = compute_ray(i, j, &data->settings.camera, &data->frame);
	object_index = 0;
	while (object_index < data->object_array.len)
	{
		if (is_ray_intersecting_obj(
				data->object_array.array + object_index, ray))
		{
			;
		}
		object_index++;
	}
}
