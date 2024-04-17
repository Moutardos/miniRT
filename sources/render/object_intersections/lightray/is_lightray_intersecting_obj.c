/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lightray_intersecting_obj.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:05:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/17 13:50:39 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setup_current_light_utils_cy(t_cylinder *cylinder, int light_index)
{
	t_plane	*disk1;
	t_plane	*disk2;

	cylinder->utils.light_utils
		= &(cylinder->utils.light_utils_array.array[light_index]);
	disk1 = &cylinder->utils.induced_plane1;
	disk1->utils.light_utils
		= &(disk1->utils.light_utils_array.array[light_index]);
	disk2 = &cylinder->utils.induced_plane2;
	disk2->utils.light_utils
		= &(disk2->utils.light_utils_array.array[light_index]);
}

void	setup_current_light_utils_co(t_cone *cone, int light_index)
{
	t_plane	*disk2;

	cone->utils.light_utils
		=&(cone->utils.light_utils_array.array[light_index]);
	disk2 = &cone->utils.induced_plane2;
	disk2->utils.light_utils
		=&(disk2->utils.light_utils_array.array[light_index]);
}

bool	is_lightray_intersecting_obj(t_object *object,
			t_vector lightray, double t_max, int light_index)
{
	if (object->type == SP)
	{
		object->sphere.utils.light_utils
			= &(object->sphere.utils.light_utils_array.array[light_index]);
		return (is_lightray_intersecting_sp(&object->sphere, lightray,
				t_max));
	}
	if (object->type == PL)
	{
		object->plane.utils.light_utils
			= &(object->plane.utils.light_utils_array.array[light_index]);
		return (is_lightray_intersecting_pl(&object->plane, lightray, t_max));
	}
	if (object->type == CY)
	{
		setup_current_light_utils_cy(&object->cylinder, light_index);
		return (is_lightray_intersecting_cy(&object->cylinder, lightray,
				t_max));
	}
	if (object->type == CO)
	{
		setup_current_light_utils_co(&object->cone, light_index);
		return (is_lightray_intersecting_co(&object->cone, lightray, t_max));
	}
	return (false);
}
