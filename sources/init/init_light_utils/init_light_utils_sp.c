/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_utils_sp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:11:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/12 12:28:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_light_utils_sp(t_sphere *sphere, int len)
{
	sphere->utils.light_utils_array.array
		= malloc(sizeof(t_light_utils_sp) * len);
	if (!sphere->utils.light_utils_array.array)
		return (1);
	sphere->utils.light_utils_array.len = len;
	return (0);
}
