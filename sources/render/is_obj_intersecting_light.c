/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_obj_intersecting_light.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:05:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/05 19:41:36 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_sp_intersecting_light (t_sphere *sphere, t_vector lightray,
			double t_max)
{
	t_quadratic_roots	roots;
	double				t;

	roots = solve_quadratic_equation(
			1,
			2 * perform_dot_product(sphere->utils.center_light, lightray),
			sphere->utils.l_const
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = t_max - get_min_positive_root(&roots);
	return (t < t_max && t > HITPOINT_OFFSET);
}

bool	is_pl_intersecting_light (t_plane *plane, t_vector lightray,
			t_point hitpoint, double t_max)
{
	double		intermediate_dot_product;
	double		t;

	intermediate_dot_product
		= perform_dot_product(lightray, plane->vector);
	if (are_doubles_equals(intermediate_dot_product, 0))
		return (false);
	t = (perform_dot_product(create_vector(hitpoint, plane->point),
		plane->vector) / intermediate_dot_product);
	return (t < (t_max + HITPOINT_OFFSET) && t > HITPOINT_OFFSET);
}

bool	is_obj_intersecting_light(t_object *object,
			t_vector lightray, t_point hitpoint, double t_max)
{
	if (object->type == SP)
	{
		return (is_sp_intersecting_light(&object->sphere, lightray,
			t_max));
	}
	if (object->type == PL)
	{
		return (is_pl_intersecting_light(&object->plane, lightray, hitpoint, t_max));
	}
	return (false);
}