/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_intersecting_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:22:25 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/07 19:11:03 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_ray_intersecting_obj(t_object *object, t_vector ray,
			t_point_info *point_info)
{
	if (object->type == CY)
		return (is_ray_intersecting_cy(&object->cylinder, ray, point_info));
	if (object->type == PL)
		return (is_ray_intersecting_pl(&object->plane, ray, point_info));
	if (object->type == SP)
		return (is_ray_intersecting_sp(&object->sphere, ray, point_info));
	return (false);
}
