/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrrange.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:37:02 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/06 22:29:06 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minirt.h"

char	*ft_substrrange(char *buffer,
			unsigned int start_index, unsigned int end_index)
{
	char			*res;
	unsigned int	i;

	if (!buffer || start_index > end_index + 1)
		return (NULL);
	res = malloc((end_index - start_index + 2) * sizeof(char));
	if (!res)
		return (NULL);
	if (start_index == end_index + 1)
	{
		res[0] = 0;
		return (res);
	}
	i = 0;
	while (i != start_index)
		i++;
	while (i != end_index)
	{
		res[i - start_index] = buffer[i];
		i++;
	}
	res[i - start_index] = buffer[i];
	res[i - start_index + 1] = '\0';
	return (res);
}
