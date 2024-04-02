/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:29:44 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/02 08:25:41 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "minirt.h"

void	handle_rotations(int keycode, t_vector *direction)
{
	if (keycode == XK_Up)
		*direction = (t_vector){0, 1, 0};
	else if (keycode == XK_Down)
		*direction = (t_vector){0, -1, 0};
	else if (keycode == XK_Right)
		*direction = (t_vector){1, 0, 0};
	else if (keycode == XK_Left)
		*direction = (t_vector){-1, 0, 0};
	else if (keycode == XK_Tab)
		*direction = (t_vector){0, 0, 1};
	else if (keycode == XK_Shift_L)
		*direction = (t_vector){0, 0, -1};
}
