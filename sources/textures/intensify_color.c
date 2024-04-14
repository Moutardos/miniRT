/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensify_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:07:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/11 14:37:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

void	intensify_color(t_color *color, t_color_intensity color_intensity)
{
	color->r = ft_dmin(color->r * color_intensity[0], 255);
	color->g = ft_dmin(color->g * color_intensity[1], 255);
	color->b = ft_dmin(color->b * color_intensity[2], 255);
}
