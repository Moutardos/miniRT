/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_camray_intersecting_co.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:21:18 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/22 04:15:46 by ekhaled          ###   ########.fr       */
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

double	get_min_cone_root_camera(t_quadratic_roots *roots,
			double dot_prod_uv, t_cone *cone)
{
	double		p[2];
	double		c;

	c = cone->utils.dot_prod_disk1_center_camera_dir;
	if (roots->nb == 1 && roots->single[0] > 0)
	{
		p[0] = -(roots->single[0] * dot_prod_uv + c);
		if (p[0] >= 0 && p[0] < cone->height)
			return (roots->single[0]);
		return (-1);
	}
	p[0] = -(roots->distincts[0] * dot_prod_uv + c);
	p[1] = -(roots->distincts[1] * dot_prod_uv + c);
	if (p[0] >= 0 && p[0] < cone->height && p[1] >= 0 && p[1] < cone->height)
	{
		if (roots->distincts[1] < 0 || roots->distincts[0] < roots->distincts[1])
			return (roots->distincts[0]);
		return (roots->distincts[1]);
	}
	if (p[0] >= 0 && p[0] < cone->height)
		return (roots->distincts[0]);
	if (p[1] >= 0 && p[1] < cone->height)
		return (roots->distincts[1]);
	else
		return (-1);
}

bool	is_camray_intersecting_co_tube(t_cone *cone, t_vector ray,
			t_point_info *point_info)
{
	t_quadratic_roots	roots;
	double				dot_prod_uv;
	double				squared_dot_prod_uv;
	double				t;

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
	t = get_min_cone_root_camera(&roots, dot_prod_uv, cone);
	if (t <= 0)
		return (false);
	point_info->cp_magnitude = t;
	point_info->cp = multiply_vector(t, ray);
	point_info->normal = get_cone_normal(cone, point_info->cp);
	return (true);
}

bool	is_camray_intersecting_co(t_cone *cone, t_vector ray,
			t_point_info *point_info)
{
	t_point_info	current_point_info;

	init_point_info(&current_point_info);
	if (is_camray_intersecting_disk(&cone->utils.induced_plane2,
			cone->utils.radius, ray, &current_point_info))
		if (point_info->cp_magnitude == -1
			|| current_point_info.cp_magnitude < point_info->cp_magnitude)
			*point_info = current_point_info;
	if (is_camray_intersecting_co_tube(cone, ray, &current_point_info))
		if (point_info->cp_magnitude == -1
			|| current_point_info.cp_magnitude < point_info->cp_magnitude)
			*point_info = current_point_info;
	return (point_info->cp_magnitude != -1);
}
