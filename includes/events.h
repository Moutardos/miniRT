/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:31:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/01 22:31:52 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define STEP 1
# define DIM 1
# define RGB_INCR 50

enum e_mouse_buttons
{
	LEFT_CLICK = 1,
	RIGHT_CLICK,
	MIDDLE_CLICK,
	SCROLL_UP,
	SCROLL_DOWN
};

typedef struct s_point			t_point;
typedef struct s_vector			t_vector;

typedef struct s_camera			t_camera;

void	init_hooks(t_data *data);

int		call_destroynotify_handler(t_mlx_info *mlx_info);
int		call_keypress_handler(int keycode, t_data *data);


void	handle_translations(int keycode, t_point *point);
void	handle_rotations(int keycode, t_vector *direction);


void	reload_scene(t_data *data);

#endif
