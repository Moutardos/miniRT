/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:05:26 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 16:27:54 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	reload_scene(t_data *data)
{
	fill_utils(&data->settings.camera, &data->object_array);
	fill_utils_light(&data->settings.light, &data->object_array);
	run_rt(data);
}
