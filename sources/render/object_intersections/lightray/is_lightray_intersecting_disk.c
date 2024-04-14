/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lightray_intersecting_disk.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:26:47 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/15 18:05:54 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

bool	is_lightray_intersecting_disk(t_plane *induced_plane,
			double disk_radius, t_vector lightray, double t_max)
{
	double		mag;
	double		intermediate_dot_product;
	double		t;

	intermediate_dot_product
		= perform_dot_product(lightray, induced_plane->vector);
	if (are_doubles_equals(intermediate_dot_product, 0))
		return (false);
	t = induced_plane->utils.light_utils->dot_prod_const_light
		/ intermediate_dot_product;
	if (t >= (t_max - OFFSET) || t < OFFSET)
		return (false);
	mag = get_vector_magnitude(
			sum_vectors(induced_plane->utils.light_utils->point_light,
				multiply_vector(t, lightray)));
	return (mag <= disk_radius);
}
