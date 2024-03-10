/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:15:59 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/10 20:34:03 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>

#include "minirt.h"
#include "mlx.h"

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx_info.win_ptr, DestroyNotify, StructureNotifyMask,
		&call_destroynotify_handler, &data->mlx_info);
}
