/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:55:01 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/26 15:00:41 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_left(t_info *info)
{
	if (info->angle == 360)
		info->angle = 0;
	else
		info->angle += 1;
	mlx_clear_window(info->mlx, info->win);
	minimap(info);
}

void	move_right(t_info *info)
{

	if (info->angle == 0)
		info->angle = 360;
	else
		info->angle -= 1;
	mlx_clear_window(info->mlx, info->win);
	minimap(info);
}

void	move_up(t_info *info)
{
	info->px = round(cos(to_radian(info->angle)) * 5) + info->px;
	info->py = round(sin(to_radian(info->angle)) * 5) * -1 + info->py;
	mlx_clear_window(info->mlx, info->win);
	minimap(info);
}

void	move_down(t_info *info)
{
	info->px = round(cos(to_radian(info->angle)) * 5) * -1 + info->px;
	info->py = round(sin(to_radian(info->angle)) * 5) + info->py;
	mlx_clear_window(info->mlx, info->win);
	minimap(info);
}

void	move(t_info *info, int keycode)
{
	if (keycode == 126 || keycode == 13)
		move_up(info);
	if (keycode == 125 || keycode == 1)
		move_down(info);
	if (keycode == 123 || keycode == 0)
		move_left(info);
	if (keycode == 124 || keycode == 2)
		move_right(info);
}