/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_single_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:24:46 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/06 21:57:16 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_single_argument(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("No argument was given\n", 2);
		return (false);
	}
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Too many arguments were given\n", 2);
		return (false);
	}
	return (true);
}
