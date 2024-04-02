/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:18:01 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/02 08:03:26 by ekhaled          ###   ########.fr       */
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

void	handle_camera(int keycode, t_camera *camera)
{
	handle_translations(keycode, &camera->point);
	handle_rotations(keycode, &camera->vector);
}

int	call_keypress_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx_info.mlx_ptr);
	handle_camera(keycode, &data->settings.camera);
	reload_scene(data);
	return (0);
}
