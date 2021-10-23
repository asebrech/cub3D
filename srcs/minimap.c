/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:36:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/23 16:50:57 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda(float *x, float *y, t_info *info)
{
	int		dx;
	int		dy;
	int		step;
	float	xinc;
	float	yinc;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	xinc = dx / step;
	yinc = dy / step;
	while (step > 0)
	{
		mlx_pixel_put(info->mlx, info->win,
			round(x[0]), round(y[0]), 0x00FF0000);
		x[0] = x[0] + xinc;
		y[0] = y[0] + yinc;
		step--;
	}	
}

void	print_dir(int i, int j, t_info *info)
{
	float	x[2];
	float	y[2];

	x[0] = j * info->minicub + info->minicub / 2;
	x[1] = j * info->minicub + info->minicub;
	y[0] = i * info->minicub + info->minicub / 2;
	y[1] = i * info->minicub + info->minicub;
	dda(x, y, info);
}

void	print_p(int i, int j, t_info *info)
{
	int		k;
	int		l;
	int		x;
	int		y;

	x = j * info->minicub + info->minicub / 4;
	y = i * info->minicub + info->minicub / 4;
	l = -1;
	while (++l < info->minicub / 2)
	{
		k = -1;
		while (++k < info->minicub / 2)
		{
			if (info->map[i][j])
				mlx_pixel_put(info->mlx, info->win, x + k, y, 0x0000FF00);
		}
		y++;
	}
}

void	print_cub(int i, int j, t_info *info)
{
	int		k;
	int		l;
	int		x;
	int		y;

	x = j * info->minicub;
	y = i * info->minicub;
	l = 0;
	while (++l < info->minicub)
	{
		k = 0;
		while (++k < info->minicub)
		{
			if (info->map[i][j])
				mlx_pixel_put(info->mlx, info->win, x + k, y, 0x000000FF);
		}
		y++;
	}
}

void	minimap(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	while (info->map[++i] != NULL)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == '1')
				print_cub(i, j, info);
			else if (info->map[i][j] == info->player)
			{
				print_p(i, j, info);
				print_dir(i, j, info);
			}
		}
	}
}
