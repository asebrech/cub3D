/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:55:01 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/04 14:08:30 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	look_left(t_info *info, double j)
{
	info->angle += j;
	if (info->angle > 360.0)
		info->angle -= 360.0;
	print_screen(info);
}

void	look_right(t_info *info, double j)
{
	info->angle -= j;
	if (info->angle < 0.0)
		info->angle += 360.0;
	print_screen(info);
}

void	move_up(t_info *info, double i, double angle)
{
	info->px = round(cos(to_radian(angle)) * i) + info->px;
	info->py = round(sin(to_radian(angle)) * i) * -1.0 + info->py;
	print_screen(info);
}

void	move_down(t_info *info, double i, double angle)
{
	info->px = round(cos(to_radian(angle)) * i) * -1.0 + info->px;
	info->py = round(sin(to_radian(angle)) * i) + info->py;
	print_screen(info);
}

void	move(t_info *info, int keycode)
{
	double	i;
	double	j;

	i = 8.0 * (info->cub / 18);
	j = 6.0 * (info->cub / 18);
	if (keycode == 13)
		move_up(info, i, info->angle);
	if (keycode == 1)
		move_down(info, i, info->angle);
	if (keycode == 0)
		move_up(info, i, info->angle + 90.0);
	if (keycode == 2)
		move_up(info, i, info->angle - 90.0);
	if (keycode == 123)
		look_left(info, j);
	if (keycode == 124)
		look_right(info, j);
}
