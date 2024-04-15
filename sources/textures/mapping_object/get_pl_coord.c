/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pl_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:50:27 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 02:40:15 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "minirt.h"

t_texture_coordinates	get_pl_coord(t_plane *plane, t_point_info *point_info)
{
	t_point	centered_point;
	double	x;
	double	y;

	centered_point = translate_point(point_info->point,
			create_vector(plane->point, (t_point){0, 0, 0}));
	centered_point = rotate_point(centered_point, plane->vector);
	x = fmod(centered_point.x, 1);
	y = fmod(centered_point.z, 1);
	if (x < 0)
		x += 1;
	if (y < 0)
		y += 1;
	return ((t_texture_coordinates){
		.x = x,
		.y = y
	});
}
