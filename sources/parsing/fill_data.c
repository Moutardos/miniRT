/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:00:28 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 01:48:43 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "minirt.h"

static int	read_line_settings(t_settings *settings, char *line,
			int *count_object, int *count_light)
{
	int		error;

	ignore_space(&line);
	error = 0;
	if (is_same_first_word(line, "C"))
		error = update_camera(&settings->camera, line);
	else if (is_same_first_word(line, "A"))
		error = update_env_light(&settings->env_light, line);
	else if (is_same_first_word(line, "l"))
		(*count_light)++;
	else if (is_same_first_word(line, "\n"))
		return (0);
	else if (!str_to_obj(line, NULL))
		(*count_object)++;
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

static int	read_line_arrays(t_data *data,
				t_object_array *objects, t_light_array *lights, char *line)
{
	static int	i_obj = 0;
	static int	i_light = 0;
	int			error;
	char		*original_line;

	ignore_space(&line);
	original_line = line;
	error = 0;
	if (is_same_first_word(line, "l"))
	{
		error = update_light(&lights->array[i_light], line);
		i_light++;
	}
	else if (str_to_obj(line, &objects->array[i_obj].type))
		return (0);
	else
		error = init_object(data, &objects->array[i_obj++], line);
	if (error)
	{
		ft_putstr_fd("Error\nWrong values\n", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\n", 2);
		return (destroy_object_array(data, objects, i_obj - 1),
			destroy_light_array(lights), 1);
	}
	return (0);
}

static int	fill_settings(t_settings *settings, char *file, int *count_object,
			int *count_light)
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
		if (read_line_settings(settings, line, count_object, count_light))
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

int	fill_arrays(t_data *data, t_object_array *objects,
		t_light_array *lights, char *file)
{
	char			*line;
	int				fd;

	if (file_check(&fd, file))
		return (1);
	while (!get_next_line(&line, fd))
	{
		if (!line)
		{
			close(fd);
			if (init_light_utils(objects, lights))
			{
				return (destroy_light_array(lights),
					destroy_object_array(data, objects, objects->len), 1);
			}
			return (0);
		}
		if (read_line_arrays(data, objects, lights, line))
			return (close(fd), free(line), 1);
		free(line);
	}
	close(fd);
	ft_putstr_fd("Error while allocating memory\n", 2);
	return (1);
}

int	fill_data(t_data *data, char *file)
{
	t_object_array	*objects;
	t_light_array	*lights;

	if (fill_settings(&data->settings, file, &data->object_array.len,
			&data->settings.light_array.len))
		return (1);
	lights = &data->settings.light_array;
	objects = &data->object_array;
	if (objects->len > 0 || lights->len > 0)
	{
		if (objects->len > 0)
			objects->array = ft_calloc(objects->len, sizeof(t_object));
		if (lights->len > 0)
			lights->array = ft_calloc(lights->len, sizeof(t_light));
		if ((lights->len > 0 && !lights->array)
			|| (objects->len > 0 && !objects->array))
		{
			ft_putstr_fd("Error while allocating memory\n", 2);
			return (1);
		}
		if (fill_arrays(data, objects, lights, file))
			return (1);
	}
	return (0);
}
