/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:06:22 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/07 13:00:24 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_sphere(t_object *object, char *line)
{
	object->type = SP;
	line += 2;
	ignore_space(&line);
	if (extract_point(&object->sphere.center, &line))
		return (1);
	ignore_space(&line);
	if (extract_double(&object->sphere.diameter, &line)
		|| object->sphere.diameter <= 0)
		return (1);
	ignore_space(&line);
	if (extract_color(&object->color, &line))
		return (1);
	ignore_space(&line);
	if (*line != '\n' && *line != '\0')
		return (1);
	return (0);
}

int	init_plane(t_object *object, char *line)
{
	object->type = PL;
	line += 2;
	ignore_space(&line);
	if (extract_point(&object->plane.point, &line))
		return (1);
	ignore_space(&line);
	if (extract_unit_vector(&object->plane.vector, &line))
		return (1);
	ignore_space(&line);
	if (extract_color(&object->color, &line))
		return (1);
	ignore_space(&line);
	if (*line != '\n' && *line != '\0')
		return (1);
	return (0);
}

int	init_cylinder(t_object *object, char *line)
{
	object->type = CY;
	line += 2;
	ignore_space(&line);
	if (extract_point(&object->cylinder.center, &line))
		return (1);
	ignore_space(&line);
	if (extract_unit_vector(&object->cylinder.vector, &line))
		return (1);
	ignore_space(&line);
	if (extract_double(&object->cylinder.diameter, &line)
		|| object->cylinder.diameter <= 0)
		return (1);
	ignore_space(&line);
	if (extract_double(&object->cylinder.height, &line)
		|| object->cylinder.height <= 0)
		return (1);
	ignore_space(&line);
	if (extract_color(&object->color, &line))
		return (1);
	ignore_space(&line);
	if (*line != '\n' && *line != '\0')
		return (1);
	return (0);
}
