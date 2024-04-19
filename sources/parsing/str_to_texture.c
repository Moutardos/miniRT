/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:58:39 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/19 16:10:04 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

bool	str_to_texture(char *str, t_texture *texture)
{
	if (is_same_first_word(str, ""))
	{
		texture->type = NONE;
		return (0);
	}
	if (is_same_first_word(str, "ch"))
	{
		texture->type = CH;
		return (0);
	}
	if (is_same_first_word(str, "bm"))
	{
		texture->type = BUMP;
		return (0);
	}
	return (1);
}
