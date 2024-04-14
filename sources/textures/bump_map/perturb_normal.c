/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturb_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:10:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/14 20:08:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

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

	i = roundf(coord.x * (map->width - 1));
	j = roundf(coord.y * (map->height - 1));
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	if (i > map->width - 1)
		i = map->width - 1;
	if (j > map->height - 1)
		j = map->height - 1;
	return ((*map->map)[i * (map->width) + j]);
}

void	get_tbn_matrix(t_matrix_3x3 tbn, t_vector normal_facing, t_point_info *point_info)
{
	t_vector	tangent;
	t_vector	bitangent;

	tangent = perform_cross_product(point_info->object->cone.vector, point_info->normal);
	bitangent = perform_cross_product(tangent, normal_facing);
	tbn[0][0] = tangent.x;
	tbn[0][1] = tangent.y;
	tbn[0][2] = tangent.z;
	tbn[1][0] = bitangent.x;
	tbn[1][1] = bitangent.y;
	tbn[1][2] = bitangent.z;
	tbn[2][0] = normal_facing.x;
	tbn[2][1] = normal_facing.y;
	tbn[2][2] = normal_facing.z;
}

t_vector	perturb_normal(t_vector normal_facing, t_point_info *point_info)
{
	t_texture_coordinates	coord;
	t_vector				bump_normal;
	t_matrix_3x3			tbn;

	coord = point_to_texture_coordinates(point_info->object, point_info->point);
	if (point_info->object->type == PL)
		coord.y = coord.x;
	get_tbn_matrix(tbn, normal_facing, point_info);
	bump_normal = get_normal_bump_map(coord, &point_info->object->texture.map);
	bump_normal = normalize_vector(bump_normal);
	bump_normal = sum_vectors(
			multiply_vector(2, bump_normal), (t_vector){-1, -1, -1});
	return (multiply_vector_by_3x3matrix(bump_normal, tbn));
}
