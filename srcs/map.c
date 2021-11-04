/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:39:10 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/04 18:51:11 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall(t_info	*info, double lenght, double x)
{
	double	plane;
	double	slice;
	double	top;
	double	i;

	plane = round((info->x / 2.0) / tan(to_radian(info->fov / 2.0)));
	slice = ceil((info->cub / lenght) * plane);
	top = round((info->y / 2.0) - (slice / 2.0));
	i = -1;
	while (++i < slice)
		if (x >= 0 && top + i >= 0 && x < info->x && top + i < info->y)
			my_mlx_pixel_put(info, x, top + i, 0x00FF0000);
}

void	player_view(t_info *info)
{
	double		c[2];
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
		wall(info, lenght, i);
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