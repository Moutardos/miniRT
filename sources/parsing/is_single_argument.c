/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_single_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:24:46 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/24 00:34:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "minirt.h"

bool	is_single_argument(int argc)
{
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		write(2, "No argument was given\n", 22);
		return (false);
	}
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		write(2, "Too many arguments were given\n", 30);
		return (false);
	}
	return (true);
}
