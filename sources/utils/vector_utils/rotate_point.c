/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:42:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/12 11:54:36 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	rotate_point(t_point point, t_vector rotate)
{
	if (rotate.y != 0)
		return (point);
	if (rotate.z != 0)
		return ((t_point){point.x, point.z, point.y});
	if (rotate.x != 0)
		return ((t_point){point.y, point.x, point.z});
	return (point);
}
