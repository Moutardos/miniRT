/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:31:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/26 05:16:22 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_sphere_utils(t_sphere *sphere, t_camera *camera)
{
	sphere->utils.radius = sphere->diameter / 2;
	sphere->utils.center_camera = create_vector(sphere->center, camera->point);
	sphere->utils.center_origin
		= create_vector(sphere->center, (t_point){0, 0, 0});
	sphere->utils.center_origin_magnitude
		= get_vector_magnitude(sphere->utils.center_origin);
	sphere->utils.c_const
		= sphere->utils.center_origin_magnitude
		* sphere->utils.center_origin_magnitude
		- sphere->utils.radius * sphere->utils.radius;
}

void	fill_plane_utils(t_plane *plane, t_camera *camera)
{
	plane->utils.camera_point = create_vector(camera->point, plane->point);
	plane->utils.dot_prod_const
		= perform_dot_product(plane->utils.camera_point, plane->vector);
}

void	fill_cylinder_disks_utils(t_cylinder *cylinder)
{
	cylinder->utils.halved_height = cylinder->height / 2;
	cylinder->utils.radius = cylinder->diameter / 2;
}

void	fill_cylinder_tube_utils(t_cylinder *cylinder, t_camera *camera)
{
	double	mag_center_camera;
	double	squared_mag_center_camera;
	double	mag_dir;
	double	dot_prod_center_camera_dir;
	double	squared_dot_prod_center_camera_dir;

	cylinder->utils.center_camera
		= create_vector(camera->point, cylinder->center);
	mag_center_camera = get_vector_magnitude(cylinder->utils.center_camera);
	squared_mag_center_camera = mag_center_camera * mag_center_camera;
	mag_dir = get_vector_magnitude(cylinder->vector);
	cylinder->utils.squared_mag_dir = mag_dir * mag_dir;
	cylinder->utils.dsquared_mag_dir
		= cylinder->utils.squared_mag_dir * cylinder->utils.squared_mag_dir;
	dot_prod_center_camera_dir
		= perform_dot_product(cylinder->utils.center_camera, cylinder->vector);
	squared_dot_prod_center_camera_dir
		= dot_prod_center_camera_dir * dot_prod_center_camera_dir;
	cylinder->utils.c_const
		= squared_dot_prod_center_camera_dir / cylinder->utils.dsquared_mag_dir
		+ 2 * squared_dot_prod_center_camera_dir
		/ cylinder->utils.squared_mag_dir + squared_mag_center_camera
		- (cylinder->diameter * cylinder->diameter) / 4;
	cylinder->utils.p_const
		= dot_prod_center_camera_dir / cylinder->utils.squared_mag_dir;
}

void	fill_utils(t_camera *camera, t_object_array *object_array)
{
	int	object_index;

	camera->utils.co = create_vector(camera->point, (t_point){0, 0, 0});
	object_index = 0;
	while (object_index < object_array->len)
	{
		if (object_array->array[object_index].type == SP)
			fill_sphere_utils(
				&object_array->array[object_index].sphere, camera);
		if (object_array->array[object_index].type == PL)
			fill_plane_utils(&object_array->array[object_index].plane, camera);
		if (object_array->array[object_index].type == CY)
		{
			fill_cylinder_tube_utils(
				&object_array->array[object_index].cylinder, camera);
			fill_cylinder_disks_utils(
				&object_array->array[object_index].cylinder);
		}
		object_index++;
	}
}
