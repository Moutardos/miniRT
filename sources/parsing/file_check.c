/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:42:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 17:16:40 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "libft.h"
#include "minirt.h"

int	file_check(int *fd, char *file)
{
	if (ft_strlen(file) < 3 || ft_strcmp(file + (ft_strlen(file) - 3), ".rt"))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Expecting .rt extension\n", 2);
		return (1);
	}
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}
