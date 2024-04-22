/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:43:07 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 02:10:07 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdlib.h>

typedef double	t_matrix_3x3[3][3];

typedef struct s_quadratic_roots
{
	int	nb;
	union
	{
		double	*none;
		double	single[1];
		double	distincts[2];
	};
}	t_quadratic_roots;

double				get_min_positive_root(t_quadratic_roots *roots);
t_quadratic_roots	solve_quadratic_equation(double a, double b, double c);

t_vector			multiply_vector_by_matrix(t_vector vector,
						t_matrix_3x3 matrix);
t_vector			rotate_vector_upside(t_vector obj_orientation,
						t_point hitpoint,
						t_point center);
void				get_rotation_matrix(t_matrix_3x3 rotation_matrix,
						double angle,
						t_vector axis);

t_vector			create_vector(t_point start_point, t_point end_point);
double				get_vector_magnitude(t_vector v);
bool				is_unit_vector(t_vector v);
t_vector			multiply_vector(double scalar, t_vector vector);
t_vector			normalize_vector(t_vector vector);
double				perform_dot_product(t_vector vector1, t_vector vector2);
t_vector			perform_cross_product(t_vector vector1, t_vector vector2);
t_vector			sum_vectors(t_vector vector1, t_vector vector2);
t_point				rotate_point(t_point point, t_vector rotate);
t_point				translate_point(t_point point, t_vector vector);

#endif
