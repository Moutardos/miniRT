/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:23:13 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 00:23:41 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

void   get_matrix_rotation(t_matrix_3x3 rotation_matrix, double angle,
        t_vector axis)
{
    double  cos_a;
    double  sin_a;

    cos_a = cos(angle);
    sin_a = sin(angle);
    axis = normalize_vector(axis);
    rotation_matrix[0][0] = cos_a + (axis.x * axis.x) * (1 - cos_a);
    rotation_matrix[1][0] = axis.y * axis.x * (1 - cos_a) + axis.z * sin_a;
    rotation_matrix[2][0] = axis.z * axis.x * (1 - cos_a) - axis.y * sin_a;
    rotation_matrix[0][1] = axis.x * axis.y * (1 - cos_a) - axis.z * sin_a;
    rotation_matrix[1][1] = (axis.y * axis.y) * (1 - cos_a) + cos_a;
    rotation_matrix[2][1] = axis.z * axis.y * (1 - cos_a) + axis.x * sin_a;
    rotation_matrix[0][2] = axis.z * axis.x * (1 - cos_a) + axis.y * sin_a;
    rotation_matrix[1][2] = axis.z * axis.y * (1 - cos_a) - axis.x * sin_a;
    rotation_matrix[2][2] = cos_a + (axis.z * axis.z) * (1 - cos_a);
}