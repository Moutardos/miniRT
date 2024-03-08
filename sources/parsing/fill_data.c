/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:00:28 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/08 10:48:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "minirt.h"

static int	reading_line_settings(t_settings *settings, char *line, int *count)
{
	int		error;

	error = 0;
	if (is_same_word(line, "C"))
		error = update_camera(&settings->camera, line);
	else if (is_same_word(line, "A"))
		error = update_env_light(&settings->env_light, line);
	else if (is_same_word(line, "L"))
		error = update_light(&settings->light, line);
	else if (is_same_word(line, "\n"))
		return (0);
	else if (!str_to_obj(line, NULL))
		(*count)++;
	else
	{
		ft_putstr_fd("Error\nUnknown identifier\n", 2);
		return (1);
	}
	if (!error)
		return (0);
	else if (error == 1)
		ft_putstr_fd("Error\nToo many of the same element\n", 2);
	else if (error == 2)
		ft_putstr_fd("Error\nWrong values\n", 2);
	return (1);
}

static int	fill_settings(t_settings *settings, char *file, int *count_objects)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (!get_next_line(&line, fd))
	{
		if (!line)
		{
			close(fd);
			return (0);
		}
		if (reading_line_settings(settings, line, count_objects))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	ft_putstr_fd("Error while trying to read file\n", 2);
	return (2);
}

int	fill_data(t_data *data, char *file)
{
	if (fill_settings(&data->settings, file, &data->object_array.len))
		return (1);
	return (0);
}
