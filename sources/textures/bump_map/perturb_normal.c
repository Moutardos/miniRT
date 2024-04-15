/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturb_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:10:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/15 02:39:23 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "minirt.h"

void	fill_tbn(t_matrix_3x3 tbn, t_vector tangent,
				t_vector bitangent, t_vector normal)
{
	tbn[0][0] = tangent.x;
	tbn[0][1] = tangent.y;
	tbn[0][2] = tangent.z;
	tbn[1][0] = bitangent.x;
	tbn[1][1] = bitangent.y;
	tbn[1][2] = bitangent.z;
	tbn[2][0] = normal.x;
	tbn[2][1] = normal.y;
	tbn[2][2] = normal.z;
}

t_vector	multiply_vector_by_3x3matrix(t_vector vector, t_matrix_3x3 matrix)
{
	return ((t_vector){
		.x = vector.x * matrix[0][0]
			+ vector.y * matrix[1][0] + vector.z * matrix[2][0],
		.y = vector.x * matrix[0][1]
			+ vector.y * matrix[1][1] + vector.z * matrix[2][1],
		.z = vector.x * matrix[0][2]
			+ vector.y * matrix[1][2] + vector.z * matrix[2][2],
	});
}

t_vector	get_normal_bump_map(t_texture_coordinates coord, t_bump_map *map)
{
	int	i;
	int	j;

	i = ft_dclamp(roundf(coord.x * (map->width - 1)), 0, map->width - 1);
	j = ft_dclamp(roundf(coord.y * (map->height - 1)), 0, map->height - 1);
	return ((*map->map)[i * (map->width) + j]);
}

void	get_tbn_matrix(t_matrix_3x3 tbn, t_point_info *point_info)
{
	t_vector	tangent;
	t_vector	bitangent;

	if (point_info->object->type == CO)
		tangent = perform_cross_product(point_info->object->cone.vector,
				point_info->surface_normal);
	else if (point_info->object->type == PL)
		tangent = perform_cross_product(point_info->object->plane.vector,
				(t_vector) {1,0,0});
	else if (point_info->object->type == CY)
		tangent = perform_cross_product(point_info->object->cylinder.vector,
				point_info->surface_normal);
	else
		tangent = perform_cross_product((t_vector){0, 0, 1},
				point_info->surface_normal);
	bitangent = perform_cross_product(tangent, point_info->surface_normal);
	fill_tbn(tbn, tangent, bitangent, point_info->surface_normal);
}

t_vector	perturb_normal(t_point_info *point_info)
{
	t_texture_coordinates	coord;
	t_vector				bump_normal;
	t_matrix_3x3			tbn;

	coord = point_to_texture_coordinates(point_info);
	get_tbn_matrix(tbn, point_info);
	bump_normal = get_normal_bump_map(coord, &point_info->object->texture.map);
	bump_normal = normalize_vector(sum_vectors(multiply_vector(2, bump_normal), (t_vector){-1,-1,-1}));
	return (normalize_vector(multiply_vector_by_3x3matrix(bump_normal, tbn)));
}
