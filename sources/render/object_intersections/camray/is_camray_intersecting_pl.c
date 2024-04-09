/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_camray_intersecting_pl.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:05:51 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 20:40:12 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_camray_intersecting_pl(t_plane *plane, t_vector ray,
			t_point_info *point_info)
{
	double	intermediate_dot_product;
	double	t;

	intermediate_dot_product = perform_dot_product(ray, plane->vector);
	if (are_doubles_equals(intermediate_dot_product, 0))
	{
		point_info->cp = (t_vector){0, 0, 0};
		point_info->cp_magnitude = 0;
		point_info->normal = plane->vector;
		return (are_doubles_equals(plane->utils.dot_prod_const_camera, 0));
	}
	t = plane->utils.dot_prod_const_camera / intermediate_dot_product;
	if (t <= 0)
		return (false);
	point_info->cp = multiply_vector(t, ray);
	point_info->cp_magnitude = t;
	point_info->normal = plane->vector;
	return (true);
}
