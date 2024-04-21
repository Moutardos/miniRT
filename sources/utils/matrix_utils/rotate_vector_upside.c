/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector_upside.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:09:07 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 00:20:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>
#include "libft.h"
#include "minirt.h"

t_vector    rotate_vector_upside(t_vector vec_orientation, t_point hitpoint, t_point
    center)
{
    const t_vector  upside = {0,1,0};
    double          angle;
	t_vector		axis;
    t_matrix_3x3    rotation_matrix;
    t_vector        projected_position;

    projected_position = create_vector(hitpoint, center);
	if (!(are_doubles_equals(perform_dot_product(vec_orientation, upside),1)))
	{
		angle = acos(perform_dot_product(vec_orientation, upside));
		axis = perform_cross_product(upside, vec_orientation);
        get_matrix_rotation(rotation_matrix, angle, axis);
	}
    else
        return (projected_position);
    return (multiply_vector_by_matrix(projected_position, rotation_matrix));
}
