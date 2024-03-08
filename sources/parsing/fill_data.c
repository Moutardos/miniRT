/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:00:28 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/08 11:38:36 by lcozdenm         ###   ########.fr       */
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

static int	reading_line_objects(t_object_array *objects, char *line)
{
	int					error;
	static int			i = 0;
	enum e_object_type	type;

	if (i >= objects->len)
		return (0);
	error = 0;
	if (str_to_obj(line, &type))
		return (0);
	if (type == PL)
		error = init_plane(&objects->array[i], line);
	else if (type == SP)
		error = init_sphere(&objects->array[i], line);
	else if (type == CY)
		error = init_cylinder(&objects->array[i], line);
	i++;
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

int	fill_objects(t_object_array *objects, char *file)
{
	char			*line;
	int				fd;

	objects->array = malloc(sizeof(t_object) * objects->len);
	if (!objects->array)
	{
		ft_putstr_fd("Error while allocating memory\n", 2);
		return (1);
	}
	fd = open(file, O_RDONLY);
	while (!get_next_line(&line, fd))
	{
		if (!line)
			return (close(fd), 0);
		if (reading_line_objects(objects, line))
			return (free(objects->array), free(line), close(fd), 1);
		free(line);
	}
	close(fd);
	ft_putstr_fd("Error while trying to read file\n", 2);
	return (2);
}

int	fill_data(t_data *data, char *file)
{
	if (fill_settings(&data->settings, file, &data->object_array.len))
		return (1);
	if (fill_objects(&data->object_array, file))
		return (1);
	return (0);
}
