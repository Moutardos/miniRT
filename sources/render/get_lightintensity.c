/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lightintensity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:17:02 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/08 12:26:12 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_there_shadow(t_data *data,
			t_vector light_direction, t_point_info *point_info)
{
	t_object	*other_object;
	int			i;
	t_vector	lightray;
	double		t_max;

	lightray = normalize_vector(light_direction);
	t_max = get_vector_magnitude(light_direction);
	i = 0;
	while (i < data->object_array.len)
	{
		other_object = &data->object_array.array[i];
		if (other_object != point_info->object
			&& is_obj_intersecting_light(other_object, lightray,
				t_max))
			return (true);
		i++;
	}
	return (false);
}

double	get_lightintensity(t_data *data, t_point_info *p_info)
{
	double		global_intensity;
	double		light_intensity;
	t_vector	light_direction;
	t_vector	normal_facing;

	global_intensity = data->settings.env_light.ratio;
	normal_facing = p_info->normal;
	if (perform_dot_product(normal_facing, p_info->cp) >= 0)
		normal_facing = multiply_vector(-1, normal_facing);
	light_direction = create_vector(data->settings.light.point, p_info->point);
	fill_utils_light(&data->settings.light, &data->object_array);
	if (is_there_shadow(data, light_direction, p_info))
		return (global_intensity);
	light_intensity = -perform_dot_product(normal_facing, light_direction);
	if (light_intensity > 0)
	{
		light_intensity *= data->settings.light.ratio;
		light_intensity /= get_vector_magnitude(light_direction);
		global_intensity += light_intensity;
	}
	return (global_intensity);
}
