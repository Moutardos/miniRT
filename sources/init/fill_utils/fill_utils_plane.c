/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:23:16 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 20:37:21 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_plane_light_utils(t_plane *plane, t_light *light)
{
	plane->utils.point_light = create_vector(plane->point, light->point);
	plane->utils.dot_prod_const_light
		= -perform_dot_product(plane->utils.point_light, plane->vector);
}

void	fill_plane_camera_utils(t_plane *plane, t_camera *camera)
{
	plane->utils.point_camera = create_vector(plane->point, camera->point);
	plane->utils.dot_prod_const_camera
		= -perform_dot_product(plane->utils.point_camera, plane->vector);
}

void	fill_plane_utils(t_plane *plane, t_camera *camera, t_light *light)
{
	fill_plane_camera_utils(plane, camera);
	fill_plane_light_utils(plane, light);
}
