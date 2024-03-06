/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:57 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/07 00:18:43 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "minirt.h"

static void debug_print_rgb(t_color color)
{
	printf("(%X)", color.hex);
}

static void debug_print_point(t_point p)
{
	printf("(%lf,%lf,%lf)", p.x, p.y, p.z);
}

static void debug_print_vector(t_vector v)
{
	printf("(%lf,%lf,%lf)", v.x, v.y, v.z);
}

static void debug_data(t_data data)
{
	printf("A : %lf ", data.settings.env_light.ratio);
	debug_print_rgb(data.settings.env_light.color);
	printf("\n");
	printf("C : ");
	debug_print_point(data.settings.camera.point);
	debug_print_vector(data.settings.camera.vector);
	printf("%c\n", data.settings.camera.fov);
	printf("\n");
	printf("L : ");
	debug_print_point(data.settings.light.point);
	printf("%lf ", data.settings.light.ratio);
	debug_print_rgb(data.settings.light.color);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!is_single_argument(argc))
		return (1);
	if (init_data(&data, argv[1]))
		return (1);
	// destroy_data(&data);
	debug_data(data);
}