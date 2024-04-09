/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:26:08 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 20:37:30 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_sphere_light_utils(t_sphere *sphere, t_light *light)
{
	double	center_light_magnitude;

	sphere->utils.center_light = create_vector(sphere->center, light->point);
	center_light_magnitude
		= get_vector_magnitude(sphere->utils.center_light);
	sphere->utils.lc_const = center_light_magnitude * center_light_magnitude
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

void	fill_sphere_utils(t_sphere *sphere, t_camera *camera, t_light *light)
{
	fill_sphere_camera_utils(sphere, camera);
	fill_sphere_light_utils(sphere, light);
}
