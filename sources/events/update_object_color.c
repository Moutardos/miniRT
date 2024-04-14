/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_objects_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:28:37 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/14 15:33:57 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

void	update_object_color(t_color *og_color, t_color *object_color)
{
	*og_color = *object_color;
	*object_color = (t_color){
		.r = ft_min(og_color->r + RGB_INCR, 255),
		.g = ft_min(og_color->g + RGB_INCR, 255),
		.b = ft_min(og_color->b + RGB_INCR, 255)
	};
}
