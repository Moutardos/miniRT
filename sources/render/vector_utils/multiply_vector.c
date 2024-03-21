/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:06:44 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/21 02:06:54 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	multiply_vector(double scalar, t_vector vector)
{
	t_vector	scalar_multiplied_vector;

	scalar_multiplied_vector = (t_vector){
		scalar * vector.x,
		scalar * vector.y,
		scalar * vector.z
	};
	return (scalar_multiplied_vector);
}
