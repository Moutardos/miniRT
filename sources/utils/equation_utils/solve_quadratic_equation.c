/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic_equation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:59:03 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/17 22:35:11 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "minirt.h"

t_quadratic_roots	solve_quadratic_equation(double a, double b, double c)
{
	double				discriminant;
	double				discriminant_sqrt;
	t_quadratic_roots	roots;

	discriminant = b * b - 4 * a * c;
	discriminant_sqrt = sqrt(ft_dabs(discriminant));
	if (are_doubles_equals(discriminant_sqrt, 0))
	{
		roots.nb = 1;
		roots.single[0] = -b / (2 * a);
	}
	else if (discriminant < 0)
	{
		roots.nb = 0;
		roots.none = NULL;
	}
	else
	{
		roots.nb = 2;
		roots.distincts[0] = (-b + discriminant_sqrt) / (2 * a);
		roots.distincts[1] = (-b - discriminant_sqrt) / (2 * a);
	}
	return (roots);
}
