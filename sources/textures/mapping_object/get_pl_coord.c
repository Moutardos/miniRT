/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pl_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:50:27 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 02:41:54 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "minirt.h"

t_texture_coordinates	get_pl_coord(t_plane *plane, t_point_info *point_info)
{
	t_vector	projected_position;
	double		y;
	double		x;

	projected_position
		= rotate_vector_upside(plane->vector, point_info->point, plane->point);
	x = fmod(projected_position.x, 1);
	y = fmod(projected_position.z, 1);
	if (x < 0)
		x += 1;
	if (y < 0)
		y += 1;
	return ((t_texture_coordinates){
		.x = x,
		.y = y
	});
}
