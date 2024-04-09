/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_intersecting_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:22:25 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 10:31:53 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_ray_intersecting_obj(t_object *object, t_vector ray,
			t_point_info *point_info)
{
	bool	is_ray_intersecting;

	is_ray_intersecting = false;
	if (object->type == CY)
		is_ray_intersecting
			= is_ray_intersecting_cy(&object->cylinder, ray, point_info);
	if (object->type == PL)
		is_ray_intersecting
			= is_ray_intersecting_pl(&object->plane, ray, point_info);
	if (object->type == SP)
		is_ray_intersecting
			= is_ray_intersecting_sp(&object->sphere, ray, point_info);
	if (is_ray_intersecting)
	{
		point_info->object = object;
		return (true);
	}
	return (false);
}
