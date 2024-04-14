/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:41:28 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/12 17:06:23 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_surface_normal(t_point_info *p_info)
{
	p_info->surface_normal = p_info->normal;
	if (perform_dot_product(p_info->surface_normal, p_info->cp) >= 0)
		p_info->surface_normal = multiply_vector(-1, p_info->normal);
	if (p_info->object->texture.type == BUMP)
		p_info->surface_normal = perturb_normal(p_info->surface_normal, p_info);
}
