/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:10:29 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/11 17:44:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct s_data	t_data;
typedef struct s_camera	t_camera;

void		run_rt(t_data *data);

void		find_pix_color(unsigned int i, unsigned int j, t_data *data);

t_vector	compute_ray(unsigned int i, unsigned int j, t_camera *camera);


t_vector	create_vector(t_point start_point, t_point end_point);
double		get_vector_magnitude(t_vector v);
t_vector	normalize_vector(t_vector vector);
t_vector	sum_vectors(t_vector vector1, t_vector vector2);
bool		is_unit_vector(t_vector v);

#endif
