/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:11 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/19 18:40:15 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "minirt.h"

int	get_path_len(char *line)
{
	int	i;

	i = 0;
	while (!ft_iswhitespace(line[i]))
		i++;
	return (i);
}

int	extract_path(char **path, char **ptr_line)
{
	int	len;

	len = get_path_len(*ptr_line);
	if (len <= 0)
		return (1);
	*path = malloc(sizeof(char) * (len + 1));
	if (!(*path))
		return (1);
	ft_strlcpy(*path, *ptr_line, len + 1);
	return (0);
}
