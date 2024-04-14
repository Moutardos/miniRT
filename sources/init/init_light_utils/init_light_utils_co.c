/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_utils_co.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:11:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/14 17:43:14 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_light_utils_co(t_cone *cone, int len)
{
	cone->utils.light_utils_array.array
		= malloc(sizeof(t_light_utils_co) * len);
	if (!cone->utils.light_utils_array.array)
		return (1);
	cone->utils.light_utils_array.len = len;
	if (init_light_utils_pl(&cone->utils.induced_plane2, len))
	{
		free(cone->utils.light_utils_array.array);
		return (1);
	}
	return (0);
}
