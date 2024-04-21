/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colored_intensity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:04:53 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/21 21:15:54 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_colored_intensity(t_color_intensity color_intensity,
				t_color light_color, double intensity)
{
	color_intensity[0] += light_color.r / 255.0 * intensity;
	color_intensity[1] += light_color.g / 255.0 * intensity;
	color_intensity[2] += light_color.b / 255.0 * intensity;
}
