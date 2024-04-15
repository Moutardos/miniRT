/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:58:44 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 02:15:23 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "minirt.h"

bool	init_checker(t_checker *checker, char **line)
{
	*line += 2;
	ignore_space(line);
	checker->width = CHECKER_W;
	checker->height = CHECKER_H;
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
