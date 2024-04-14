/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bump_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:29:32 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/14 16:34:35 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "minirt.h"

int	fill_bump_map(t_bump_map *bump_map, t_vector *map, char *path)
{
	int		i;
	int		fd;
	int		size;
	char	*line;
	char	*line_copy;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error opening texture\n", 2), 1);
	i = 0;
	size = bump_map->height * bump_map->width;
	while (!get_next_line(&line, fd))
	{
		if (!line && i < size)
			return (close(fd), 1);
		if (!line)
			return (close(fd), 0);
		line_copy = line;
		if (i >= size || extract_vector(&map[i], &line_copy))
			return (free(line), close(fd), 1);
		free(line);
		i++;
	}
	close(fd);
	return (ft_putstr_fd("Error while allocating memory\n", 2), 1);
}

int	init_bump_map(t_bump_map *bump_map, char **line)
{
	static t_vector	*map_wood = NULL;

	if (bump_map->type == WOOD)
	{
		bump_map->height = BM_WOOD_H;
		bump_map->width = BM_WOOD_W;
		*line += ft_strlen("wood");
		if (map_wood == NULL)
		{
			map_wood = malloc(sizeof(t_vector) * BM_WOOD_SIZE);
			if (!map_wood || fill_bump_map(bump_map, map_wood, "texture/wood"))
				return (free(map_wood), 1);
		}
		bump_map->map = &map_wood;
		return (0);
	}
	return (1);
}
