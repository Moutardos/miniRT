/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:43:23 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/14 16:22:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_data(t_data *data)
{
	destroy_mlx_info(&data->mlx_info);
	if (data->object_array.len > 0)
	{
		destroy_light_utils(&data->object_array, data->object_array.len);
		destroy_bump_maps(&data->object_array);
		free(data->object_array.array);
	}
	if (data->settings.light_array.len > 0)
		free(data->settings.light_array.array);
}
