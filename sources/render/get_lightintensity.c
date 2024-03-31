/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lightintensity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:17:02 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/31 04:27:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_sp_intersecting_light (t_sphere *sphere, t_vector light_direction,
			t_point_info *p_info)
{
	t_quadratic_roots	roots;
	double				t;
	t_vector			op;
	double				c;
	
	op = create_vector(sphere->center, p_info->point);
	c = get_vector_magnitude(op)
		* get_vector_magnitude(op)
		- sphere->utils.radius * sphere->utils.radius;
	roots = solve_quadratic_equation(
			1,
			2 * perform_dot_product(op, normalize_vector(light_direction)),
			c
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_positive_root(&roots);
	return (t < get_vector_magnitude(light_direction) && t > 0.01);
}

static bool	is_there_shadow(t_data *data, t_point_info *p_info,
			t_vector light_direction)
{
	t_object	*other_object;
	int			i;

	i = 0;
	while (i < data->object_array.len)
	{
		other_object = &data->object_array.array[i];
		if (other_object->type == SP)
		{
			if (is_sp_intersecting_light(&other_object->sphere, light_direction,
				p_info))
				return (true);
		}
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
	light_direction = create_vector(p_info->point, data->settings.light.point);
	normal_facing = p_info->normal;
	if (perform_dot_product(normal_facing, p_info->cp) >= 0)
		normal_facing = multiply_vector(-1, normal_facing);
	if (is_there_shadow(data, p_info, light_direction))
		return (global_intensity);
	light_intensity = perform_dot_product(normal_facing, light_direction);
	if (light_intensity > 0)
	{
		light_intensity *= data->settings.light.ratio;
		light_intensity /= get_vector_magnitude(light_direction);
		global_intensity += light_intensity;
	}
	return (global_intensity);
}
