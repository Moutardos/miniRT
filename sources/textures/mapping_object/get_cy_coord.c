/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cy_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:50:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 02:29:17 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "minirt.h"

t_texture_coordinates	get_cy_coord(t_cylinder *cylinder,
						t_point_info *point_info)
{
	double		azimuth_angle;
	t_vector	projected_position;
	double		y;
	double		x;

	if (are_doubles_equals(ft_dabs(perform_dot_product(point_info->normal,
					cylinder->vector)), 1))
		return (get_pl_coord(&cylinder->utils.induced_plane1, point_info));
	projected_position = rotate_vector_upside(
			cylinder->vector, point_info->point, cylinder->center);
	azimuth_angle = atan2(projected_position.x, projected_position.z);
	x = (azimuth_angle / (2.0 * M_PI) + 0.5);
	y = (2 * projected_position.y + cylinder->height) / (2 * cylinder->height);
	return ((t_texture_coordinates){
		.x = x,
		.y = y
	});
}
