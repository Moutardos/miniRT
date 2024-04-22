/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lightray_intersecting_co.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 04:23:23 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/22 05:11:24 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

double	get_min_cone_root_light(t_quadratic_roots roots,
			double dot_prod_uv, t_cone *cone)
{
	double		p[2];
	double		c;

	c = cone->utils.light_utils->dot_prod_disk1_center_light_dir;
	if (roots.nb == 1 && roots.single[0] > 0)
	{
		p[0] = -(roots.single[0] * dot_prod_uv + c);
		if (p[0] >= 0 && p[0] < cone->height)
			return (roots.single[0]);
		return (-1);
	}
	p[0] = -(roots.distincts[0] * dot_prod_uv + c);
	p[1] = -(roots.distincts[1] * dot_prod_uv + c);
	if (p[0] >= 0 && p[0] < cone->height && p[1] >= 0 && p[1] < cone->height)
	{
		if (roots.distincts[1] < 0 || roots.distincts[0] < roots.distincts[1])
			return (roots.distincts[0]);
		return (roots.distincts[1]);
	}
	if (p[0] >= 0 && p[0] < cone->height)
		return (roots.distincts[0]);
	if (p[1] >= 0 && p[1] < cone->height)
		return (roots.distincts[1]);
	else
		return (-1);
}

bool	is_lightray_intersecting_co_tube(t_cone *cone,
		t_vector lightray, double t_max)
{
	t_quadratic_roots	roots;
	double				dot_prod_uv;
	double				squared_dot_prod_uv;
	double				t;

	dot_prod_uv = perform_dot_product(lightray, cone->vector);
	squared_dot_prod_uv = dot_prod_uv * dot_prod_uv;
	roots = solve_quadratic_equation(
			1 - (squared_dot_prod_uv) * cone->utils.light_utils->la_const,
			2 * perform_dot_product(cone->utils.light_utils->disk1_center_light,
				lightray)
			+ dot_prod_uv * cone->utils.light_utils->lb_const,
			cone->utils.light_utils->lc_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_cone_root_light(roots, dot_prod_uv, cone);
	return (t < (t_max - OFFSET_LIGHT) && t > OFFSET_LIGHT);
}

bool	is_lightray_intersecting_co(t_cone *cone, t_vector lightray,
			double t_max)
{
	if (is_lightray_intersecting_disk(&cone->utils.induced_plane2,
			cone->utils.radius, lightray, t_max))
		return (true);
	return (is_lightray_intersecting_co_tube(cone, lightray, t_max));
}
