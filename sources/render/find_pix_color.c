/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:35:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/26 21:16:05 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	find_pix_color(unsigned int i, unsigned int j, t_data *data)
{
	t_vector		ray;
	int				object_index;
	t_point_info	nearest_point_info;
	t_point_info	current_point_info;

	current_point_info = (t_point_info){0};
	nearest_point_info = current_point_info;
	ray = compute_ray(i, j, &data->settings.camera, &data->frame);
	object_index = 0;
	while (object_index < data->object_array.len)
	{
		if (is_ray_intersecting_obj(data->object_array.array + object_index,
				ray, &current_point_info))
		{
			if (nearest_point_info.cp_magnitude == 0
				|| (current_point_info.cp_magnitude
					< nearest_point_info.cp_magnitude))
			{
				current_point_info.object
					= data->object_array.array + object_index;
				nearest_point_info = current_point_info;
			}
		}
		object_index++;
	}
	if (nearest_point_info.object)
	{
		nearest_point_info.point
			= translate_point(data->settings.camera.point, nearest_point_info.cp);
		;
	}
}
