/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_cross_product.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:19:22 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/13 19:25:50 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	perform_cross_product(t_vector vector1, t_vector vector2)
{
	t_vector	cross_product;

	cross_product = (t_vector){
		vector1.y * vector2.z - vector1.z * vector2.y,
		vector1.z * vector2.x - vector1.x * vector2.z,
		vector1.x * vector2.y - vector1.y * vector2.x
	};
	return (cross_product);
}
