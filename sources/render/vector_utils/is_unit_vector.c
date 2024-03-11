/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unit_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:50:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/11 17:19:01 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "minirt.h"

bool	is_unit_vector(t_vector v)
{
	return (fabs(1.0 - get_vector_magnitude(v)) <= 0.0001);
}
