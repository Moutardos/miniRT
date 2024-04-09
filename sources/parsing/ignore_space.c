/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:06:04 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 21:20:38 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

void	ignore_space(char **ptr_line)
{
	while (ft_iswhitespace(**ptr_line) && **ptr_line != '\0')
		(*ptr_line)++;
}
