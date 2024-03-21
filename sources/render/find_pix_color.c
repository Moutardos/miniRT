/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:35:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/21 03:16:44 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	find_pix_color(unsigned int i, unsigned int j, t_data *data)
{
	t_vector	ray;

	ray = compute_ray(i, j, &data->settings.camera, &data->frame);
}
