/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_positive_root.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:03:38 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/26 02:13:09 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_min_positive_root(t_quadratic_roots *roots)
{
	if (roots->nb == 1)
		return (roots->single[0]);
	if (roots->distincts[1] < 0)
		return (roots->distincts[0]);
	else if (roots->distincts[0] < 0)
		return (roots->distincts[1]);
	else
		return (ft_dmin(roots->distincts[0], roots->distincts[1]));
}
