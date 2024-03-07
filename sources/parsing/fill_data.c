/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:00:28 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/07 17:55:18 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "minirt.h"

static int	update_env_light(t_env_light *env_light, char *line)
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
	return (0);
}

static int	update_light(t_light *light, char *line)
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
	extract_color(&light->color, &line);
	return (0);
}

static int	update_camera(t_camera *camera, char *line)
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
	return (0);	
}

static int	reading_line(t_data *data, char *line, int *count)
{
	int		error;

	error = 0;
	if (is_same_word(line, "C"))	
		error = update_camera(&data->settings.camera, line);
	else if (is_same_word(line, "A"))
		error = update_env_light(&data->settings.env_light, line);
	else if (is_same_word(line, "L"))
		error = update_light(&data->settings.light, line);
	else if (is_same_word(line, "\n"))
		return (0);
	else if (!str_to_obj(line, NULL))
		count++;
	else
	{
		ft_putstr_fd("Error\nUnknown identifier\n",2);
		return (1);
	}
	if (!error)
		return (0);
	else if (error == 1)
		ft_putstr_fd("Error\nToo many of the same element\n",2);
	else if (error == 2)
		ft_putstr_fd("Error\nWrong values\n",2);
	return (1);
}

int	fill_data(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int 	count_objects;

	count_objects = 0;
	if (!file)
		return (1);
	fd = open(file, O_RDONLY);
	while (!get_next_line(&line, fd))
	{
		if (!line)
		{
			data->object_array.len = count_objects;
			return (0);
		}
		if (reading_line(data, line, &count_objects))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	ft_putstr_fd("Error while trying to read file\n", 2);
	return (2);
}