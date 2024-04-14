/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:57:07 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/12 14:50:32 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

# include "objects.h"

# define DECIMAL_PRECISION 5

int		extract_int(int *value, char **ptr_line);
int		extract_double(double *value, char **ptr_line);

int		extract_point(t_point *point, char **ptr_line);
int		extract_vector(t_vector *vector, char **ptr_line);
int		extract_unit_vector(t_vector *vector, char **ptr_line);
int		extract_color(t_color *color, char **ptr_line);
int		extract_fov(uint8_t *fov, char **ptr_line);

void	ignore_space(char **ptr_line);

bool	str_to_obj(char *str, enum e_object_type *obj);
bool	str_to_texture(char *str, t_texture *texture);

int		file_check(int *fd, char *file);
bool	is_single_argument(int argc);

#endif
