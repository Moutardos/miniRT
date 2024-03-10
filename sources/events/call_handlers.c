/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:18:01 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/10 20:35:53 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"

int	call_destroynotify_handler(t_mlx_info *mlx_info)
{
	mlx_loop_end(mlx_info->mlx_ptr);
	return (0);
}
