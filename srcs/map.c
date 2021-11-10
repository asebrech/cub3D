/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:39:10 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/10 16:21:08 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_v(t_info *info, double x, double y, double angle)
{
	if (angle > 90 && angle <= 270)
	{
		if (x >= 0 && y >= 0 && x < info->x && y < info->y)
			my_mlx_pixel_put(&info->img, x, y,
				mlx_pixel_get(&info->we, info->txt_x, info->txt_y));
	}
	else
	{
		if (x >= 0 && y >= 0 && x < info->x && y < info->y)
			my_mlx_pixel_put(&info->img, x, y,
				mlx_pixel_get(&info->ea, info->txt_x, info->txt_y));
	}
}

void	print_h(t_info *info, double x, double y, double angle)
{
	if (angle <= 180 && angle > 0)
	{
		if (x >= 0 && y >= 0 && x < info->x && y < info->y)
			my_mlx_pixel_put(&info->img, x, y,
				mlx_pixel_get(&info->no, info->txt_x, info->txt_y));
	}
	else
	{
		if (x >= 0 && y >= 0 && x < info->x && y < info->y)
			my_mlx_pixel_put(&info->img, x, y,
				mlx_pixel_get(&info->so, info->txt_x, info->txt_y));
	}
}

double	extremely_dumb_norm(t_info *info)
{
	if (info->wall_type == 'v')
		info->txt_x = fmod(info->wall_y / info->cub, 1.0) * info->cub;
	else
		info->txt_x = fmod(info->wall_x / info->cub, 1.0) * info->cub;
	return (ceil((info->cub / info->wall_len) * info->plane));
}

void	wall(t_info	*info, double x, double angle)
{
	double	slice;
	double	top;
	double	y;

	slice = extremely_dumb_norm(info);
	top = round((info->y / 2.0) - (slice / 2.0));
	y = -1;
	while (++y < info->y)
	{
		if (y < top && x >= 0 && y >= 0 && x < info->x && y < info->y)
			my_mlx_pixel_put(&info->img, x, y,
				create_trgb(0, info->cr, info->cg, info->cb));
		else if (y >= slice + top && x >= 0 && y >= 0
			&& x < info->x && y < info->y)
			my_mlx_pixel_put(&info->img, x, y,
				create_trgb(0, info->fr, info->fg, info->fb));
		else
		{
			info->txt_y = (1.0 - ((top + slice) - y) / slice) * info->cub;
			if (info->wall_type == 'v')
				print_v(info, x, y, angle);
			else
				print_h(info, x, y, angle);
		}
	}
}

void	map(t_info *info)
{
	double		angle;
	double		beta;
	double		x;

	beta = info->fov / 2.0;
	angle = info->angle - info->fov / 2.0;
	x = info->x;
	while (x)
	{
		if (angle > 360.0)
			angle -= 360.0;
		if (angle < 0.0)
			angle += 360.0;
		find_wall(info, angle);
		if (info->wall_len < 1.0)
			info->wall_len = info->cub / 4;
		info->wall_len = info->wall_len * cos(to_radian(beta));
		wall(info, x, angle);
		angle += info->fov / info->x;
		if (x > info->x / 2.0)
			beta -= info->fov / info->x;
		else
			beta += info->fov / info->x;
		x--;
	}
}
