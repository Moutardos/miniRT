/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:05:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/06 23:24:10 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	str_to_obj(char *str, enum e_object_type *obj)
{
	if (is_same_word(str, "cy"))
	{
		if (obj)
			*obj = CY;
		return (0);
	}
	else if (is_same_word(str, "pl"))
	{
		if (obj)
			*obj = PL;
		return (0);
	}
	else if (is_same_word(str, "sp"))
	{
		if (obj)
			*obj = SP;
		return (0);
	}
	return (1);
}
