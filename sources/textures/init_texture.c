/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:49:45 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/12 14:48:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_texture(t_texture *texture, char **line)
{
	if (extract_color(&texture->color, line))
		return (1);
	ignore_space(line);
	if (str_to_texture(*line, texture))
		return (1);
	if (texture->type == CH)
	{
		if (init_checker(&texture->checker, line))
			return (1);
	}
	if (texture->type == BUMP)
	{
		if (init_bump_map(&texture->map, line))
			return (1);
	}
	return (0);
}
