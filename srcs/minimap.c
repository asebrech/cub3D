/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:36:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/26 15:50:18 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda(double *x, double *y, t_info *info)
{
	double	dx;
	double	dy;
	int		step;
	double	xinc;
	double	yinc;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xinc = dx / step;
	yinc = dy / step;
	while (step > 0)
	{
		if (x[0] >= 0 && y[0] >= 0 && x[0] <= info->x && y[0] <= info->y)
			mlx_pixel_put(info->mlx, info->win,
				round(x[0]), round(y[0]), 0x00FF0000);
		x[0] = x[0] + xinc;
		y[0] = y[0] + yinc;
		step--;
	}	
}

void	player_start(int i, int j, t_info *info)
{
	info->px = j * info->minicub + info->minicub / 2;
	info->py = i * info->minicub + info->minicub / 2;
	if (info->player == 'N')
		info->angle = 90;
	else if (info->player == 'S')
		info->angle = 270;
	else if (info->player == 'E')
		info->angle = 0;
	else if (info->player == 'W')
		info->angle = 260;
}

void	player_dir(t_info *info)
{
	double		x[2];
	double		y[2];

	x[0] = info->px;
	y[0] = info->py;
	x[1] = round(cos(to_radian(info->angle)) * info->minicub) + info->px;
	y[1] = round(sin(to_radian(info->angle)) * info->minicub) * -1 + info->py;
	dda(x, y, info);
}

void	player_dir2(t_info *info)
{
	double		x[2];
	double		y[2];
	double		a[2];
	double		b[2];

	find_wall(info, a, b);
	x[0] = info->px;
	y[0] = info->py;
	x[1] =	b[0];
	y[1] =	b[1];
	dda(x, y, info);
}

void	player_pos(t_info *info)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = info->px - info->minicub / 4;
	y = info->py - info->minicub / 4;
	i = -1;
	while (++i < info->minicub / 2)
	{
		j = -1;
		while (++j < info->minicub / 2)
		{
			if (x + j <= info->x && y <= info->y)
				mlx_pixel_put(info->mlx, info->win, x + j, y, 0x0000FF00);
		}
		y++;
	}
}

void	print_wall(int i, int j, t_info *info)
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
			if (x + k <= info->x && y <= info->y)
				mlx_pixel_put(info->mlx, info->win, x + k, y, 0x000000FF);
		}
		y++;
	}
}

void	print_floor(int i, int j, t_info *info)
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
			if ((x + k <= info->x && y <= info->y) && (l == 0 || l == info->minicub|| k == 0 || k == info->minicub))
				mlx_pixel_put(info->mlx, info->win, x + k, y, 0x00FF00FF);
		}
		y++;
	}
}

void	minimap(t_info *info)
{
	static int	p = 0;
	int			i;
	int			j;

	p++;
	i = -1;
	while (info->map[++i] != NULL)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == '1')
				print_wall(i, j, info);
			else if (info->map[i][j] != ' ')
				print_floor(i, j, info);
			if (info->map[i][j] == info->player && p == 1)
				player_start(i, j, info);
		}
	}
	player_pos(info);
	//player_dir(info);
	player_dir2(info);
}
