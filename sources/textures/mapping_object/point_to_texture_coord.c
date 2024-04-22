/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_texture_coord.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 02:26:53 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_texture_coordinates	point_to_texture_coordinates(t_point_info *point_info)
{
	if (point_info->object->type == SP)
		return (get_sp_coord(&point_info->object->sphere, point_info));
	if (point_info->object->type == PL)
		return (get_pl_coord(&point_info->object->plane, point_info));
	if (point_info->object->type == CO)
		return (get_co_coord(&point_info->object->cone, point_info));
	if (point_info->object->type == CY)
		return (get_cy_coord(&point_info->object->cylinder, point_info));
	return ((t_texture_coordinates){0});
}
