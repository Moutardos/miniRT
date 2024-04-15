/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_light_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:01:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 17:18:34 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_light_array(t_light_array *light_array)
{
	if (light_array->len > 0)
	{
		free(light_array->array);
	}
}
