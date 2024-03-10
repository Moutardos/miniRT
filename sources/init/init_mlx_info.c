/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:29:28 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/10 16:17:30 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "minirt.h"

static int	init_img(t_img *img, void *mlx_ptr)
{
	img->img_ptr = mlx_new_image(mlx_ptr, WIN_W, WIN_H);
	if (!img->img_ptr)
		return (1);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	if (!img->addr)
	{
		mlx_destroy_image(mlx_ptr, img->img_ptr);
		return (1);
	}
	return (0);
}

int	init_mlx_info(t_mlx_info *mlx_info)
{
	mlx_info->mlx_ptr = mlx_init();
	if (!mlx_info->mlx_ptr)
		return (1);
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr, WIN_W, WIN_H, "RT");
	if (!mlx_info->win_ptr)
	{
		mlx_destroy_display(mlx_info->mlx_ptr);
		free(mlx_info->mlx_ptr);
		return (1);
	}
	if (init_img(&mlx_info->img, mlx_info->mlx_ptr))
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		mlx_destroy_display(mlx_info->mlx_ptr);
		free(mlx_info->mlx_ptr);
		return (1);
	}
	return (0);
}
