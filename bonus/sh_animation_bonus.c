/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:11:19 by alois             #+#    #+#             */
/*   Updated: 2021/11/20 17:38:30 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fire_sh(t_info *info)
{
	static	int i = 1;

	if (i < 2)
		mlx_put_image_to_window(info->mlx, info->win, info->sh1, info->wp, 0);
	else if (i < 4)
		mlx_put_image_to_window(info->mlx, info->win, info->sh2, info->wp, 0);
	else if (i < 6)
		mlx_put_image_to_window(info->mlx, info->win, info->sh3, info->wp, 0);
	else if (i < 8)
		mlx_put_image_to_window(info->mlx, info->win, info->sh4, info->wp, 0);
	else if (i < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->sh5, info->wp, 0);
	else if (i <= 12)
		mlx_put_image_to_window(info->mlx, info->win, info->sh6, info->wp, 0);
	i++;
	if (i > 12)
	{
		i = 1;
		info->sh--;
	}
}

void	reload_sh(t_info *info)
{
	static	int i = 1;

	if (i < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->shr1, info->wp, 0);
	else if (i < 20)
		mlx_put_image_to_window(info->mlx, info->win, info->shr2, info->wp, 0);
	else if (i <= 30)
		mlx_put_image_to_window(info->mlx, info->win, info->shr3, info->wp, 0);
	i++;
	if (i > 30)
	{
		i = 1;
		info->sh++;
	}
}

void	fire_sn(t_info *info)
{
	static	int i = 1;

	if (i < 4)
		mlx_put_image_to_window(info->mlx, info->win, info->sn1, info->wp, 0);
	else if (i < 8)
		mlx_put_image_to_window(info->mlx, info->win, info->sn2, info->wp, 0);
	else if (i <= 12)
		mlx_put_image_to_window(info->mlx, info->win, info->sn3, info->wp, 0);
	i++;
	if (i > 12)
	{
		i = 1;
		info->sn--;
	}
}

void	reload_sn(t_info *info)
{
	static	int i = 1;

	if (i < 18)
		mlx_put_image_to_window(info->mlx, info->win, info->snr1, info->wp, 0);
	else if (i < 32)
		mlx_put_image_to_window(info->mlx, info->win, info->snr2, info->wp, 0);
	else if (i <= 46)
		mlx_put_image_to_window(info->mlx, info->win, info->snr3, info->wp, 0);
	i++;
	if (i > 35)
	{
		i = 1;
		info->sn = 4;
	}
}