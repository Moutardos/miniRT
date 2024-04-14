/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:56:47 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/12 16:42:39 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_point_info(t_point_info *point_info)
{
	point_info->point = (t_point){0, 0, 0};
	point_info->cp = (t_vector){0, 0, 0};
	point_info->pc = (t_vector){0, 0, 0};
	point_info->cp_magnitude = -1;
	point_info->object = NULL;
	point_info->normal = (t_vector){0, 0, 0};
	point_info->surface_normal = (t_vector){0, 0, 0};
}
