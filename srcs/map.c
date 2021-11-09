/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:39:10 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/09 17:57:25 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall(t_info	*info, double lenght, double x, double *c, double angle)
{
	double	plane;
	double	slice;
	double	top;
	double	y;
	int		txt_x;
	int		txt_y;

	plane = round((info->x / 2.0) / tan(to_radian(info->fov / 2.0)));
	slice = ceil((info->cub / lenght) * plane);
	top = round((info->y / 2.0) - (slice / 2.0));
	if (c[2] == -2)
    	txt_x = fmod(c[1] / info->cub, 1.0) * 64.0;
	else
		txt_x = fmod(c[0] / info->cub, 1.0) * 64.0;
	y = -1;
	while (++y < slice)
	{
		txt_y = (1.0 - ((top + slice) - (top + y)) / slice) * 64.0;
		if (c[2] == -2)
		{
			if (angle > 90 && angle <= 270)
			{
				if (x >= 0 && top + y >= 0 && x < info->x && top + y < info->y)
					my_mlx_pixel_put(&info->img, x, top + y, mlx_pixel_get(&info->we, txt_x, txt_y));
			}
			else
			{
				if (x >= 0 && top + y >= 0 && x < info->x && top + y < info->y)
					my_mlx_pixel_put(&info->img, x, top + y, mlx_pixel_get(&info->ea, txt_x, txt_y));
			}
		}
		else
		{	
			if (angle <= 180 && angle > 0)
			{
				if (x >= 0 && top + y >= 0 && x < info->x && top + y < info->y)
					my_mlx_pixel_put(&info->img, x, top + y, mlx_pixel_get(&info->no, txt_x, txt_y));
			}
			else
			{
				if (x >= 0 && top + y >= 0 && x < info->x && top + y < info->y)
					my_mlx_pixel_put(&info->img, x, top + y, mlx_pixel_get(&info->so, txt_x, txt_y));
			}
		}
	}
}

void	player_view(t_info *info)
{
	double		c[3];
	double		angle;
	double		beta;
	double		lenght;
	double		i;

	beta = info->fov / 2.0;
	angle = info->angle - info->fov / 2.0;
	i = info->x;
	while (i)
	{
		if (angle > 360.0)
			angle -= 360.0;
		if (angle < 0.0)
			angle += 360.0;
		lenght = find_wall(info, c, angle);
		lenght = lenght * cos(to_radian(beta));
		wall(info, lenght, i, c, angle);
		angle += info->fov / info->x;
		if (i > info->x / 2.0)
			beta -= info->fov / info->x;
		else
			beta += info->fov / info->x;
		i--;
	}
}

void	map(t_info *info)
{
	player_view(info);
}