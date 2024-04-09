/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lightintensity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:17:02 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 22:32:20 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_there_shadow(t_data *data, t_vector light_direction,
			double light_distance)
{
	t_object	*other_object;
	int			i;
	t_vector	lightray;

	lightray = normalize_vector(light_direction);
	i = 0;
	while (i < data->object_array.len)
	{
		other_object = &data->object_array.array[i];
		if (is_lightray_intersecting_obj(other_object, lightray,
				light_distance))
			return (true);
		i++;
	}
	return (false);
}

double	get_lightintensity(t_data *data, t_point_info *p_info)
{
	double		global_intensity;
	double		dot_prod_nl;
	t_vector	light_direction;
	double		light_distance;
	t_vector	normal_facing;

	global_intensity = data->settings.env_light.ratio;
	normal_facing = p_info->normal;
	if (perform_dot_product(normal_facing, p_info->cp) >= 0)
		normal_facing = multiply_vector(-1, normal_facing);
	light_direction = create_vector(data->settings.light.point, p_info->point);
	light_distance = get_vector_magnitude(light_direction);
	if (is_there_shadow(data, light_direction, light_distance))
		return (global_intensity);
	dot_prod_nl = -perform_dot_product(normal_facing, light_direction);
	if (dot_prod_nl > 0)
		global_intensity
			+= (dot_prod_nl * data->settings.light.ratio)
			/ light_distance;
	return (global_intensity);
}
