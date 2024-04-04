/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:42:38 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/04 06:51:01 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "minirt.h"

t_point	get_p_coords(unsigned int i, unsigned int j, t_frame *frame)
{
	t_point	p;

	p = translate_point(frame->origin,
			sum_vectors(
				multiply_vector(frame->delta_x * j, frame->dir_j),
				multiply_vector(frame->delta_y * i, frame->dir_i)
				)
			);
	return (p);
}

t_vector	compute_ray(unsigned int i, unsigned int j,
				t_camera *camera, t_frame *frame)
{
	t_vector	cp;
	t_vector	u;

	cp = create_vector(camera->point, get_p_coords(i, j, frame));
	u = normalize_vector(cp);
	return (u);
}
