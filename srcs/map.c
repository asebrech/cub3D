/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:39:10 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/28 20:01:38 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall(t_info	*info, double lenght, double x)
{
	double	plane;
	double	slice;
	double	top;
	double	i;

	plane = round((info->x / 2) / tan(to_radian(info->fov / 2)));
	slice = ceil(info->cub / lenght * plane);
	printf("%f\n", lenght);
	top = round((info->y / 2) - (slice / 2));
	i = -1;
	while (++i < slice / 2)
		if (x >= 0 && top + i >= 0 && x <= info->x && top + i <= info->y)
			my_mlx_pixel_put(info, x, top + i, 0x00FF0000);
}

void	player_dir2(t_info *info)
{
	double		c[2];
	double		angle;
	double		beta;
	double		lenght;
	double		i;

	beta = info->fov / 2;
	angle = info->angle - info->fov / 2;
	i = -1.0;
	while (++i <= info->x)
	{
		if (angle > 360.0)
			angle -= 360.0;
		if (angle < 0.0)
			angle += 360.0;
		lenght = find_wall(info, c, angle);
		lenght = lenght * cos(to_radian(beta));
		wall(info, lenght, i);
		angle += info->fov / info->x;
		if (i < info->x / 2)
			beta -= info->fov / info->x;
		else
			beta += info->fov / info->x;
	}
}

void	map(t_info *info)
{
	player_dir2(info);
}
