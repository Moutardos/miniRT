/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:41:23 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 20:54:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	res_size;
	size_t	i;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	res_size = nmemb * size;
	res = malloc(res_size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < res_size)
	{
		((char *)res)[i] = '\0';
		i++;
	}
	return (res);
}
