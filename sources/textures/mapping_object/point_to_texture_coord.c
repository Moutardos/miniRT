/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_texture_coord.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/14 17:53:35 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_texture_coordinates	point_to_texture_coordinates(t_object *object,
						t_point point)
{
	if (object->type == SP)
		return (get_sp_coord(&object->sphere, point));
	if (object->type == PL)
		return (get_pl_coord(&object->plane, point));
	if (object->type == CO)
		return (get_co_coord(&object->cone, point));
	if (object->type == CY)
		return (get_cy_coord(&object->cylinder, point));
	return ((t_texture_coordinates){0});
}
