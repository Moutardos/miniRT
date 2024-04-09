/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lightray_intersecting_obj.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:05:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 15:56:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_lightray_intersecting_obj(t_object *object,
			t_vector lightray, double t_max)
{
	if (object->type == SP)
	{
		return (is_lightray_intersecting_sp(&object->sphere, lightray,
				t_max));
	}
	if (object->type == PL)
	{
		return (is_lightray_intersecting_pl(&object->plane, lightray, t_max));
	}
	if (object->type == CY)
	{
		return (is_lightray_intersecting_cy(&object->cylinder, lightray,
				t_max));
	}
	return (false);
}
