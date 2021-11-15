/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:36:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/15 13:36:22 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	player_dir(t_info *info)
{
	double		x[2];
	double		y[2];

	x[0] = info->minipx;
	y[0] = info->minipy;
	x[1] = round(cos(to_radian(info->angle)) * info->minicub) + info->minipx;
	y[1] = round(sin(to_radian(info->angle)) * info->minicub)
		* -1.0 + info->minipy;
	dda(x, y, info);
}

void	player_pos(t_info *info)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = info->minipx - info->minicub / 4;
	y = info->minipy - info->minicub / 4;
	i = -1;
	while (++i < info->minicub / 2.0)
	{
		j = -1;
		while (++j < info->minicub / 2.0)
		{
			if (x + j < info->x && y < info->y)
				my_mlx_pixel_put(&info->img, x + j, y, 0x0000FF00);
		}
		y++;
	}
}

void	very_dumb_norm(t_info *info, int k, int x, int y)
{
	if (x + k < info->x && y < info->y)
		my_mlx_pixel_put(&info->img, x + k, y, 0xb3b3ff);
}

void	print_wall(int i, int j, t_info *info, int bool)
{
	int		k;
	int		l;
	int		x;
	int		y;

	x = j * info->minicub;
	y = i * info->minicub;
	l = -1;
	while (++l < info->minicub)
	{
		k = -1;
		while (++k < info->minicub)
		{
			if (bool)
			{
				if (x + k < info->x && y < info->y)
					my_mlx_pixel_put(&info->img, x + k, y, 0x4646b9);
			}
			else
				very_dumb_norm(info, k, x, y);
		}
		y++;
	}
}

void	minimap(t_info *info)
{
	int			i;
	int			j;

	i = -1;
	while (info->map[++i] != NULL)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == '1')
				print_wall(i, j, info, 0);
			else if (info->map[i][j] != ' ')
				print_wall(i, j, info, 1);
		}
	}
	player_dir(info);
	player_pos(info);
}
