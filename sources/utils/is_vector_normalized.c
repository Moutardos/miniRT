/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vector_normalized.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:50:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/10 19:31:32 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "minirt.h"

bool	is_vector_normalized_d(double x, double y, double z)
{
	t_vector	vector;

	vector = (t_vector){
		.x = x,
		.y = y,
		.z = z
	};
	return (fabs(1.0 - get_magnitude(vector)) <= 0.0001);
}

bool	is_vector_normalized(t_vector v)
{
	return (fabs(1.0 - get_magnitude(v)) <= 0.0001);
}
