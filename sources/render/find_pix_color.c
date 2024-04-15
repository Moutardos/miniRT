/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:35:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/15 00:23:04 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	color_object_point(unsigned int i, unsigned int j,
			t_data *data, t_point_info *point_info)
{
	t_color	point_color;

	point_info->pc = multiply_vector(-1, point_info->cp);
	point_color = get_point_color(point_info);
	apply_shader(&point_color, data, point_info);
	color_img_pix(&data->mlx_info.img, j, i, point_color.hex);
}

void	color_point(unsigned int i, unsigned int j, t_data *data,
			t_point_info *point_info)
{
	if (point_info->cp_magnitude != -1)
	{
		point_info->point
			= translate_point(data->settings.camera.point, point_info->cp);
		color_object_point(i, j, data, point_info);
	}
	else
		color_img_pix(&data->mlx_info.img, j, i, BLACK);
}

void	find_pix_color(unsigned int i, unsigned int j, t_data *data)
{
	t_vector		ray;
	int				object_index;
	t_point_info	nearest_point_info;
	t_point_info	current_point_info;

	init_point_info(&nearest_point_info);
	ray = compute_ray(i, j, &data->settings.camera, &data->frame);
	object_index = 0;
	while (object_index < data->object_array.len)
	{
		init_point_info(&current_point_info);
		if (is_camray_intersecting_obj(data->object_array.array + object_index,
				ray, &current_point_info))
		{
			if (nearest_point_info.cp_magnitude == -1
				|| (current_point_info.cp_magnitude
					< nearest_point_info.cp_magnitude))
				nearest_point_info = current_point_info;
		}
		object_index++;
	}
	color_point(i, j, data, &nearest_point_info);
}
