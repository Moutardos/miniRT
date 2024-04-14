/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:26:08 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 17:28:36 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_sphere_light_utils(t_sphere *sphere, t_light *light)
{
	double	center_light_magnitude;

	sphere->utils.light_utils->center_light
		= create_vector(sphere->center, light->point);
	center_light_magnitude
		= get_vector_magnitude(
			sphere->utils.light_utils->center_light);
	sphere->utils.light_utils->lc_const 
		= center_light_magnitude * center_light_magnitude
		- sphere->utils.radius * sphere->utils.radius;
}

void	fill_sphere_camera_utils(t_sphere *sphere, t_camera *camera)
{
	double	center_camera_magnitude;

	sphere->utils.radius = sphere->diameter / 2;
	sphere->utils.center_camera = create_vector(sphere->center, camera->point);
	center_camera_magnitude
		= get_vector_magnitude(sphere->utils.center_camera);
	sphere->utils.cc_const = center_camera_magnitude * center_camera_magnitude
		- sphere->utils.radius * sphere->utils.radius;
}

void	fill_sphere_utils(t_sphere *sphere, t_camera *camera,
		t_light_array *light_array)
{
	int	i;

	i = 0;
	fill_sphere_camera_utils(sphere, camera);
	while (i < light_array->len)
	{
		sphere->utils.light_utils = &sphere->utils.light_utils_array.array[i];
		fill_sphere_light_utils(sphere, &light_array->array[i]);
		i++;
	}
}
