/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:05:26 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 20:39:56 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	reload_scene(t_data *data)
{
	fill_utils(&data->settings.camera,
		&data->settings.light, &data->object_array);
	run_rt(data);
}
