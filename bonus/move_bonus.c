/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:55:01 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/14 18:04:09 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	look_left(t_info *info, double v)
{
	if (abs(info->mouse) && info->mouse != 0)
		v = (double)abs(info->mouse) / 30;
	info->angle += v;
	if (info->angle > 360.0)
		info->angle -= 360.0;
	//print_screen(info);
}

void	look_right(t_info *info, double v)
{
	if (info->mouse && info->mouse != 0)
		v = (double)info->mouse / 30;
	info->angle -= v;
	if (info->angle < 0.0)
		info->angle += 360.0;
	//print_screen(info);
}

void	move_up(t_info *info, double cub, double angle)
{
	double	y;
	double	x;
	int		tmpy;
	int		tmpx;

	x = round(cos(to_radian(angle)) * cub) + info->px;
	y = round(sin(to_radian(angle)) * cub) * -1.0 + info->py;
	tmpx = floor(x / info->cub);
	tmpy = floor(y / info->cub);
	if (info->map[(int)floor(info->py / info->cub)][tmpx] != '1')
	{
		info->px = x;
		info->minipx = x / 6.0;
	}
	if (info->map[tmpy][(int)floor(info->px / info->cub)] != '1')
	{	
		info->py = y;
		info->minipy = y / 6.0;
	}
	//print_screen(info);
}

void	move(t_info *info)
{
	double	v;
	double	m;
	double	cub;
	double	mini;

	if (info->run)
		m = 3.0;
	else
		m = 5.0;
	v = info->fov / 12.0;
	cub = info->cub / m;
	mini = info->minicub / m;
	if (info->lookl || info->mouse < 0)
		look_left(info, v);
	if (info->lookr || info->mouse > 0)
		look_right(info, v);
	if (info->right)
		move_up(info, cub / 2.0, info->angle + 90.0);
	if (info->left)
		move_up(info, cub / 2.0, info->angle - 90.0);
	if (info->up)
		move_up(info, cub, info->angle);
	if (info->down)
		move_up(info, cub, info->angle + 180);
	print_screen(info);
}
