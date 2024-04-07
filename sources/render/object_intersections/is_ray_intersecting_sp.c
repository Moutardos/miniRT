/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_intersecting_sp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:03:28 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/07 19:03:31 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_ray_intersecting_sp(t_sphere *sphere, t_vector ray,
			t_point_info *point_info)
{
	t_quadratic_roots	roots;
	double				t;

	roots = solve_quadratic_equation(
			1,
			2 * perform_dot_product(sphere->utils.center_camera, ray),
			sphere->utils.c_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_positive_root(&roots);
	point_info->cp = multiply_vector(t, ray);
	point_info->cp_magnitude = t;
	point_info->normal = multiply_vector(1 / sphere->utils.radius,
			sum_vectors(sphere->utils.center_camera, point_info->cp));
	return (true);
}
