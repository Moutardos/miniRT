/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lightray_intersecting_pl.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:05:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 14:32:13 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_lightray_intersecting_pl(t_plane *plane, t_vector lightray,
		double t_max)
{
	double		intermediate_dot_product;
	double		t;

	intermediate_dot_product
		= perform_dot_product(lightray, plane->vector);
	if (are_doubles_equals(intermediate_dot_product, 0))
		return (false);
	t = plane->utils.dot_prod_const_l / intermediate_dot_product;
	return (t < (t_max + HITPOINT_OFFSET) && t > HITPOINT_OFFSET);
}
