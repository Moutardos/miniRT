/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:18:01 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/31 05:36:55 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "minirt.h"
#include "mlx.h"

int	call_destroynotify_handler(t_mlx_info *mlx_info)
{
	mlx_loop_end(mlx_info->mlx_ptr);
	return (0);
}

int	call_keypress_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx_info.mlx_ptr);
	return (0);
}
