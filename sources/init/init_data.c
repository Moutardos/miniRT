/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:54:31 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/11 18:32:00 by lcozdenm         ###   ########.fr       */
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
	fill_utils(&data->settings.camera,
		&data->settings.light_array, &data->object_array);
	return (0);
}
