/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:53:49 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/20 22:49:54 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	extract_point(t_point *point, char **ptr_line)
{
	if (extract_double(&point->x, ptr_line))
		return (1);
	if (**ptr_line != ',')
		return (2);
	(*ptr_line)++;
	if (extract_double(&point->y, ptr_line))
		return (1);
	if (**ptr_line != ',')
		return (2);
	(*ptr_line)++;
	if (extract_double(&point->z, ptr_line))
		return (1);
	return (0);
}

int	extract_vector(t_vector *vector, char **ptr_line)
{
	if (extract_double(&vector->x, ptr_line))
		return (1);
	if (**ptr_line != ',')
		return (2);
	(*ptr_line)++;
	if (extract_double(&vector->y, ptr_line))
		return (1);
	if (**ptr_line != ',')
		return (2);
	(*ptr_line)++;
	if (extract_double(&vector->z, ptr_line))
		return (1);
	return (0);
}

int	extract_unit_vector(t_vector *vector, char **ptr_line)
{
	if (extract_vector(vector, ptr_line))
		return (1);
	if (!is_unit_vector(*vector))
		return (2);
	return (0);
}

int	extract_color(t_color *color, char **ptr_line)
{
	int	raw_value;

	if (extract_int(&raw_value, ptr_line))
		return (1);
	if (raw_value < 0 || raw_value > 255)
		return (1);
	color->r = raw_value;
	if (**ptr_line != ',')
		return (2);
	(*ptr_line)++;
	if (extract_int(&raw_value, ptr_line))
		return (1);
	if (raw_value < 0 || raw_value > 255)
		return (1);
	color->g = raw_value;
	if (**ptr_line != ',')
		return (2);
	(*ptr_line)++;
	if (extract_int(&raw_value, ptr_line))
		return (1);
	if (raw_value < 0 || raw_value > 255)
		return (1);
	color->b = raw_value;
	return (0);
}

int	extract_fov(uint8_t *fov, char **ptr_line)
{
	int	raw_value;

	if (extract_int(&raw_value, ptr_line))
		return (2);
	if (raw_value >= 180 || raw_value <= 0)
		return (2);
	*fov = raw_value;
	return (0);
}
