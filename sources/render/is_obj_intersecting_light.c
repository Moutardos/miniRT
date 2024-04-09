/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_obj_intersecting_light.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:05:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/03 11:22:55 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_sp_intersecting_light (t_sphere *sphere, t_vector lightray,
			t_point_info *p_info, double t_max)
{
	t_quadratic_roots	roots;
	double				t;
	t_vector			op;
	double				c;
	double				mag_op;

	op = create_vector(sphere->center, p_info->point);
	mag_op = get_vector_magnitude(op);
	c = mag_op * mag_op - sphere->utils.radius * sphere->utils.radius;
	roots = solve_quadratic_equation(
			1,
			2 * perform_dot_product(op, lightray),
			c
			);
	if (roots.nb == 0 || (roots.nb == 1 && roots.single[0] < 0)
		|| (roots.nb == 2 && roots.distincts[0] < 0 && roots.distincts[1] < 0))
		return (false);
	t = get_min_positive_root(&roots);
	return (t < t_max && t > HITPOINT_OFFSET);
}

bool	is_pl_intersecting_light (t_plane *plane, t_vector lightray,
			t_point_info *p_info, double t_max)
{
	double		intermediate_dot_product;
	double		t;
	double		pp_dot;

	intermediate_dot_product
		= perform_dot_product(lightray, plane->vector);
	if (are_doubles_equals(intermediate_dot_product, 0))
		return (false);
	pp_dot = perform_dot_product(create_vector(p_info->point, plane->point),
		plane->vector);
	t = pp_dot / intermediate_dot_product;
	return (t < t_max && t > HITPOINT_OFFSET);
}

bool	is_obj_intersecting_light(t_object *object, t_point_info *p_info,
			t_vector lightray, double t_max)
{
	if (object->type == SP)
	{
		return (is_sp_intersecting_light(&object->sphere, lightray,
			p_info, t_max));
	}
	if (object->type == PL)
	{
		return (is_pl_intersecting_light(&object->plane, lightray,
			p_info, t_max));
	}
	return (false);
}