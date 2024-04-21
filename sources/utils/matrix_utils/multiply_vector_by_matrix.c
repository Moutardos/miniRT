/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_vector_by_matrix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:56:01 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/21 20:56:33 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	multiply_vector_by_matrix(t_vector vector, t_matrix_3x3 matrix)
{
	return ((t_vector){
		.x = vector.x * matrix[0][0]
			+ vector.y * matrix[1][0] + vector.z * matrix[2][0],
		.y = vector.x * matrix[0][1]
			+ vector.y * matrix[1][1] + vector.z * matrix[2][1],
		.z = vector.x * matrix[0][2]
			+ vector.y * matrix[1][2] + vector.z * matrix[2][2],
	});
}
