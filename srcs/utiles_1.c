/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:22:55 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/10 11:15:30 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_start(int i, int j, t_info *info)
{
	info->px = j * info->cub + info->cub / 2;
	info->py = i * info->cub + info->cub / 2;
	if (info->player == 'N')
		info->angle = 90;
	else if (info->player == 'S')
		info->angle = 270;
	else if (info->player == 'E')
		info->angle = 360;
	else if (info->player == 'W')
		info->angle = 180;
}

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
		if (x[0] >= 0 && y[0] >= 0 && x[0] < info->x && y[0] < info->y)
			my_mlx_pixel_put(&info->img, round(x[0]), round(y[0]), 0x00FF0000);
		x[0] = x[0] + xinc;
		y[0] = y[0] + yinc;
		step--;
	}	
}
