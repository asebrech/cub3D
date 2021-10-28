/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:36:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/28 13:28:45 by asebrech         ###   ########.fr       */
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
			my_mlx_pixel_put(info, round(x[0]), round(y[0]), 0x00FF0000);
		x[0] = x[0] + xinc;
		y[0] = y[0] + yinc;
		step--;
	}	
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
	double		c[2];
	double		angle;
	double		i;

	angle = info->angle - info->fov / 2;
	i = -1.0;
	while (++i < info->plane)
	{
		if (angle > 360.0)
			angle -= 360.0;
		if (angle < 0.0)
			angle += 360.0;
		find_wall(info, c, angle);
		x[0] = info->px;
		y[0] = info->py;
		x[1] = c[0];
		y[1] = c[1];
		dda(x, y, info);
		angle += info->fov / info->plane;
	}
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
				my_mlx_pixel_put(info, x + j, y, 0x0000FF00);
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
				my_mlx_pixel_put(info, x + k, y, 0x000000FF);
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
	l = 0;
	while (++l < info->minicub)
	{
		k = 0;
		while (++k < info->minicub)
		{
			if (x + k <= info->x && y <= info->y)
				my_mlx_pixel_put(info, x + k, y, 0x00FFFFFF);
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
	info->img = mlx_new_image(info->mlx, info->x, info->y);
	info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel,
			&info->line_length, &info->endian);
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
		}
	}
	player_pos(info);
	//player_dir(info);
	player_dir2(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_destroy_image(info->mlx, info->img);
}
