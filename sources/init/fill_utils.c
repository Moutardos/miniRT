/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:31:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/04 06:52:31 by ekhaled          ###   ########.fr       */
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

void	fill_cylinder_disks_utils(t_cylinder *cylinder, t_camera *camera)
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
	fill_plane_utils(&cylinder->utils.induced_plane1, camera);
	fill_plane_utils(&cylinder->utils.induced_plane2, camera);
	cylinder->utils.disk1_center_camera
		= create_vector(cylinder->utils.disk1_center, camera->point);
	cylinder->utils.disk2_center_camera
		= create_vector(cylinder->utils.disk2_center, camera->point);
}

void	fill_cylinder_tube_utils(t_cylinder *cylinder, t_camera *camera)
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
	cylinder->utils.c_const
		= -squared_dot_prod_center_camera_dir
		+ squared_mag_center_camera
		- (cylinder->utils.radius * cylinder->utils.radius);
	cylinder->utils.p_const = dot_prod_center_camera_dir;
}

void	fill_utils(t_camera *camera, t_object_array *object_array)
{
	int	object_index;

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
			fill_cylinder_disks_utils(
				&object_array->array[object_index].cylinder, camera);
			fill_cylinder_tube_utils(
				&object_array->array[object_index].cylinder, camera);
		}
		object_index++;
	}
}
