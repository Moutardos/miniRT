/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:19:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/11 13:20:10 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	sum_vectors(t_vector vector1, t_vector vector2)
{
	t_vector	summed_vector;

	summed_vector = (t_vector){
		vector1.x + vector2.x,
		vector1.y + vector2.y,
		vector1.z + vector2.z,
	};
	return (summed_vector);
}
