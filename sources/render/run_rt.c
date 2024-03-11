/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:01:58 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/11 01:08:20 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"

void	run_rt(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			find_pix_color(i, j, data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_info.mlx_ptr, data->mlx_info.win_ptr,
		data->mlx_info.img.img_ptr, 0, 0);
}
