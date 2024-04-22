/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturb_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:10:26 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/22 02:32:08 by lcozdenm         ###   ########.fr       */
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

t_vector	get_normal_bump_map(t_texture_coordinates coord,
			t_bump_map *bump_map)
{
	int	i;
	int	j;

	i = ft_dclamp(roundf(coord.x * (bump_map->img.width - 1)), 0,
			bump_map->img.width - 1);
	j = ft_dclamp(roundf(coord.y * (bump_map->img.height - 1)), 0,
			bump_map->img.height - 1);
	return (bump_map->map[j * (bump_map->img.width) + i]);
}

t_vector	get_cone_tangent(t_point_info *point_info)
{
	if (are_doubles_equals(ft_dabs(perform_dot_product(point_info->normal,
					point_info->object->cone.utils.induced_plane2.vector)), 1))
	{
		return (perform_cross_product(point_info->object->cylinder.vector,
				(t_vector){1, 0, 0}));
	}
	else
	{
		return (perform_cross_product(point_info->object->cone.vector,
				point_info->surface_normal));
	}
}

void	get_tbn_matrix(t_matrix_3x3 tbn, t_point_info *point_info)
{
	t_vector	tangent;
	t_vector	bitangent;

	if (point_info->object->type == PL)
		tangent = perform_cross_product(point_info->object->plane.vector,
				(t_vector){1, 0, 0});
	else if (point_info->object->type == CY)
	{
		if (are_doubles_equals(ft_dabs(perform_dot_product(point_info->normal,
						point_info->object->cylinder.utils
						.induced_plane1.vector)), 1))
			tangent = perform_cross_product(point_info->object->cylinder.vector,
					(t_vector){1, 0, 0});
		else
			tangent = perform_cross_product(point_info->object->cylinder.vector,
					point_info->surface_normal);
	}
	else if (point_info->object->type == CO)
		tangent = get_cone_tangent(point_info);
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
	bump_normal = get_normal_bump_map(
			coord, point_info->object->texture.bump_map);
	return (normalize_vector(multiply_vector_by_matrix(bump_normal, tbn)));
}
