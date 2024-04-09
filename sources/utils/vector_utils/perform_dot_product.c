/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dot_product.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:57:05 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/20 20:16:25 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	perform_dot_product(t_vector vector1, t_vector vector2)
{
	double	scalar_product;

	scalar_product
		= vector1.x * vector2.x
		+ vector1.y * vector2.y
		+ vector1.z * vector2.z;
	return (scalar_product);
}
