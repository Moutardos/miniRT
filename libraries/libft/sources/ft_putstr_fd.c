/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:57:27 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 20:54:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	if (s == NULL)
		return (0);
	size = ft_strlen(s);
	return (write(fd, s, size));
}
