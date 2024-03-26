/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_intersecting_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:22:25 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/26 02:25:16 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_ray_intersecting_sp(t_sphere *sphere, t_vector ray)
{
	t_quadratic_roots	roots;

	roots = solve_quadratic_equation(
			1,
			2 * perform_dot_product(sphere->utils.center_camera, ray),
			sphere->utils.c_const
			);
	if ((roots.nb == 1 && roots.single[0] > 0)
		|| (roots.nb == 2
			&& (roots.distincts[0] > 0 || roots.distincts[1] > 0)))
		return (true);
	else
		return (false);
}

bool	is_ray_intersecting_pl(t_plane *plane, t_vector ray)
{
	double	intermediate_dot_product;
	double	t;

	intermediate_dot_product = perform_dot_product(ray, plane->vector);
	if (are_doubles_equals(intermediate_dot_product, 0))
		return (true);
	t = plane->utils.dot_prod_const / intermediate_dot_product;
	return (t > 0);
}

bool	is_ray_intersecting_cy_tube(t_cylinder *cylinder, t_vector ray)
{
	t_quadratic_roots	roots;
	double				dot_prod_uv;
	double				squared_dot_prod_uv;
	t_vector			o_c_proj;
	double				t;

	dot_prod_uv = perform_dot_product(ray, cylinder->vector);
	squared_dot_prod_uv = dot_prod_uv * dot_prod_uv;
	roots = solve_quadratic_equation(
			1 - ((2 * squared_dot_prod_uv) / cylinder->utils.squared_mag_dir)
			+ (squared_dot_prod_uv / cylinder->utils.dsquared_mag_dir),
			2 * perform_dot_product(cylinder->utils.center_camera, ray),
			cylinder->utils.c_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_positive_root(&roots);
	o_c_proj = multiply_vector(t * dot_prod_uv / cylinder->utils.squared_mag_dir
			+ cylinder->utils.p_const, cylinder->vector);
	return (get_vector_magnitude(o_c_proj) <= cylinder->utils.halved_height);
}

bool	is_ray_intersecting_obj(t_object *object, t_vector ray)
{
	if (object->type == CY)
		return (is_ray_intersecting_cy_tube(&object->cylinder, ray));
	if (object->type == PL)
		return (is_ray_intersecting_pl(&object->plane, ray));
	if (object->type == SP)
		return (is_ray_intersecting_sp(&object->sphere, ray));
	return (false);
}
