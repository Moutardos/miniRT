/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:36:31 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 18:02:57 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_sphere_utils_l(t_sphere *sphere, t_light *light)
{
	sphere->utils.center_light = create_vector(sphere->center, light->point);
	sphere->utils.center_light_magnitude
		= get_vector_magnitude(sphere->utils.center_light);
	sphere->utils.l_const
		= sphere->utils.center_light_magnitude
		* sphere->utils.center_light_magnitude
		- sphere->utils.radius * sphere->utils.radius;
}

void	fill_plane_utils_l(t_plane *plane, t_light *light)
{
	plane->utils.light_point = create_vector(plane->point, light->point);
	plane->utils.dot_prod_const_l
		= -perform_dot_product(plane->utils.light_point, plane->vector);
}

void	fill_cylinder_tube_utils_l(t_cylinder *cylinder, t_light *light)
{
	double	mag_center_light;
	double	squared_mag_center_light;
	double	dot_prod_center_light_dir;
	double	squared_dot_prod_center_light_dir;

	cylinder->utils.center_light
		= create_vector(cylinder->center, light->point);
	mag_center_light = get_vector_magnitude(cylinder->utils.center_light);
	squared_mag_center_light = mag_center_light * mag_center_light;
	dot_prod_center_light_dir
		= perform_dot_product(cylinder->utils.center_light, cylinder->vector);
	squared_dot_prod_center_light_dir
		= dot_prod_center_light_dir * dot_prod_center_light_dir;
	cylinder->utils.lc_const
		= -squared_dot_prod_center_light_dir
		+ squared_mag_center_light
		- (cylinder->utils.radius * cylinder->utils.radius);
	cylinder->utils.lp_const = dot_prod_center_light_dir;
}

void	fill_cylinder_disk_utils_l(t_cylinder *cylinder, t_light *light)
{
	fill_plane_utils_l(&cylinder->utils.induced_plane1, light);
	fill_plane_utils_l(&cylinder->utils.induced_plane2, light);
}

void	fill_utils_light(t_light *light, t_object_array *object_array)
{
	int	object_index;

	object_index = 0;
	while (object_index < object_array->len)
	{
		if (object_array->array[object_index].type == SP)
			fill_sphere_utils_l(
				&object_array->array[object_index].sphere, light);
		if (object_array->array[object_index].type == PL)
			fill_plane_utils_l(
				&object_array->array[object_index].plane, light);
		if (object_array->array[object_index].type == CY)
		{
			fill_cylinder_tube_utils_l(
				&object_array->array[object_index].cylinder, light);
			fill_cylinder_disk_utils_l(
				&object_array->array[object_index].cylinder, light);
		}
		object_index++;
	}
}
