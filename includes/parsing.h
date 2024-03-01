/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:57:07 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/01 21:59:51 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

# include "objects.h"

# define DECIMAL_PRECISION 5

int		extract_point(t_point *point, char **ptr_line);
int		extract_vector(t_vector *vector, char **ptr_line);
int		extract_color(t_color *color, char **ptr_line);
bool	is_single_argument(int argc);

#endif
