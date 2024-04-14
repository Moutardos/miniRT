/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_utils_pl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:11:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/12 12:34:37 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_light_utils_pl(t_plane *plane, int len)
{
	plane->utils.light_utils_array.array
		= malloc(sizeof(t_light_utils_pl) * len);
	if (!plane->utils.light_utils_array.array)
		return (1);
	plane->utils.light_utils_array.len = len;
	return (0);
}
