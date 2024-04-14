/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sp_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:49:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/14 19:09:20 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_texture_coordinates	get_sp_coord(t_sphere *sphere, t_point point)
{
	double		azimuth_angle;
	double		polar_angle;
	t_point		centered_point;

	if (sphere->utils.radius == 0)
		return ((t_texture_coordinates){0});
	centered_point = translate_point(point,
			create_vector(sphere->center, (t_point){0, 0, 0}));
	azimuth_angle = atan2(centered_point.x, centered_point.z);
	polar_angle = acos(centered_point.y / sphere->utils.radius);
	return ((t_texture_coordinates){
		.x = (azimuth_angle / (2.0 * M_PI) + 0.5),
		.y = (polar_angle / M_PI)
	});
}
