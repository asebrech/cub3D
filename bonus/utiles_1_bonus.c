/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:22:55 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/13 18:39:46 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	player_start(int i, int j, t_info *info)
{
	info->px = j * info->cub + info->cub / 2;
	info->py = i * info->cub + info->cub / 2;
	info->minipx = j * info->minicub + info->minicub / 2;
	info->minipy = i * info->minicub + info->minicub / 2;
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

int	ft_close(t_info *info)
{
	ft_exit(NULL, info, 0);
	return (0);
}

int	render_next_frame(t_info *info)
{
	int		x;
	int		y;

	mlx_mouse_get_pos(info->win, &x, &y);
	info->mouse = x - (info->x / 2);
	move(info);
	mlx_mouse_move(info->win, info->x / 2, info->y / 2);
	return (0);
}
