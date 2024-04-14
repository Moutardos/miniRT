/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:38:16 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/12 11:55:50 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_color	get_point_color(t_object *object, t_point point)
{
	t_texture_coordinates	coord;

	if (object->texture.type == NONE)
		return (object->texture.color);
	coord = point_to_texture_coordinates(object, point);
	if (object->texture.type == CH)
		return (get_checker_pattern(coord, &object->texture));
	else
		return (object->texture.color);
}
