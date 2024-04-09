/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intensified_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:07:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/09 21:19:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

t_color	get_intensified_color(t_color color, double intensity)
{
	return ((t_color){
		.r = ft_dmin(color.r * intensity, 255),
		.g = ft_dmin(color.g * intensity, 255),
		.b = ft_dmin(color.b * intensity, 255),
	});
}
