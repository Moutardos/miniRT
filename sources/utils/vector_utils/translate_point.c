/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:12:36 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/21 02:14:19 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	translate_point(t_point point, t_vector vector)
{
	t_point	translated_point;

	translated_point = (t_point){
		point.x + vector.x,
		point.y + vector.y,
		point.z + vector.z
	};
	return (translated_point);
}
