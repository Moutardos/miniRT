/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:49:45 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/19 18:52:09 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int	init_texture(t_data *data, t_texture *texture, enum e_object_type type,
		char **line)
{
	texture->bump_maps = NULL;
	texture->bump_map = NULL;
	if (extract_color(&texture->color, line))
		return (1);
	ignore_space(line);
	if (str_to_texture(*line, texture))
		return (1);
	if (texture->type == CH)
	{
		if (init_checker(&texture->checker, type, line))
			return (1);
	}
	if (texture->type == BUMP)
	{
		(*line) += 2;
		ignore_space(line);
		if (get_bump_map(data, texture, line))
			return (1);
		(*line) += ft_strlen(texture->bump_map->path_name);
	}
	return (0);
}
