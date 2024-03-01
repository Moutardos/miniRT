/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:49:12 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/01 20:38:08 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <stdbool.h>

# include "objects.h"

# define ENV_LIGHT_COLOR 0xFFFFFFFF
# define ENV_LIGHT_RATIO 0.5

# define LIGHT_COLOR 0x0
# define LIGHT_RATIO 0.0
# define LIGHT_POINT_X 0
# define LIGHT_POINT_Y 0
# define LIGHT_POINT_Z 0

# define CAMERA_FOV 90
# define CAMERA_VECTOR_X 0
# define CAMERA_VECTOR_Y 0
# define CAMERA_VECTOR_Z 0
# define CAMERA_POINT_X 0
# define CAMERA_POINT_Y 0
# define CAMERA_POINT_Z 0

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

int	init_settings(t_settings *settings);

#endif
