/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lightray_intersecting_cy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:05:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 21:21:57 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

double	is_lightray_intersecting_cy_tube(t_cylinder *cylinder,
		t_vector lightray, double t_max)
{
	t_quadratic_roots	roots;
	double				dot_prod_uv;
	double				squared_dot_prod_uv;
	t_vector			proj_o_c;
	double				t;

	dot_prod_uv = perform_dot_product(lightray, cylinder->vector);
	squared_dot_prod_uv = dot_prod_uv * dot_prod_uv;
	roots = solve_quadratic_equation(
			1 - (squared_dot_prod_uv),
			2 * perform_dot_product(cylinder->utils.center_light, lightray)
			- 2 * cylinder->utils.lp_const * dot_prod_uv,
			cylinder->utils.lc_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_positive_root(&roots);
	proj_o_c = multiply_vector(-(t * dot_prod_uv
				+ cylinder->utils.lp_const), cylinder->vector);
	if (get_vector_magnitude(proj_o_c) > cylinder->utils.halved_height)
		return (false);
	return (t < (t_max + HITPOINT_OFFSET) && t > HITPOINT_OFFSET);
}

bool	is_lightray_intersecting_cy_disk(t_plane *induced_plane,
			double disk_radius, t_vector lightray, double t_max)
{
	double		mag;
	double		intermediate_dot_product;
	double		t;

	intermediate_dot_product
		= perform_dot_product(lightray, induced_plane->vector);
	if (are_doubles_equals(intermediate_dot_product, 0))
		return (false);
	t = induced_plane->utils.dot_prod_const_light / intermediate_dot_product;
	if (t >= (t_max + HITPOINT_OFFSET) || t < HITPOINT_OFFSET)
		return (false);
	mag = get_vector_magnitude(
			sum_vectors(induced_plane->utils.point_light,
				multiply_vector(t, lightray)));
	return (mag <= disk_radius);
}

bool	is_lightray_intersecting_cy(t_cylinder *cylinder, t_vector lightray,
			double t_max)
{
	if (is_lightray_intersecting_cy_disk(&cylinder->utils.induced_plane1,
			cylinder->utils.radius, lightray, t_max))
		return (true);
	if (is_lightray_intersecting_cy_disk(&cylinder->utils.induced_plane2,
			cylinder->utils.radius, lightray, t_max))
		return (true);
	return (is_lightray_intersecting_cy_tube(cylinder, lightray, t_max));
}
