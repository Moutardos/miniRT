/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_doubles_equals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:16:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/11 18:42:30 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "minirt.h"

bool	are_doubles_equals(double x, double y)
{
	return (ft_dabs(x - y) < EPSILON);
}
