/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:59:13 by ekhaled           #+#    #+#             */
/*   Updated: 2024/03/08 11:43:54 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INFO_H
# define MLX_INFO_H

# define WIN_W 1920
# define WIN_H 1080

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx_info;

int		init_mlx_info(t_mlx_info *mlx_info);
void	destroy_mlx_info(t_mlx_info *mlx_info);

#endif
