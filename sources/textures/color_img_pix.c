/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_img_pix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:44:09 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/19 18:43:24 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	color_img_pix(t_img *img, int x, int y, int color)
{
	*(int *)(img->addr + (img->size_line * y + x * 4)) = color;
}
