/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:18:07 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/19 18:42:18 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "minirt.h"

int	extract_image(t_mlx_info *mlx_info, t_img *image, char *path)
{
	image->img_ptr = mlx_xpm_file_to_image(mlx_info->mlx_ptr, path,
			&image->width, &image->height);
	if (!image->img_ptr)
		return (1);
	image->addr = mlx_get_data_addr(image->img_ptr, &image->bpp,
			&image->size_line, &image->endian);
	if (!image->addr)
	{
		mlx_destroy_image(mlx_info->mlx_ptr, image->img_ptr);
		return (1);
	}
	return (0);
}
