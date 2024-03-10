/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:47:29 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/10 16:17:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "minirt.h"

void	destroy_mlx_info(t_mlx_info *mlx_info)
{
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->img.img_ptr);
	mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	mlx_destroy_display(mlx_info->mlx_ptr);
	free(mlx_info->mlx_ptr);
}
