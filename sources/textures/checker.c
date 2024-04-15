/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:58:44 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 03:10:42 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "minirt.h"

static void	get_checker_size(t_checker *checker, enum e_object_type type)
{
	if (type == CO)
	{
		checker->width = CHECKER_CO_W;
		checker->height = CHECKER_CO_H;
	}
	else if (type == CY)
	{
		checker->width = CHECKER_CY_W;
		checker->height = CHECKER_CY_H;
	}
	else if (type == SP)
	{
		checker->width = CHECKER_SP_W;
		checker->height = CHECKER_SP_H;
	}
	else if (type == PL)
	{
		checker->width = CHECKER_PL_W;
		checker->height = CHECKER_PL_H;
	}
}

bool	init_checker(t_checker *checker, enum e_object_type type, char **line)
{
	*line += 2;
	ignore_space(line);
	get_checker_size(checker, type);
	if (extract_color(&checker->color_b, line))
		return (1);
	return (0);
}

t_color	get_checker_pattern(t_texture_coordinates coord, t_texture *texture)
{
	t_checker	ch;

	ch = texture->checker;
	if (((int) floor(coord.x * ch.width) 
			+ (int) floor(coord.y * ch.height)) % 2 == 0)
		return (texture->color);
	else
		return (ch.color_b);
}
