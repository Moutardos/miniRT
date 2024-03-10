/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_img_pix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:44:09 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/10 20:44:26 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	color_img_pix(t_img *img, int x, int y, int color)
{
	*(int *)(img->addr + (img->size_line * y + x * 4)) = color;
}
