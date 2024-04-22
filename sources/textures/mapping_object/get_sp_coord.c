/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sp_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:49:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 02:27:25 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_texture_coordinates	get_sp_coord(t_sphere *sphere, t_point_info *point_info)
{
	double		azimuth_angle;
	double		polar_angle;
	t_vector	projected_position;

	projected_position = rotate_vector_upside(
			(t_vector){0, 1, 0}, point_info->point, sphere->center);
	azimuth_angle = atan2(projected_position.x, projected_position.z);
	polar_angle = acos(projected_position.y / sphere->utils.radius);
	return ((t_texture_coordinates){
		.x = (azimuth_angle / (2.0 * M_PI) + 0.5),
		.y = (polar_angle / M_PI)
	});
}
