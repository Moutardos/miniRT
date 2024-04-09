/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:56:47 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 10:56:59 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_point_info(t_point_info *point_info)
{
	point_info->point = (t_point){0, 0, 0};
	point_info->cp = (t_vector){0, 0, 0};
	point_info->cp_magnitude = -1;
	point_info->object = NULL;
	point_info->normal = (t_vector){0, 0, 0};
}
