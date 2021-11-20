/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:44:56 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/20 18:05:57 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	sniper(t_info *info)
{
	static	int	i = 0;
	static	int	k = 0;

	if (i == 0 && k == 0 && info->reload == 1 && info->weapon == 6 && info->sn != 4)
		i = 35;
	else if (i == 0 && k == 0 && info->fire == 1 && info->weapon == 6 && info->sn)
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

void	shotgun(t_info *info)
{
	static	int	i = 0;
	static	int	k = 0;

	if (i == 0 && k == 0 && info->reload == 1 && info->weapon == 5 && info->sh != 12)
		i = 30;
	else if (i == 0 && k == 0 && info->fire == 1 && info->weapon == 5 && info->sh)
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
	static	int j = 0;
	static	int k = 0;

	if (k == 0 && !info->pr)
		k = 1;
	if (k == 0 && j == 0 && info->reload == 1 && info->weapon == 4 && info->pr != 100)
		k = info->pr;
	else if (k == 0 && j == 0 && info->fire == 1 && info->weapon == 4 && info->pr > 0)
		j = 4;
	if (k == 100)
	{
		info->pr = 100;
		k = 0;
	}
	if	(k)
		k++;
	if (j > 0 &&  info->weapon == 4)
	{
		fire_pr(info);
		j--;
	}
	else if (k > 0 && info->weapon == 4)
		mlx_put_image_to_window(info->mlx, info->win, info->pr6, info->wp, 0);
	else if (info->weapon == 4)
		mlx_put_image_to_window(info->mlx, info->win, info->pr1, info->wp, 0);
	shotgun(info);	
}

void	ppistol(t_info *info)
{
	static	int	i = 0;

	if (i == 0 && info->fire == 1 && info->weapon == 3 && info->pp > 0)
		i = 10;
	if (i > 0 &&  info->weapon == 3)
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
	static	int	i = 0;
	static	int	j = 0;
	static	int	k = 0;

	if (i == 0 && j == 0 && k == 0 && info->reload == 1 && info->weapon == 2 && info->ma != 8)
		i = 50;
	else if (j == 0 && j == 0 && k == 0 && info->cross == 1 && info->weapon == 2)
		j = 48;
	else if (j == 0 && j == 0 && k == 0 && info->fire == 1 && info->weapon == 2 && info->ma > 0)
		k = 12;
	if (i > 0 && info->weapon == 2)
	{
		reload_ma(info);
		i--;
	}
	else if (j > 0 && info->weapon == 2)
	{
		cross_ma(info);
		j--;
	}
	else if (k > 0 && info->weapon == 2)
	{
		fire_ma(info);
		k--;
	}
	else if (info->weapon == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->ma1, info->wp, 0);
	ppistol(info);
}

void	sprite(t_info *info)
{
	//printf("%d\n", info->button);
	static	int	i = 0;
	static	int	j = 0;
	static	int k = 0;

	//if (info->ar == 0)
		//i = 50;
	if (i == 0 && j == 0 && k == 0 && info->reload == 1 && info->weapon == 1 && info->ar != 32)
		i = 50;
	else if (j == 0 && j == 0 && k == 0 && info->cross == 1 && info->weapon == 1)
		j = 30;
	else if (j == 0 && j == 0 && k == 0 && info->fire == 1 && info->weapon == 1 && info->ar > 0)
		k = 4;
	if (i > 0 && info->weapon == 1)
	{
		reload_ar(info);
		i--;
	}
	else if (j > 0 && info->weapon == 1)
	{
		cross_ar(info);
		j--;
	}
	else if (k > 0 && info->weapon == 1)
	{
		fire_ar(info);
		k--;
	}
	else if (info->weapon == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->ar1, info->wp, 0);
	magnum(info);
}