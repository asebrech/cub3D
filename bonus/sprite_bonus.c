/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:44:56 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/14 19:06:13 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fire_ar(t_info *info)
{
	static	int i = 1;

	if (i == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->ar1, info->wp, 0);
	else if (i == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->ar2, info->wp, 0);
	else if (i == 3)
		mlx_put_image_to_window(info->mlx, info->win, info->ar3, info->wp, 0);
	i++;
	if (i > 3)
		i = 1;
}

void	cross_ar(t_info *info)
{
	static	int i = 1;

	if (i < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->arc1, info->wp, 0);
	else if (i < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->arc2, info->wp, 0);
	else if (i <= 30)
		mlx_put_image_to_window(info->mlx, info->win, info->arc3, info->wp, 0);
	i++;
	if (i > 30)
		i = 1;
}

void	reload_ar(t_info *info)
{
	static	int i = 1;

	//printf("reload %d\n", i);
	if (i < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->arr1, info->wp, 0);
	else if (i < 20)
		mlx_put_image_to_window(info->mlx, info->win, info->arr2, info->wp, 0);
	else if (i < 30)
		mlx_put_image_to_window(info->mlx, info->win, info->arr3, info->wp, 0);
	else if (i < 40)
		mlx_put_image_to_window(info->mlx, info->win, info->arr4, info->wp, 0);
	else if (i <= 50)
		mlx_put_image_to_window(info->mlx, info->win, info->arr5, info->wp, 0);
	i++;
	if (i > 50)
		i = 1;
}

void	sprite(t_info *info)
{
	//printf("%d\n", info->button);
	static	int	i = 0;
	static	int	j = 0;

	if (i == 0 && j == 0 && info->reload == 1 && info->weapon == 1)
		i = 50;
	else if (j == 0 && j == 0 && info->cross == 1 && info->weapon == 1)
		j = 30;
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
	else if (info->fire && info->weapon == 1)
		fire_ar(info);
	else if (!info->fire && info->weapon == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->ar1, info->wp, 0);
}