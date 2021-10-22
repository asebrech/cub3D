/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:53:07 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/22 16:18:44 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		//mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	/*else
		move(info, keycode); */
	info = NULL;
	return (0);
}

static int	ft_close(int keycode, t_info *info)
{
	keycode = 0;
	info = NULL;
	exit(0);
	return (0);
}

void	cub3d(t_info *info)
{
	info->x = 1800;
	info->y = 900;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->x, info->y, "cub3D");
	mlx_hook(info->win, 2, 1L << 0, key_hook, &info);
	mlx_hook(info->win, 17, 1L << 15, ft_close, &info);
	minimap(info);
	mlx_loop(info->mlx);
}
