/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:29:28 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/08 11:56:33 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "minirt.h"

int	init_mlx_info(t_mlx_info *mlx_info)
{
	mlx_info->mlx_ptr = mlx_init();
	if (!mlx_info->mlx_ptr)
		return (1);
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr, WIN_W, WIN_H, "RT");
	if (!mlx_info->win_ptr)
	{
		mlx_destroy_display(mlx_info->mlx_ptr);
		return (1);
	}
	mlx_info->img.img_ptr = NULL;
	return (0);
}
