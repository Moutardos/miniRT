/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:18:01 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/17 13:48:19 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "minirt.h"
#include "mlx.h"

int	call_destroynotify_handler(t_mlx_info *mlx_info)
{
	mlx_loop_end(mlx_info->mlx_ptr);
	return (0);
}

void	handle_camera(int keycode, t_camera *camera, t_frame *frame)
{
	if (keycode == XK_w || keycode == XK_s
		|| keycode == XK_a || keycode == XK_d
		|| keycode == XK_r || keycode == XK_f)
		handle_camera_translations(keycode, camera, frame);
	if (keycode == XK_Up || keycode == XK_Down
		|| keycode == XK_Right || keycode == XK_Left)
		handle_camera_rotations(keycode, camera, frame);
}

void	handle_objects(int keycode,
			t_camera *camera, t_frame *frame, t_object_array *object_array)
{
	static int		i;
	static t_color	og_color;

	if (keycode == XK_c || keycode == XK_l)
		object_array->array[i].texture.color = og_color;
	else if (keycode == XK_o)
		update_object_color(&og_color, &object_array->array[i].texture.color);
	else if (keycode == XK_n)
	{
		object_array->array[i].texture.color = og_color;
		i++;
		if (i == object_array->len)
			i = 0;
		update_object_color(&og_color, &object_array->array[i].texture.color);
	}
	update_object_properties(keycode, camera, frame, &object_array->array[i]);
}

void	handle_light(int keycode, t_data *data, t_light_array *light_array)
{
	static int		i = 0;

	if (keycode == XK_n)
	{
		i++;
		if (i == light_array->len)
			i = 0;
	}
	handle_translations(keycode, &data->settings.camera,
		&data->frame, &light_array->array[i].point);
}

int	call_keypress_handler(int keycode, t_data *data)
{
	static int	target_keycode = XK_c;

	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx_info.mlx_ptr);
	if (keycode == target_keycode)
		return (0);
	if (keycode == XK_c || keycode == XK_o || keycode == XK_l)
	{
		if ((keycode == XK_o || target_keycode == XK_o)
			&& data->object_array.len)
			handle_objects(keycode, &data->settings.camera,
				&data->frame, &data->object_array);
		target_keycode = keycode;
		reload_scene(data);
		return (0);
	}
	if (target_keycode == XK_c)
		handle_camera(keycode, &data->settings.camera, &data->frame);
	else if (target_keycode == XK_o && data->object_array.len)
		handle_objects(keycode, &data->settings.camera,
			&data->frame, &data->object_array);
	else if (target_keycode == XK_l && data->settings.light_array.len)
		handle_light(keycode, data, &data->settings.light_array);
	reload_scene(data);
	return (0);
}
