/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_intersecting_cy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:04:45 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 10:55:57 by ekhaled          ###   ########.fr       */
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

bool	is_ray_intersecting_cy_disk(t_plane *induced_plane, double disk_radius,
			t_vector ray, t_point_info *point_info)
{
	double	mag;

	if (!is_ray_intersecting_pl(induced_plane, ray, point_info))
		return (false);
	mag = get_vector_magnitude(
			sum_vectors(induced_plane->utils.point_camera, point_info->cp));
	return (mag <= disk_radius);
}

bool	is_ray_intersecting_cy(t_cylinder *cylinder, t_vector ray,
			t_point_info *point_info)
{
	t_point_info	current_point_info;

	init_point_info(&current_point_info);
	if (is_ray_intersecting_cy_disk(&cylinder->utils.induced_plane1,
			cylinder->utils.radius, ray, &current_point_info))
		if (point_info->cp_magnitude == -1
			|| current_point_info.cp_magnitude < point_info->cp_magnitude)
			*point_info = current_point_info;
	if (is_ray_intersecting_cy_disk(&cylinder->utils.induced_plane2,
			cylinder->utils.radius, ray, &current_point_info))
		if (point_info->cp_magnitude == -1
			|| current_point_info.cp_magnitude < point_info->cp_magnitude)
			*point_info = current_point_info;
	if (is_ray_intersecting_cy_tube(cylinder, ray, &current_point_info))
		if (point_info->cp_magnitude == -1
			|| current_point_info.cp_magnitude < point_info->cp_magnitude)
			*point_info = current_point_info;
	return (point_info->cp_magnitude != -1);
}
