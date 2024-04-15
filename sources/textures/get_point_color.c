/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:38:16 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 15:39:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_point_color(t_point_info *point_info)
{
	t_texture_coordinates	coord;

	if (point_info->object->texture.type == NONE)
		return (point_info->object->texture.color);
	coord = point_to_texture_coordinates(point_info);
	if (point_info->object->texture.type == CH)
		return (get_checker_pattern(coord, &point_info->object->texture));
	else
		return (point_info->object->texture.color);
}
