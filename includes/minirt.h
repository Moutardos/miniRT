/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:14:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/15 17:18:56 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "textures.h"
# include "events.h"
# include "mlx_info.h"
# include "objects.h"
# include "parsing.h"
# include "render.h"
# include "settings.h"
# include "utils.h"

typedef struct s_data
{
	t_mlx_info		mlx_info;
	t_settings		settings;
	t_object_array	object_array;
	t_frame			frame;
}	t_data;

int		init_data(t_data *data, char *file);
int		fill_data(t_data *data, char *file);

void	destroy_data(t_data *data);
void	destroy_light_utils(t_object_array *objects, int len);
void	destroy_object_array(t_object_array *object_array, int len);
void	destroy_light_array(t_light_array *light_array);

#endif
