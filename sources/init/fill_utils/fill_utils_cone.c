/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_cone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:40:21 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 18:59:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_cone_tube_light_utils(t_cone *cone, t_light *light)
{
	double				mag_d1_center_light;
	double				squared_dot_prod_d1_center_light_dir;

	cone->utils.light_utils->disk1_center_light
		= create_vector(cone->utils.disk1_center, light->point);
	mag_d1_center_light
		= get_vector_magnitude(cone->utils.light_utils->disk1_center_light);
	cone->utils.light_utils->dot_prod_disk1_center_light_dir
		= perform_dot_product(
			cone->utils.light_utils->disk1_center_light, cone->vector);
	squared_dot_prod_d1_center_light_dir
		= cone->utils.light_utils->dot_prod_disk1_center_light_dir
		* cone->utils.light_utils->dot_prod_disk1_center_light_dir;
	cone->utils.light_utils->la_const
		= 1 + (cone->utils.radius * cone->utils.radius)
		/ (cone->height * cone->height);
	cone->utils.light_utils->lb_const
		= -2 * cone->utils.light_utils->dot_prod_disk1_center_light_dir
		* cone->utils.ca_const;
	cone->utils.light_utils->lc_const
		= mag_d1_center_light * mag_d1_center_light
		- squared_dot_prod_d1_center_light_dir
		* cone->utils.ca_const;
}

void	fill_cone_tube_camera_utils(t_cone *cone, t_camera *camera)
{
	double	mag_d1_center_camera;
	double	squared_dot_prod_d1_center_camera_dir;

	cone->utils.disk1_center_camera
		= create_vector(cone->utils.disk1_center, camera->point);
	mag_d1_center_camera
		= get_vector_magnitude(cone->utils.disk1_center_camera);
	cone->utils.dot_prod_disk1_center_camera_dir
		= perform_dot_product(cone->utils.disk1_center_camera, cone->vector);
	squared_dot_prod_d1_center_camera_dir
		= cone->utils.dot_prod_disk1_center_camera_dir
		* cone->utils.dot_prod_disk1_center_camera_dir;
	cone->utils.ca_const = 1 + (cone->utils.radius * cone->utils.radius)
		/ (cone->height * cone->height);
	cone->utils.cb_const
		= -2 * cone->utils.dot_prod_disk1_center_camera_dir
		* cone->utils.ca_const;
	cone->utils.cc_const = mag_d1_center_camera * mag_d1_center_camera
		- squared_dot_prod_d1_center_camera_dir
		* cone->utils.ca_const;
}

void	fill_cone_disks_utils(t_cone *cone,
			t_camera *camera, t_light_array *light_array)
{
	t_vector	co_center_disk1_center;
	t_vector	co_center_disk2_center;
	double		halved_height;

	cone->utils.radius = cone->diameter / 2;
	halved_height = cone->height / 2;
	co_center_disk1_center
		= multiply_vector(halved_height, cone->vector);
	co_center_disk2_center = multiply_vector(-1, co_center_disk1_center);
	cone->utils.disk1_center
		= translate_point(cone->center, co_center_disk1_center);
	cone->utils.disk2_center
		= translate_point(cone->center, co_center_disk2_center);
	cone->utils.induced_plane2.point = cone->utils.disk2_center;
	cone->utils.induced_plane2.vector
		= multiply_vector(-1, cone->vector);
	fill_plane_utils(&cone->utils.induced_plane2, camera, light_array);
}

void	fill_cone_utils(t_cone *cone,
			t_camera *camera, t_light_array *light_array)
{
	int	i;

	i = 0;
	fill_cone_disks_utils(cone, camera, light_array);
	fill_cone_tube_camera_utils(cone, camera);
	while (i < light_array->len)
	{
		cone->utils.light_utils = &cone->utils.light_utils_array.array[i];
		fill_cone_tube_light_utils(cone, &light_array->array[i]);
		i++;
	}
}
