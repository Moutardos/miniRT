/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_intersecting_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:22:25 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/25 23:57:48 by ekhaled          ###   ########.fr       */
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
	if ((roots.roots_nb == 1 && roots.roots_one[0] > 0)
		|| (roots.roots_nb == 2
			&& (roots.roots_two[0] > 0 || roots.roots_two[1] > 0)))
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

bool	is_ray_intersecting_obj(t_object *object, t_vector ray)
{
	if (object->type == PL)
		return (is_ray_intersecting_pl(&object->plane, ray));
	if (object->type == SP)
		return (is_ray_intersecting_sp(&object->sphere,ray));
	return (false);
}
