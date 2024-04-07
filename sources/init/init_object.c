/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:06:22 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/07 13:39:34 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_sphere(t_sphere *sphere, char **line)
{
	*line += 2;
	ignore_space(line);
	if (extract_point(&sphere->center, line))
		return (1);
	ignore_space(line);
	if (extract_double(&sphere->diameter, line)
		|| sphere->diameter <= 0)
		return (1);
	ignore_space(line);
	return (0);
}

int	init_plane(t_plane *plane, char **line)
{
	*line += 2;
	ignore_space(line);
	if (extract_point(&plane->point, line))
		return (1);
	ignore_space(line);
	if (extract_unit_vector(&plane->vector, line))
		return (1);
	ignore_space(line);
	return (0);
}

int	init_cylinder(t_cylinder *cylinder, char **line)
{
	*line += 2;
	ignore_space(line);
	if (extract_point(&cylinder->center, line))
		return (1);
	ignore_space(line);
	if (extract_unit_vector(&cylinder->vector, line))
		return (1);
	ignore_space(line);
	if (extract_double(&cylinder->diameter, line)
		|| cylinder->diameter <= 0)
		return (1);
	ignore_space(line);
	if (extract_double(&cylinder->height, line)
		|| cylinder->height <= 0)
		return (1);
	ignore_space(line);
	return (0);
}

int	init_object(t_object *object, char *line)
{
	int	error;

	error = 0;
	if (object->type == PL)
		error = init_plane(&object->plane, &line);
	else if (object->type == SP)
		error = init_sphere(&object->sphere, &line);
	else if (object->type == CY)
		error = init_cylinder(&object->cylinder, &line);
	if (error)
		return (1);
	if (extract_color(&object->color, &line))
		return (1);
	ignore_space(&line);
	if (*line != '\n' && *line != '\0')
		return (1);
	return (0);
}
