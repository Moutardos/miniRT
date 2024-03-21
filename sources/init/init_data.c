/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:54:31 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/21 02:44:57 by ekhaled          ###   ########.fr       */
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
	return (0);
}
