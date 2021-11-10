/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:55:01 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/10 11:13:17 by asebrech         ###   ########.fr       */
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

void	move_up(t_info *info, double m, double angle)
{
	info->px = round(cos(to_radian(angle)) * m) + info->px;
	info->py = round(sin(to_radian(angle)) * m) * -1.0 + info->py;
	print_screen(info);
}

void	move_down(t_info *info, double m, double angle)
{
	info->px = round(cos(to_radian(angle)) * m) * -1.0 + info->px;
	info->py = round(sin(to_radian(angle)) * m) + info->py;
	print_screen(info);
}

void	move(t_info *info, int keycode)
{
	double	m;
	double	v;

	m = info->cub / 4.0;
	v = info->fov / 12.0;
	if (keycode == 13)
		move_up(info, m, info->angle);
	if (keycode == 1)
		move_down(info, m, info->angle);
	if (keycode == 0)
		move_up(info, m, info->angle + 90.0);
	if (keycode == 2)
		move_up(info, m, info->angle - 90.0);
	if (keycode == 123)
		look_left(info, v);
	if (keycode == 124)
		look_right(info, v);
}
