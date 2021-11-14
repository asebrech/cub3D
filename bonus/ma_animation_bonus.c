/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:52:33 by alois             #+#    #+#             */
/*   Updated: 2021/11/14 22:54:51 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fire_ma(t_info *info)
{
	static	int i = 1;

	if (i < 3)
		mlx_put_image_to_window(info->mlx, info->win, info->ma1, info->wp, 0);
	else if (i < 6)
		mlx_put_image_to_window(info->mlx, info->win, info->ma2, info->wp, 0);
	else if (i < 9)
		mlx_put_image_to_window(info->mlx, info->win, info->ma3, info->wp, 0);
	else if (i <= 12)
		mlx_put_image_to_window(info->mlx, info->win, info->ma4, info->wp, 0);
	i++;
	if (i > 12)
		i = 1;
}

void	cross_ma(t_info *info)
{
	static	int i = 1;

	if (i < 5)
		mlx_put_image_to_window(info->mlx, info->win, info->mac1, info->wp, 0);
	else if (i < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->mac2, info->wp, 0);
	else if (i <= 15)
		mlx_put_image_to_window(info->mlx, info->win, info->mac3, info->wp, 0);
	else if (i <= 20)
		mlx_put_image_to_window(info->mlx, info->win, info->mac4, info->wp, 0);
	else if (i <= 25)
		mlx_put_image_to_window(info->mlx, info->win, info->mac5, info->wp, 0);
	else if (i <= 30)
		mlx_put_image_to_window(info->mlx, info->win, info->mac6, info->wp, 0);
	else if (i <= 35)
		mlx_put_image_to_window(info->mlx, info->win, info->mac7, info->wp, 0);

	i++;
	if (i > 35)
		i = 1;
}

void	reload_ma(t_info *info)
{
	static	int i = 1;

	//printf("reload %d\n", i);
	if (i < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->mar1, info->wp, 0);
	else if (i < 20)
		mlx_put_image_to_window(info->mlx, info->win, info->mar2, info->wp, 0);
	else if (i < 30)
		mlx_put_image_to_window(info->mlx, info->win, info->mar3, info->wp, 0);
	else if (i < 40)
		mlx_put_image_to_window(info->mlx, info->win, info->mar4, info->wp, 0);
	else if (i <= 50)
		mlx_put_image_to_window(info->mlx, info->win, info->mar5, info->wp, 0);
	i++;
	if (i > 50)
		i = 1;
}

void	fire_pr(t_info *info)
{
	static	int i = 1;

	if (i < 2)
		mlx_put_image_to_window(info->mlx, info->win, info->pr1, info->wp, 0);
	else if (i < 4)
		mlx_put_image_to_window(info->mlx, info->win, info->pr2, info->wp, 0);
	else if (i <= 6)
		mlx_put_image_to_window(info->mlx, info->win, info->pr3, info->wp, 0);
	else if (i <= 8)
		mlx_put_image_to_window(info->mlx, info->win, info->pr4, info->wp, 0);
	else if (i <= 10)
		mlx_put_image_to_window(info->mlx, info->win, info->pr5, info->wp, 0);
	i++;
	if (i > 10)
		i = 1;
}