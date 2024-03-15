/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:42:38 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/15 03:31:35 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "minirt.h"

t_point	get_p_coords(unsigned int i, unsigned int j, t_camera *camera)
{
	t_point	p;

	p.x = (double) j - WIN_W / 2;
	p.y = WIN_H / 2 - (double) i;
	if (camera->fov == 0)
		p.z = 0;
	else
		p.z = - (WIN_W / (2 * tan((camera->fov * M_PI) / 90)));
	return (p);
}

t_vector	compute_ray(unsigned int i, unsigned int j, t_camera *camera)
{
	t_vector	co;
	t_vector	op;
	t_vector	cp;
	t_vector	u;

	co = create_vector(camera->point, (t_point){0, 0, 0});
	op = create_vector((t_point){0, 0, 0}, get_p_coords(i, j, camera));
	cp = sum_vectors(co, op);
	u = normalize_vector(cp);
	return (u);
}
