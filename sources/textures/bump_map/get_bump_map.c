/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bump_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:29:32 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/19 18:52:09 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "minirt.h"

/* Faire une liste chaine avec path, img, map (t_vector *) et next*/
int	fill_bump_map_map(t_bump_map *bump_map)
{
	int		i;
	int		size;
	t_img	image;
	t_color	*px_color;

	i = 0;
	image = bump_map->img;
	size = image.height * image.width;
	bump_map->map = malloc(sizeof(t_vector) * size);
	if (!bump_map->map)
		return (free(bump_map->path_name), 1);
	while (i < size)
	{
		px_color = (t_color *) &image.addr[i * (image.bpp / 8)];
		bump_map->map[i] = (t_vector)
		{
			.x = px_color->r,
			.y = px_color->g,
			.z = px_color->b
		};
		i++;
	}
	return (0);
}

int	init_node_bump_map(t_data *data, t_bump_map **node, char *path)
{
	*node = malloc(sizeof(t_bump_map));
	(*node)->next = NULL;
	if (!(*node))
		return (1);
	if (extract_image(&data->mlx_info, &(*node)->img, path))
		return (free(*node), 1);
	(*node)->path_name = path;
	return (0);
}

int	get_bump_map(t_data *data, t_texture *texture, char **ptr_line)
{
	static t_bump_map	*bump_maps = NULL;
	char				*path;
	t_bump_map			*node;
	t_bump_map			*node_prev;

	node = bump_maps;
	node_prev = NULL;
	texture->bump_maps = &bump_maps;
	if (extract_path(&path, ptr_line))
		return (1);
	while (node)
	{
		if (!ft_strcmp(path, node->path_name))
			return (texture->bump_map = node, free(path), 0);
		node_prev = node;
		node = node->next;
	}
	if (init_node_bump_map(data, &node, path) || fill_bump_map_map(node))
		return (free(path), 1);
	if (node_prev)
		node_prev->next = node;
	texture->bump_map = node;
	if (bump_maps == NULL)
		bump_maps = node;
	return (0);
}
