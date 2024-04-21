/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:04:14 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/20 23:09:03 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "minirt.h"

void	init_dirs(t_vector *dir_j, t_vector *dir_i, t_vector *dir_cam)
{
	t_vector	dir_up;

	dir_up = (t_vector){0, 1, 0};
	if (are_doubles_equals(ft_dabs(dir_cam->y), 1))
	{
		*dir_i = (t_vector){-1, 0, 0};
		if (are_doubles_equals(dir_cam->y, 1))
			*dir_j = (t_vector){0, 0, -1};
		else
			*dir_j = (t_vector){0, 0, 1};
	}
	else
	{
		*dir_j = perform_cross_product(*dir_cam, dir_up);
		*dir_i = perform_cross_product(*dir_cam, *dir_j);
	}
}

t_point	get_frame_origin(t_frame *frame, t_camera *camera)
{
	t_vector	o_oframe;

	o_oframe = sum_vectors(
			sum_vectors(
				create_vector((t_point){0, 0, 0}, camera->point),
				camera->vector
				), sum_vectors(
				multiply_vector(-frame->height * 0.5, frame->dir_i),
				multiply_vector(-frame->width * 0.5, frame->dir_j)
				)
			);
	return (translate_point((t_point){0, 0, 0}, o_oframe));
}

void	init_frame(t_frame *frame, t_camera *camera)
{
	init_dirs(&frame->dir_j, &frame->dir_i, &camera->vector);
	frame->width = 2 * tan(camera->fov * M_PI / 360);
	frame->height = (frame->width / WIN_W) * WIN_H;
	frame->delta_x = frame->width / WIN_W;
	frame->delta_y = frame->height / WIN_H;
	frame->origin = get_frame_origin(frame, camera);
}
