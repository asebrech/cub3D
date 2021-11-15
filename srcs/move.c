/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:55:01 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/15 13:46:02 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	look_left(t_info *info, double v)
{
	info->angle += v;
	if (info->angle > 360.0)
		info->angle -= 360.0;
	//print_screen(info);
}

void	look_right(t_info *info, double v)
{
	info->angle -= v;
	if (info->angle < 0.0)
		info->angle += 360.0;
	//print_screen(info);
}

void	move_up(t_info *info, double cub, double mini, double angle)
{
	info->px = round(cos(to_radian(angle)) * cub) + info->px;
	info->py = round(sin(to_radian(angle)) * cub) * -1.0 + info->py;
	info->minipx = round(cos(to_radian(angle)) * mini) + info->px / 6.0;
	info->minipy = round(sin(to_radian(angle)) * mini) * -1.0 + info->py / 6.0;
	//print_screen(info);
}

void	move_down(t_info *info, double cub, double mini, double angle)
{
	info->px = round(cos(to_radian(angle)) * cub) * -1.0 + info->px;
	info->py = round(sin(to_radian(angle)) * cub) + info->py;
	info->minipx = round(cos(to_radian(angle)) * mini) * -1.0 + info->px / 6.0;
	info->minipy = round(sin(to_radian(angle)) * mini) + info->py / 6.0;
	//print_screen(info);
}

void	move(t_info *info)
{
	double	v;
	double	m;
	double	cub;
	double	mini;

	m = 5.0;
	v = info->fov / 12.0;
	cub = info->cub / m;
	mini = info->minicub / m;
	if (info->lookl)
		look_left(info, v);
	if (info->lookr)
		look_right(info, v);
	if (info->right)
		move_up(info, cub / 2.0, mini / 2.0, info->angle + 90.0);
	if (info->left)
		move_up(info, cub / 2.0, mini / 2.0, info->angle - 90.0);
	if (info->up)
		move_up(info, cub, mini, info->angle);
	if (info->down)
		move_down(info, cub, mini, info->angle);
	print_screen(info);
}
