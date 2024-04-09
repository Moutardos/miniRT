/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic_equation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:59:03 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 21:22:17 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "minirt.h"

t_quadratic_roots	solve_quadratic_equation(double a, double b, double c)
{
	double				discriminant;
	t_quadratic_roots	roots;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		roots.nb = 0;
		roots.none = NULL;
	}
	else if (are_doubles_equals(discriminant, 0))
	{
		roots.nb = 1;
		roots.single[0] = -b / (2 * a);
	}
	else
	{
		roots.nb = 2;
		roots.distincts[0] = (-b + sqrt(discriminant)) / (2 * a);
		roots.distincts[1] = (-b - sqrt(discriminant)) / (2 * a);
	}
	return (roots);
}
