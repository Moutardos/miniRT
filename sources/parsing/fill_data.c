/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:00:28 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 21:20:32 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "minirt.h"

static int	read_line_settings(t_settings *settings, char *line, int *count)
{
	int		error;

	error = 0;
	if (is_same_first_word(line, "C"))
		error = update_camera(&settings->camera, line);
	else if (is_same_first_word(line, "A"))
		error = update_env_light(&settings->env_light, line);
	else if (is_same_first_word(line, "L"))
		error = update_light(&settings->light, line);
	else if (is_same_first_word(line, "\n"))
		return (0);
	else if (!str_to_obj(line, NULL))
		(*count)++;
	else
		return (ft_putstr_fd("Error\nUnknown identifier\n", 2), 1);
	if (!error)
		return (0);
	else if (error == 1)
		ft_putstr_fd("Error\nToo many of the same element\n", 2);
	else if (error == 2)
	{
		ft_putstr_fd("Error\nWrong values\n", 2);
		return (ft_putstr_fd(line, 2), ft_putstr_fd("\n", 2), 1);
	}
	return (1);
}

static int	read_line_objects(t_object_array *objects, char *line)
{
	static int			i = 0;

	if (i >= objects->len)
		return (0);
	if (str_to_obj(line, &objects->array[i].type))
		return (0);
	if (init_object(&objects->array[i], line))
	{
		ft_putstr_fd("Error\nWrong values\n", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	i++;
	return (0);
}

static int	fill_settings(t_settings *settings, char *file, int *count_objects)
{
	int		fd;
	char	*line;

	if (file_check(&fd, file))
		return (1);
	while (!get_next_line(&line, fd))
	{
		if (!line)
		{
			close(fd);
			return (0);
		}
		if (read_line_settings(settings, line, count_objects))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	close(fd);
	ft_putstr_fd("Error while allocating memory\n", 2);
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
	if (file_check(&fd, file))
		return (1);
	while (!get_next_line(&line, fd))
	{
		if (!line)
			return (close(fd), 0);
		if (read_line_objects(objects, line))
			return (free(objects->array), free(line), close(fd), 1);
		free(line);
	}
	close(fd);
	ft_putstr_fd("Error while allocating memory\n", 2);
	return (2);
}

int	fill_data(t_data *data, char *file)
{
	if (fill_settings(&data->settings, file, &data->object_array.len))
		return (1);
	if (data->object_array.len > 0)
	{
		if (fill_objects(&data->object_array, file))
			return (1);
	}
	return (0);
}
