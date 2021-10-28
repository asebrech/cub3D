/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:55:01 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/28 13:21:53 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_right(t_info *info, double i)
{
	info->px = round(sin(to_radian(info->angle)) * i) + info->px;
	info->py = round(cos(to_radian(info->angle)) * i) * -1.0 + info->py;
	minimap(info);
}

void	move_left(t_info *info, double i)
{
	info->px = round(sin(to_radian(info->angle)) * i) * -1.0 + info->px;
	info->py = round(cos(to_radian(info->angle)) * i) + info->py;
	minimap(info);
}

void	move_up(t_info *info, double i)
{
	info->px = round(cos(to_radian(info->angle)) * i) + info->px;
	info->py = round(sin(to_radian(info->angle)) * i) * -1.0 + info->py;
	minimap(info);
}

void	move_down(t_info *info, double i)
{
	info->px = round(cos(to_radian(info->angle)) * i) * -1.0 + info->px;
	info->py = round(sin(to_radian(info->angle)) * i) + info->py;
	minimap(info);
}

void	move(t_info *info, int keycode)
{
	double	i;
	double	j;

	i = 5.0;
	j = 2.0;
	if (keycode == 13)
		move_up(info, i);
	if (keycode == 1)
		move_down(info, i);
	if (keycode == 0)
		move_left(info, i);
	if (keycode == 2)
		move_right(info, i);
	if (keycode == 123)
		look_left(info, j);
	if (keycode == 124)
		look_right(info, j);
}
