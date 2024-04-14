/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_utils_cy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:11:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/12 12:29:07 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_light_utils_cy(t_cylinder *cylinder, int len)
{
	cylinder->utils.light_utils_array.array
		= malloc(sizeof(t_light_utils_cy) * len);
	if (!cylinder->utils.light_utils_array.array)
		return (1);
	cylinder->utils.light_utils_array.len = len;
	if (init_light_utils_pl(&cylinder->utils.induced_plane1, len))
	{
		free(cylinder->utils.light_utils_array.array);
		return (1);
	}
	if (init_light_utils_pl(&cylinder->utils.induced_plane2, len))
	{
		free(cylinder->utils.induced_plane1.utils.light_utils_array.array);
		free(cylinder->utils.light_utils_array.array);
		return (1);
	}
	return (0);
}
