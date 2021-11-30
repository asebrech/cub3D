/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:44:56 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/30 15:53:53 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	shotgun(t_info *info)
{
	static int	i = 0;
	static int	k = 0;

	if (i == 0 && k == 0 && info->reload == 1
		&& info->weapon == 5 && info->sh != 12)
		i = 30;
	else if (i == 0 && k == 0 && info->fire == 1
		&& info->weapon == 5 && info->sh)
		k = 12;
	if (i > 0 && info->weapon == 5)
	{
		reload_sh(info);
		i--;
	}
	else if (k > 0 && info->weapon == 5)
	{
		fire_sh(info);
		k--;
	}
	else if (info->weapon == 5)
		mlx_put_image_to_window(info->mlx, info->win, info->sh1, info->wp, 0);
	sniper(info);
}

void	prifle(t_info *info)
{
	static int	j = 0;
	static int	k = 0;

	if (k == 0 && !info->pr)
		k = 1;
	if (k == 0 && j == 0 && info->reload == 1 && info->weapon == 4
		&& info->pr != 100)
		k = info->pr;
	else if (k == 0 && j == 0 && info->fire == 1 && info->weapon == 4
		&& info->pr > 0)
		j = 4;
	prifle_norm(info, &k, &j);
	shotgun(info);
}

void	ppistol(t_info *info)
{
	static int	i = 0;

	if (i == 0 && info->fire == 1 && info->weapon == 3 && info->pp > 0)
		i = 10;
	if (i > 0 && info->weapon == 3)
	{
		fire_pp(info);
		i--;
	}
	else if (info->reload == 1 && info->weapon == 3 && info->pp != 100)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->ppr1, info->wp, 0);
		info->pp++;
	}
	else if (info->weapon == 3)
		mlx_put_image_to_window(info->mlx, info->win, info->pp1, info->wp, 0);
	prifle(info);
}

void	magnum(t_info *info)
{
	static int	i = 0;
	static int	j = 0;
	static int	k = 0;

	if (i == 0 && j == 0 && k == 0 && info->reload == 1
		&& info->weapon == 2 && info->ma != 8)
		i = 50;
	else if (j == 0 && j == 0 && k == 0 && info->cross == 1
		&& info->weapon == 2)
		j = 55;
	else if (j == 0 && j == 0 && k == 0 && info->fire == 1
		&& info->weapon == 2 && info->ma > 0)
		k = 12;
	magnum_norm(info, &i, &j, &k);
	ppistol(info);
}

void	sprite(t_info *info)
{
	static int	i = 0;
	static int	j = 0;
	static int	k = 0;

	if (i == 0 && j == 0 && k == 0 && info->reload == 1
		&& info->weapon == 1 && info->ar != 32)
		i = 50;
	else if (j == 0 && j == 0 && k == 0 && info->cross == 1
		&& info->weapon == 1)
		j = 30;
	else if (j == 0 && j == 0 && k == 0 && info->fire == 1
		&& info->weapon == 1 && info->ar > 0)
		k = 4;
	sprite_norm(info, &i, &j, &k);
	magnum(info);
}
