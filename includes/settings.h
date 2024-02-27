/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:49:12 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/27 02:08:21 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include "objects.h"

typedef struct s_env_light
{
	double		ratio;
	t_color		color;
}	t_env_light;

typedef struct s_camera
{
	t_point		point;
	t_vector	vector;
	uint8_t		fov;
}	t_camera;

typedef struct s_light
{
	t_point		point;
	double		ratio;
	t_color		color;
}	t_light;

typedef struct s_settings
{
	t_env_light	env_light;
	t_camera	camera;
	t_light		light;
}	t_settings;

#endif
