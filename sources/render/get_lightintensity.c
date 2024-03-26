/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lightintensity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:17:02 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/26 23:46:41 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

double	get_lightintensity(t_data *data, t_point_info *p_info)
{
	double		global_intensity;
	double		light_intensity;
	t_vector	light_direction;
	t_vector	normal_facing;

	global_intensity = data->settings.env_light.ratio;
	light_direction = create_vector(p_info->point, data->settings.light.point);
	normal_facing = p_info->normal;
	if (perform_dot_product(normal_facing, p_info->cp) > 0)
		normal_facing = multiply_vector(-1, normal_facing);
	light_intensity = perform_dot_product(normal_facing, light_direction);
	if (light_intensity > 0)
	{
		light_intensity *= data->settings.light.ratio;
		light_intensity /= get_vector_magnitude(light_direction);
		global_intensity += light_intensity;
	}
	return (global_intensity);
}
