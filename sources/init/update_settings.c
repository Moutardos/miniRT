/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:26:42 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/08 10:49:12 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	update_env_light(t_env_light *env_light, char *line)
{
	static int	count = 0;

	count++;
	if (count > 1)
		return (1);
	line++;
	ignore_space(&line);
	if (extract_double(&env_light->ratio, &line))
		return (2);
	if (env_light->ratio < 0 || env_light->ratio > 1)
		return (2);
	ignore_space(&line);
	if (extract_color(&env_light->color, &line))
		return (2);
	ignore_space(&line);
	if (*line != '\n' && *line != '\0')
		return (2);
	return (0);
}

int	update_light(t_light *light, char *line)
{
	static int	count = 0;

	count++;
	if (count > 1)
		return (1);
	line++;
	ignore_space(&line);
	if (extract_point(&light->point, &line))
		return (2);
	ignore_space(&line);
	if (extract_double(&light->ratio, &line))
		return (2);
	if (light->ratio < 0 || light->ratio > 1)
		return (2);
	ignore_space(&line);
	if (*line == '\n' || *line == '\0')
		return (0);
	if (extract_color(&light->color, &line))
		return (2);
	ignore_space(&line);
	if (*line != '\n' && *line != '\0')
		return (2);
	return (0);
}

int	update_camera(t_camera *camera, char *line)
{
	static int	count = 0;
	int			raw_value;

	count++;
	if (count > 1)
		return (1);
	line++;
	ignore_space(&line);
	if (extract_point(&camera->point, &line))
		return (2);
	ignore_space(&line);
	if (extract_vector(&camera->vector, &line))
		return (2);
	if (!is_vector_normalized(camera->vector))
		return (2);
	ignore_space(&line);
	if (extract_int(&raw_value, &line))
		return (2);
	if (raw_value > 180 || raw_value < 0)
		return (2);
	camera->fov = raw_value;
	ignore_space(&line);
	if (*line != '\n' && *line != '\0')
		return (2);
	return (0);
}
