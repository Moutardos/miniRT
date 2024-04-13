/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_cone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:40:21 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/13 14:36:45 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_cone_tube_camera_utils(t_cone *cone, t_camera *camera)
{
	double	mag_d1_center_camera;
	double	dot_prod_d1_center_camera_dir;
	double	squared_dot_prod_d1_center_camera_dir;

	cone->utils.disk1_center_camera
		= create_vector(cone->utils.disk1_center, camera->point);
	mag_d1_center_camera
		= get_vector_magnitude(cone->utils.disk1_center_camera);
	dot_prod_d1_center_camera_dir
		= perform_dot_product(cone->utils.disk1_center_camera, cone->vector);
	squared_dot_prod_d1_center_camera_dir
		= dot_prod_d1_center_camera_dir * dot_prod_d1_center_camera_dir;
	cone->utils.ca_const = 1 + cone->utils.radius * cone->utils.radius
		/ cone->height * cone->height;
	cone->utils.cb_const
		= -2 * dot_prod_d1_center_camera_dir * cone->utils.ca_const;
	cone->utils.cc_const = mag_d1_center_camera * mag_d1_center_camera
		- squared_dot_prod_d1_center_camera_dir
		* cone->utils.ca_const;
}

void	fill_cone_disks_utils(t_cone *cone)
{
	t_vector	co_center_disk1_center;
	double		halved_height;

	cone->utils.radius = cone->diameter / 2;
	halved_height = cone->height / 2;
	co_center_disk1_center
		= multiply_vector(halved_height, cone->vector);
	cone->utils.disk1_center
		= translate_point(cone->center, co_center_disk1_center);
}

void	fill_cone_utils(t_cone *cone,
			t_camera *camera)
{
	fill_cone_disks_utils(cone);
	fill_cone_tube_camera_utils(cone, camera);
}
