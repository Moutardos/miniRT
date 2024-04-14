/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lightray_intersecting_co.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:23:23 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 04:41:35 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

bool	is_lightray_intersecting_co_tube(t_cone *cone,
		t_vector lightray, double t_max)
{
	t_quadratic_roots	roots;
	double				dot_prod_uv;
	double				squared_dot_prod_uv;
	double				t;
	double				p;

	dot_prod_uv = perform_dot_product(lightray, cone->vector);
	squared_dot_prod_uv = dot_prod_uv * dot_prod_uv;
	roots = solve_quadratic_equation(
			1 - (squared_dot_prod_uv) * cone->utils.la_const,
			2 * perform_dot_product(cone->utils.disk1_center_light, lightray)
			+ dot_prod_uv * cone->utils.lb_const,
			cone->utils.lc_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_positive_root(&roots);
	p = -(t * dot_prod_uv + cone->utils.dot_prod_disk1_center_light_dir);
	if (p < 0 || p > cone->height)
		return (false);
	return (t < (t_max - EPSILON) && t > EPSILON);
}

bool	is_lightray_intersecting_co(t_cone *cone, t_vector lightray,
			double t_max)
{
	if (is_lightray_intersecting_disk(&cone->utils.induced_plane2,
			cone->utils.radius, lightray, t_max))
		return (true);
	return (is_lightray_intersecting_co_tube(cone, lightray, t_max));
}
