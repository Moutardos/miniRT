/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lightray_intersecting_sp.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:05:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 18:04:27 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

bool	is_lightray_intersecting_sp(t_sphere *sphere, t_vector lightray,
			double t_max)
{
	t_quadratic_roots	roots;
	double				t;

	roots = solve_quadratic_equation(
			1,
			2 * perform_dot_product(sphere->utils.light_utils->center_light,
				lightray),
			sphere->utils.light_utils->lc_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_positive_root(&roots);
	return (t < t_max - OFFSET);
}
