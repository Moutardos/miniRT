/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_intersecting_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:22:25 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/21 03:36:48 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_ray_intersecting_sp(t_sphere *sphere, t_camera *camera, t_vector ray)
{
	t_vector			o_sc;
	t_vector			o_so;
	double				o_so_magnitude;
	t_quadratic_roots	roots;

	o_sc = create_vector(sphere->center, camera->point);
	o_so = create_vector(sphere->center, (t_point){0, 0, 0});
	o_so_magnitude = get_vector_magnitude(o_so);
	roots = solve_quadratic_equation(
			1,
			2 * perform_dot_product(o_sc, ray),
			o_so_magnitude * o_so_magnitude
			- (sphere->diameter * sphere->diameter) / 4
			);
	if ((roots.roots_nb == 1 && roots.roots_one[0] > 0)
		|| (roots.roots_nb == 2
			&& (roots.roots_two[0] > 0 || roots.roots_two[1] > 0)))
	{
		return (true);
	}
	else
		return (false);
}

bool	is_ray_intersecting_obj(t_object *object,
			t_camera *camera, t_vector ray)
{
	if (object->type == SP)
		return (is_ray_intersecting_sp(&object->sphere, camera, ray));
	return (false);
}
