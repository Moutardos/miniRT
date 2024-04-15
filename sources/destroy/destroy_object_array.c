/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_object_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:39:06 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 17:18:23 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_object_array(t_object_array *object_array, int len)
{
	if (object_array->len > 0)
	{
		destroy_bump_maps(object_array, len);
		free(object_array->array);
	}
}
