/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_first_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:40:59 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 20:54:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_same_first_word(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if ((ft_iswhitespace(*s1)))
			return (1);
		s1++;
		s2++;
	}
	if ((ft_iswhitespace(*s1) && ft_iswhitespace(*s1)
			== ft_iswhitespace(*s2)))
		return (1);
	return (0);
}
