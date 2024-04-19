/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:43:23 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/19 18:24:52 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_data(t_data *data)
{
	destroy_object_array(data, &data->object_array, data->object_array.len);
	destroy_mlx_info(&data->mlx_info);
	destroy_light_array(&data->settings.light_array);
}
