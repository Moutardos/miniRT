/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:56:05 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/27 00:02:48 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdint.h>

typedef struct s_data	t_data;
typedef struct s_img	t_img;

typedef union u_color
{
	uint32_t	hex;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
}	t_color;

void	find_pix_color(unsigned int i, unsigned int j, t_data *data);

t_color	get_intensified_color(t_color color, double intensity);

void	color_img_pix(t_img *img, int x, int y, int color);

#endif
