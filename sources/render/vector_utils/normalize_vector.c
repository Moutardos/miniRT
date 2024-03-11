/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:24:36 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/11 15:53:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normalize_vector(t_vector vector)
{
	double		vector_magnitude;
	t_vector	normalized_vector;

	vector_magnitude = get_vector_magnitude(vector);
	if (vector_magnitude == 0)
		return (vector);
	normalized_vector = (t_vector){
		(1 / vector_magnitude) * vector.x,
		(1 / vector_magnitude) * vector.y,
		(1 / vector_magnitude) * vector.z
	};
	return (normalized_vector);
}
