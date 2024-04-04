/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:24:36 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/03 14:52:44 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normalize_vector(t_vector vector)
{
	double		vector_magnitude;

	vector_magnitude = get_vector_magnitude(vector);
	if (vector_magnitude == 0)
		return (vector);
	return (multiply_vector(1 / vector_magnitude, vector));
}
