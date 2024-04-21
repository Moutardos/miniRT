/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_shader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:17:02 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/21 21:12:00 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

static double	phong_reflection(t_vector normal_facing,
				t_vector light_direction, t_point_info *p_info, double ratio)
{
	t_vector	reflected_light;
	double		dot_prod_rv;

	reflected_light
		= sum_vectors(multiply_vector(2, multiply_vector(
					-perform_dot_product(normal_facing, light_direction),
					normal_facing)),
			light_direction);
	dot_prod_rv = perform_dot_product(reflected_light, p_info->pc);
	if (dot_prod_rv > 0)
	{
		return (
			ratio * pow(
				dot_prod_rv
				/ (get_vector_magnitude(reflected_light)
					* p_info->cp_magnitude),
				SPECULARITY)
		);
	}
	return (0);
}

static bool	is_there_shadow(t_data *data, t_vector light_direction,
			double light_distance, int light_index)
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
				light_distance, light_index))
			return (true);
		i++;
	}
	return (false);
}

void	treat_light(t_light *light, t_color_intensity color_intensity,
		t_point_info *p_info, t_vector light_direction)
{
	double		dot_prod_nl;
	double		light_intensity;

	dot_prod_nl = -perform_dot_product(p_info->surface_normal, light_direction);
	if (dot_prod_nl > 0)
	{
		light_intensity
			= light->ratio * dot_prod_nl
			/ get_vector_magnitude(light_direction)
			+ phong_reflection(p_info->surface_normal, light_direction, p_info,
				light->ratio);
		get_colored_intensity(color_intensity, light->color,
			light_intensity);
	}
}

void	apply_shader(t_color *point_color, t_data *data,
		t_point_info *p_info)
{
	int					i;
	t_light_array		*lights;
	t_color_intensity	color_intensity;
	t_vector			light_direction;
	double				light_distance;

	i = 0;
	init_color_intensity(color_intensity);
	get_colored_intensity(color_intensity, data->settings.env_light.color,
		data->settings.env_light.ratio);
	lights = &data->settings.light_array;
	get_surface_normal(p_info);
	while (i < lights->len)
	{
		light_direction = create_vector(lights->array[i].point,
				p_info->point);
		light_distance = get_vector_magnitude(light_direction);
		if (!is_there_shadow(data, light_direction, light_distance, i))
		{
			treat_light(&lights->array[i], color_intensity, p_info,
				light_direction);
		}
		i++;
	}
	intensify_color(point_color, color_intensity);
}
