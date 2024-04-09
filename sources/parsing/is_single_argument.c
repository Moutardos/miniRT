/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_single_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:24:46 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/09 21:20:43 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libft.h"
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
