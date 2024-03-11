/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:31:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/11 00:03:50 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

typedef struct s_data		t_data;
typedef struct s_mlx_info	t_mlx_info;

void	init_hooks(t_data *data);

int		call_destroynotify_handler(t_mlx_info *mlx_info);

#endif