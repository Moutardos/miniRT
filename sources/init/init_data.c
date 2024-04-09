/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:54:31 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 16:32:47 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_data(t_data *data, char *file)
{
	if (init_mlx_info(&data->mlx_info))
		return (1);
	init_settings(&data->settings);
	data->object_array.len = 0;
	data->object_array.array = NULL;
	if (fill_data(data, file))
	{
		destroy_mlx_info(&data->mlx_info);
		return (1);
	}
	init_frame(&data->frame, &data->settings.camera);
	fill_utils(&data->settings.camera, &data->object_array);
	fill_utils_light(&data->settings.light, &data->object_array);
	return (0);
}
