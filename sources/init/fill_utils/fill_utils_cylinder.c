/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:29:04 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 19:00:52 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_cylinder_tube_light_utils(t_cylinder *cylinder, t_light *light)
{
	double	mag_center_light;
	double	squared_mag_center_light;
	double	dot_prod_center_light_dir;
	double	squared_dot_prod_center_light_dir;

	cylinder->utils.light_utils->center_light
		= create_vector(cylinder->center, light->point);
	mag_center_light = get_vector_magnitude(
			cylinder->utils.light_utils->center_light);
	squared_mag_center_light = mag_center_light * mag_center_light;
	dot_prod_center_light_dir
		= perform_dot_product(
			cylinder->utils.light_utils->center_light,
			cylinder->vector);
	squared_dot_prod_center_light_dir
		= dot_prod_center_light_dir * dot_prod_center_light_dir;
	cylinder->utils.light_utils->lc_const
		= -squared_dot_prod_center_light_dir
		+ squared_mag_center_light
		- (cylinder->utils.radius * cylinder->utils.radius);
	cylinder->utils.light_utils->lp_const
		= dot_prod_center_light_dir;
}

void	fill_cylinder_tube_camera_utils(t_cylinder *cylinder, t_camera *camera)
{
	double	mag_center_camera;
	double	squared_mag_center_camera;
	double	dot_prod_center_camera_dir;
	double	squared_dot_prod_center_camera_dir;

	cylinder->utils.center_camera
		= create_vector(cylinder->center, camera->point);
	mag_center_camera = get_vector_magnitude(cylinder->utils.center_camera);
	squared_mag_center_camera = mag_center_camera * mag_center_camera;
	dot_prod_center_camera_dir
		= perform_dot_product(cylinder->utils.center_camera, cylinder->vector);
	squared_dot_prod_center_camera_dir
		= dot_prod_center_camera_dir * dot_prod_center_camera_dir;
	cylinder->utils.cc_const
		= -squared_dot_prod_center_camera_dir
		+ squared_mag_center_camera
		- (cylinder->utils.radius * cylinder->utils.radius);
	cylinder->utils.cp_const = dot_prod_center_camera_dir;
}

void	fill_cylinder_disks_utils(t_cylinder *cylinder,
			t_camera *camera, t_light_array *light_array)
{
	t_vector	cy_center_disk1_center;
	t_vector	cy_center_disk2_center;

	cylinder->utils.halved_height = cylinder->height / 2;
	cylinder->utils.radius = cylinder->diameter / 2;
	cy_center_disk1_center
		= multiply_vector(cylinder->utils.halved_height, cylinder->vector);
	cy_center_disk2_center = multiply_vector(-1, cy_center_disk1_center);
	cylinder->utils.disk1_center
		= translate_point(cylinder->center, cy_center_disk1_center);
	cylinder->utils.disk2_center
		= translate_point(cylinder->center, cy_center_disk2_center);
	cylinder->utils.induced_plane1.point = cylinder->utils.disk1_center;
	cylinder->utils.induced_plane2.point = cylinder->utils.disk2_center;
	cylinder->utils.induced_plane1.vector = cylinder->vector;
	cylinder->utils.induced_plane2.vector
		= multiply_vector(-1, cylinder->vector);
	fill_plane_utils(&cylinder->utils.induced_plane1, camera, light_array);
	fill_plane_utils(&cylinder->utils.induced_plane2, camera, light_array);
}

void	fill_cylinder_utils(t_cylinder *cylinder,
			t_camera *camera, t_light_array *light_array)
{
	int	i;

	i = 0;
	fill_cylinder_disks_utils(cylinder, camera, light_array);
	fill_cylinder_tube_camera_utils(cylinder, camera);
	while (i < light_array->len)
	{
		cylinder->utils.light_utils = &cylinder->utils
			.light_utils_array.array[i];
		fill_cylinder_tube_light_utils(cylinder, &light_array->array[i]);
		i++;
	}
}
