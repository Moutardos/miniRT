/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:57 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 14:20:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"

void	init_rt(t_data *data)
{
	init_hooks(data);
	run_rt(data);
	mlx_loop(data->mlx_info.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!is_single_argument(argc))
		return (1);
	if (init_data(&data, argv[1]))
		return (1);
	init_rt(&data);
	destroy_data(&data);
}
