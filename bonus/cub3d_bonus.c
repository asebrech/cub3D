/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:18:50 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/14 13:40:07 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	key_hook(int keycode, t_info *info)
{
	//printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->win);
		ft_exit(NULL, info, 0);
	}
	if (keycode == 13)
		info->up = 1;
	if (keycode == 1)
		info->down = 1;
	if (keycode == 2)
		info->left = 1;
	if (keycode == 0)
		info->right = 1;
	if (keycode == 123)
		info->lookl = 1;
	if (keycode == 124)
		info->lookr = 1;
	if (keycode == 257)
		info->run = 1;
	return (0);
}

int	key_relese(int keycode, t_info *info)
{
	if (keycode == 13)
		info->up = 0;
	if (keycode == 1)
		info->down = 0;
	if (keycode == 2)
		info->left = 0;
	if (keycode == 0)
		info->right = 0;
	if (keycode == 123)
		info->lookl = 0;
	if (keycode == 124)
		info->lookr = 0;
	if (keycode == 257)
		info->run = 0;
	return (0);
}

void	get_xpm(t_info *info)
{
	info->no.img = mlx_xpm_file_to_image(info->mlx,
			info->cno, &info->w, &info->h);
	info->so.img = mlx_xpm_file_to_image(info->mlx,
			info->cso, &info->w, &info->h);
	info->we.img = mlx_xpm_file_to_image(info->mlx,
			info->cwe, &info->w, &info->h);
	info->ea.img = mlx_xpm_file_to_image(info->mlx,
			info->cea, &info->w, &info->h);
	info->no.addr = mlx_get_data_addr(info->no.img, &info->no.bits_per_pixel,
			&info->no.line_length, &info->no.endian);
	info->so.addr = mlx_get_data_addr(info->so.img, &info->so.bits_per_pixel,
			&info->so.line_length, &info->so.endian);
	info->ea.addr = mlx_get_data_addr(info->ea.img, &info->ea.bits_per_pixel,
			&info->ea.line_length, &info->ea.endian);
	info->we.addr = mlx_get_data_addr(info->we.img, &info->we.bits_per_pixel,
			&info->we.line_length, &info->we.endian);
}

void	print_screen(t_info *info)
{
	info->img.img = mlx_new_image(info->mlx, info->x, info->y);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits_per_pixel,
			&info->img.line_length, &info->img.endian);
	map(info);
	minimap(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_destroy_image(info->mlx, info->img.img);
	sprite(info);
}

int	mouse(int x , int y, t_info *info)
{
	info->mousex = x;
	(void)y;
	return (0);
}

void	cub3d(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->x, info->y, "cub3D");
	mlx_hook(info->win, 2, 1L << 0, key_hook, info);
	mlx_hook(info->win, 3, 1L << 1, key_relese, info);
	mlx_hook(info->win, 6, 1L << 7, mouse, info);
	mlx_hook(info->win, 17, 1L << 15, ft_close, info);
	get_xpm(info);
	mlx_mouse_hide();
	mlx_mouse_move(info->win, info->x / 2.0, info->y / 2.0);
	mlx_do_key_autorepeatoff(info->mlx);
	print_screen(info);
	mlx_loop_hook(info->mlx, render_next_frame, info);
	mlx_loop(info->mlx);
}
