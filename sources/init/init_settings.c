/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:49 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/08 13:15:53 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minirt.h"

static void	init_default_env_light(t_env_light *env_light)
{
	env_light->ratio = ENV_LIGHT_RATIO;
	env_light->color.hex = ENV_LIGHT_COLOR;
}

static void	init_default_camera(t_camera *camera)
{
	camera->fov = CAMERA_FOV;
	camera->vector = (t_vector){
		.x = CAMERA_VECTOR_X,
		.y = CAMERA_VECTOR_Y,
		.z = CAMERA_VECTOR_Z
	};
	camera->point = (t_point){
		.x = CAMERA_POINT_X,
		.y = CAMERA_POINT_Y,
		.z = CAMERA_POINT_Z
	};
}

static void	init_default_light(t_light_array *light_array)
{
	light_array->array = NULL;
	light_array->len = 0;
}

void	init_settings(t_settings *settings)
{
	init_default_env_light(&settings->env_light);
	init_default_camera(&settings->camera);
	init_default_light(&settings->light_array);
}
