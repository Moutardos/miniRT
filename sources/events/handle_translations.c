/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_translations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:29:32 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/02 08:26:00 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "minirt.h"

void	handle_translations(int keycode, t_point *point)
{
	if (keycode == XK_w)
		point->z += STEP;
	else if (keycode == XK_s)
		point->z -= STEP;
	else if (keycode == XK_d)
		point->x += STEP;
	else if (keycode == XK_a)
		point->x -= STEP;
	else if (keycode == XK_r)
		point->y += STEP;
	else if (keycode == XK_f)
		point->y -= STEP;
}
