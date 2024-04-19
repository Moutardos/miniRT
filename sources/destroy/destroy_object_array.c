/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_object_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:39:06 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/19 18:42:51 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_object_array(t_data *data,
			t_object_array *object_array, int len)
{
	if (object_array->len > 0)
	{
		destroy_bump_maps(data, object_array, len);
		destroy_light_utils(object_array, len);
		free(object_array->array);
	}
}
