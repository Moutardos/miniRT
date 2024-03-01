/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:17:43 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/01 22:38:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "minirt.h"

static int	extract_int(int *value, char **ptr_line)
{
	int			sign;
	long int	raw_value;

	raw_value = 0;
	sign = 1;
	if (**ptr_line == '-')
	{
		(*ptr_line)++;
		sign = -1;
	}
	if (!ft_isdigit(**ptr_line))
		return (1);
	while (**ptr_line && ft_isdigit(**ptr_line))
	{
		raw_value *= 10;
		raw_value += (**ptr_line - '0') * sign;
		(*ptr_line)++;
	}
	if (raw_value < INT_MIN || raw_value > INT_MAX)
		return (3);
	*value = raw_value;
	return (0);
}

int	extract_double(double *value, char **ptr_line)
{
	int	raw_value;
	int	decimal_point;
	int	sign;

	decimal_point = 0;
	sign = 1;
	if (**ptr_line == '-')
		sign = -1;
	if (extract_int(&raw_value, ptr_line))
		return (1);
	*value = raw_value;
	if (**ptr_line != '.')
		return (0);
	(*ptr_line)++;
	while (ft_isdigit(**ptr_line))
	{
		if (decimal_point < DECIMAL_PRECISION)
		{
			*value = ((**ptr_line - '0') * sign) + *value * 10;
			decimal_point++;
		}
		(*ptr_line)++;
	}
	while (decimal_point--)
		*value /= 10;
	return (0);
}

/* @return: 1 if it couldn't extract a correct double
			2 if coma was expected and got something else
*/
int	extract_point(t_point *point, char **ptr_line)
{
	int	i;

	i = 0;
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
	int	i;

	i = 0;
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
