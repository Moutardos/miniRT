/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_camray_intersecting_co.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:21:18 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/13 19:31:07 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

t_vector	get_cone_normal(t_cone *cone, t_vector cp)
{
	t_vector	d1_center_point;
	t_vector	tangent_vector;
	t_vector	normal;

	d1_center_point
		= sum_vectors(cone->utils.disk1_center_camera, cp);
	tangent_vector = perform_cross_product(cone->vector, d1_center_point);
	normal = perform_cross_product(tangent_vector, d1_center_point);
	return (normalize_vector(normal));
}

bool	is_camray_intersecting_co_tube(t_cone *cone, t_vector ray,
			t_point_info *point_info)
{
	t_quadratic_roots	roots;
	double				dot_prod_uv;
	double				squared_dot_prod_uv;
	double				t;
	double				p;

	dot_prod_uv = perform_dot_product(ray, cone->vector);
	squared_dot_prod_uv = dot_prod_uv * dot_prod_uv;
	roots = solve_quadratic_equation(
			1 - (squared_dot_prod_uv) * cone->utils.ca_const,
			2 * perform_dot_product(cone->utils.disk1_center_camera, ray)
			+ dot_prod_uv * cone->utils.cb_const,
			cone->utils.cc_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_positive_root(&roots);
	p = -(t * dot_prod_uv + cone->utils.dot_prod_disk1_center_camera_dir);
	if (p < 0 || p > cone->height)
		return (false);
	point_info->cp_magnitude = t;
	point_info->cp = multiply_vector(t, ray);
	point_info->normal = get_cone_normal(cone, point_info->cp);
	return (true);
}

bool	is_camray_intersecting_co(t_cone *cone, t_vector ray,
			t_point_info *point_info)
{
	return (is_camray_intersecting_co_tube(cone, ray, point_info));
}
