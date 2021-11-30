/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:25:11 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/30 15:47:30 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	key_hook_norm(int keycode, t_info *info)
{
	if (keycode == 15)
		info->reload = 1;
	if (keycode == 8)
		info->cross = 1;
	if (keycode == 18)
		info->weapon = 1;
	if (keycode == 19)
		info->weapon = 2;
	if (keycode == 20)
		info->weapon = 3;
	if (keycode == 21)
		info->weapon = 4;
	if (keycode == 23)
		info->weapon = 5;
	if (keycode == 22)
		info->weapon = 6;
}

void	fucking_dumb_norm(t_info *info)
{
	info->cwe = NULL;
	info->cea = NULL;
	info->lst = NULL;
	info->map = NULL;
	info->player = 0;
	info->fr = -1;
	info->fg = -1;
	info->fb = -1;
	info->cr = -1;
	info->cg = -1;
	info->cb = -1;
	info->x = 1800.0;
	info->y = 1000.0;
	info->cub = 64.0;
	info->minicub = info->cub / 6.0;
	info->fov = 60.0;
	info->plane = round((info->x / 2.0) / tan(to_radian(info->fov / 2.0)));
	info->mousex = (info->x / 2);
	info->wp = (info->x / 2) - 500;
}

void	sprite_norm(t_info *info, int *i, int *j, int *k)
{
	if (*i > 0 && info->weapon == 1)
	{
		reload_ar(info);
		*i -= 1;
	}
	else if (*j > 0 && info->weapon == 1)
	{
		cross_ar(info);
		*j -= 1;
	}
	else if (*k > 0 && info->weapon == 1)
	{
		fire_ar(info);
		*k -= 1;
	}
	else if (info->weapon == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->ar1, info->wp, 0);
}

void	sniper(t_info *info)
{
	static int	i = 0;
	static int	k = 0;

	if (i == 0 && k == 0 && info->reload == 1
		&& info->weapon == 6 && info->sn != 4)
		i = 45;
	else if (i == 0 && k == 0 && info->fire == 1
		&& info->weapon == 6 && info->sn)
		k = 12;
	if (i > 0 && info->weapon == 6)
	{
		reload_sn(info);
		i--;
	}
	else if (k > 0 && info->weapon == 6)
	{
		fire_sn(info);
		k--;
	}
	else if (info->weapon == 6)
		mlx_put_image_to_window(info->mlx, info->win, info->sn1, info->wp, 0);
}

void	magnum_norm(t_info *info, int *i, int *j, int *k)
{
	if (*i > 0 && info->weapon == 2)
	{
		reload_ma(info);
		*i -= 1;
	}
	else if (*j > 0 && info->weapon == 2)
	{
		cross_ma(info);
		*j -= 1;
	}
	else if (*k > 0 && info->weapon == 2)
	{
		fire_ma(info);
		*k -= 1;
	}
	else if (info->weapon == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->ma1, info->wp, 0);
}
