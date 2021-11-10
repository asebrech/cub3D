/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:55:01 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/10 16:23:26 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	look_left(t_info *info, double v)
{
	info->angle += v;
	if (info->angle > 360.0)
		info->angle -= 360.0;
	print_screen(info);
}

void	look_right(t_info *info, double v)
{
	info->angle -= v;
	if (info->angle < 0.0)
		info->angle += 360.0;
	print_screen(info);
}

void	move_up(t_info *info, double cub, double mini, double angle)
{
	info->px = round(cos(to_radian(angle)) * cub) + info->px;
	info->py = round(sin(to_radian(angle)) * cub) * -1.0 + info->py;
	info->minipx = round(cos(to_radian(angle)) * mini) + info->minipx;
	info->minipy = round(sin(to_radian(angle)) * mini) * -1.0 + info->minipy;
	print_screen(info);
}

void	move_down(t_info *info, double cub, double mini, double angle)
{
	info->px = round(cos(to_radian(angle)) * cub) * -1.0 + info->px;
	info->py = round(sin(to_radian(angle)) * cub) + info->py;
	info->minipx = round(cos(to_radian(angle)) * mini) * -1.0 + info->minipx;
	info->minipy = round(sin(to_radian(angle)) * mini) + info->minipy;
	print_screen(info);
}

void	move(t_info *info, int keycode)
{
	double	v;
	double	m;
	double	cub;
	double	mini;

	m = 4.0;
	v = info->fov / 12.0;
	cub = info->cub / m;
	mini = info->minicub / m;
	if (keycode == 13)
		move_up(info, cub, mini, info->angle);
	if (keycode == 1)
		move_down(info, cub, mini, info->angle);
	if (keycode == 0)
		move_up(info, cub, mini, info->angle + 90.0);
	if (keycode == 2)
		move_up(info, cub, mini, info->angle - 90.0);
	if (keycode == 123)
		look_left(info, v);
	if (keycode == 124)
		look_right(info, v);
}
