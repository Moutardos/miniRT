/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cy_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:50:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/21 21:16:06 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_texture_coordinates	get_cy_coord(t_cylinder *cylinder,
						t_point_info *point_info)
{
	double		azimuth_angle;
	t_point		centered_point;
	double		y;
	double		x;

	centered_point = translate_point(point_info->point,
			create_vector(cylinder->center, (t_point){0, 0, 0}));
	centered_point = rotate_point(centered_point, cylinder->vector);
	azimuth_angle = atan2(centered_point.x, centered_point.z);
	x = (azimuth_angle / (2.0 * M_PI) + 0.5);
	y = (2 * centered_point.y + cylinder->height) / (2 * cylinder->height);
	return ((t_texture_coordinates){
		.x = x,
		.y = y
	});
}
