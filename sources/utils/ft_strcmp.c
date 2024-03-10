/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:52:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/10 17:28:01 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (*str1 == *str2 && (*str1 != '\0'))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
