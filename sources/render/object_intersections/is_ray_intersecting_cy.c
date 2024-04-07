/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_intersecting_cy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:04:45 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/07 19:13:23 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_ray_intersecting_cy_tube(t_cylinder *cylinder, t_vector ray,
			t_point_info *point_info)
{
	t_quadratic_roots	roots;
	double				dot_prod_uv;
	double				squared_dot_prod_uv;
	t_vector			proj_o_c;

	dot_prod_uv = perform_dot_product(ray, cylinder->vector);
	squared_dot_prod_uv = dot_prod_uv * dot_prod_uv;
	roots = solve_quadratic_equation(
			1 - (squared_dot_prod_uv),
			2 * perform_dot_product(cylinder->utils.center_camera, ray)
			- 2 * cylinder->utils.p_const * dot_prod_uv,
			cylinder->utils.c_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	point_info->cp_magnitude = get_min_positive_root(&roots);
	point_info->cp = multiply_vector(point_info->cp_magnitude, ray);
	proj_o_c = multiply_vector(-(point_info->cp_magnitude * dot_prod_uv
				+ cylinder->utils.p_const), cylinder->vector);
	point_info->normal = normalize_vector(sum_vectors(
				sum_vectors(point_info->cp, cylinder->utils.center_camera),
				proj_o_c));
	return (get_vector_magnitude(proj_o_c) <= cylinder->utils.halved_height);
}

bool	is_ray_intersecting_cy_disks(t_cylinder *cylinder, t_vector ray,
			t_point_info *point_info)
{
	double			mag;
	bool			is_intersecting_p1;
	bool			is_intersecting_p2;
	t_point_info	point_info_p1;
	t_point_info	point_info_p2;

	point_info_p1 = *point_info;
	point_info_p2 = *point_info;
	is_intersecting_p1 = is_ray_intersecting_pl(
			&cylinder->utils.induced_plane1, ray, &point_info_p1);
	is_intersecting_p2 = is_ray_intersecting_pl(
			&cylinder->utils.induced_plane2, ray, &point_info_p2);
	if (is_intersecting_p1 && is_intersecting_p2)
	{
		if (point_info_p1.cp_magnitude < point_info_p2.cp_magnitude)
		{
			*point_info = point_info_p1;
			mag = get_vector_magnitude(sum_vectors(
						cylinder->utils.disk1_center_camera, point_info->cp));
		}
		else
		{
			*point_info = point_info_p2;
			mag = get_vector_magnitude(sum_vectors(
						cylinder->utils.disk2_center_camera, point_info->cp));
		}
	}
	else if (is_intersecting_p1)
	{
		*point_info = point_info_p1;
		mag = get_vector_magnitude(sum_vectors(
					cylinder->utils.disk1_center_camera, point_info->cp));
	}
	else if (is_intersecting_p2)
	{
		*point_info = point_info_p2;
		mag = get_vector_magnitude(sum_vectors(
					cylinder->utils.disk2_center_camera, point_info->cp));
	}
	else
		return (false);
	return (mag <= cylinder->utils.radius);
}

bool	is_ray_intersecting_cy(t_cylinder *cylinder, t_vector ray,
			t_point_info *point_info)
{
	return (is_ray_intersecting_cy_tube(cylinder, ray, point_info)
		|| is_ray_intersecting_cy_tube(cylinder, ray, point_info));
}
