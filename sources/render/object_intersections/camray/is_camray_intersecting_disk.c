/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_camray_intersecting_disk.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:49:19 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/13 20:17:03 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_camray_intersecting_disk(t_plane *induced_plane,
			double disk_radius, t_vector ray, t_point_info *point_info)
{
	double	mag;

	if (!is_camray_intersecting_pl(induced_plane, ray, point_info))
		return (false);
	mag = get_vector_magnitude(
			sum_vectors(induced_plane->utils.point_camera, point_info->cp));
	return (mag <= disk_radius);
}
