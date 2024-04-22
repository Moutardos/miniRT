/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector_upside.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:09:07 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 02:31:19 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "minirt.h"

t_vector	rotate_vector_upside(t_vector vec_orientation, t_point hitpoint,
				t_point center)
{
	const t_vector	upside = {0, 1, 0};
	double			dot_prod_vu;
	t_vector		axis;
	t_matrix_3x3	rotation_matrix;
	t_vector		projected_position;

	projected_position = create_vector(hitpoint, center);
	dot_prod_vu = perform_dot_product(vec_orientation, upside);
	if (!(are_doubles_equals(dot_prod_vu, 1)))
	{
		axis = perform_cross_product(upside, vec_orientation);
		get_rotation_matrix(rotation_matrix, acos(dot_prod_vu), axis);
	}
	else
		return (projected_position);
	return (multiply_vector_by_matrix(projected_position, rotation_matrix));
}
