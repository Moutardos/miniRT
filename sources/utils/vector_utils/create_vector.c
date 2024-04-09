/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:50:19 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/11 12:51:13 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	create_vector(t_point start_point, t_point end_point)
{
	t_vector	vector;

	vector = (t_vector){
		end_point.x - start_point.x,
		end_point.y - start_point.y,
		end_point.z - start_point.z
	};
	return (vector);
}
