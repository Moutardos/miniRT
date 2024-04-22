/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_co_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:55:06 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 02:26:34 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include "minirt.h"

t_texture_coordinates	get_co_coord(t_cone *cone, t_point_info *point_info)
{
	double		azimuth_angle;
	t_vector	projected_position;
	double		y;
	double		x;

	if (are_doubles_equals(
			ft_dabs(perform_dot_product(point_info->normal, cone->vector)), 1))
		return (get_pl_coord(&cone->utils.induced_plane2, point_info));
	projected_position = rotate_vector_upside(cone->vector,
			point_info->point, cone->center);
	azimuth_angle = atan2(projected_position.x, projected_position.z);
	x = azimuth_angle / (2.0 * M_PI) + 0.5;
	y = (2 * projected_position.y + cone->height) / (2 * cone->height);
	return ((t_texture_coordinates){
		.x = x,
		.y = y
	});
}
