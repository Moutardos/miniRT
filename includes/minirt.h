/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:14:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/11 01:12:20 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "parsing.h"
# include "mlx_info.h"
# include "parsing.h"
# include "events.h"
# include "colors.h"
# include "render.h"
# include "settings.h"
# include "objects.h"
# include "utils.h"

typedef struct s_data
{
	t_mlx_info		mlx_info;
	t_settings		settings;
	t_object_array	object_array;
}	t_data;

int		init_data(t_data *data, char *file);
void	destroy_data(t_data *data);
int		fill_data(t_data *data, char *file);

#endif
