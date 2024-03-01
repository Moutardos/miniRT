/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_single_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:24:46 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/01 22:03:26 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

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
