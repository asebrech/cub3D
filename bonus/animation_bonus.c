/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:18:15 by alois             #+#    #+#             */
/*   Updated: 2021/11/14 22:39:53 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fire_ar(t_info *info)
{
	static	int i = 1;

	if (i < 3)
		mlx_put_image_to_window(info->mlx, info->win, info->ar1, info->wp, 0);
	else if (i < 6)
		mlx_put_image_to_window(info->mlx, info->win, info->ar2, info->wp, 0);
	else if (i <= 9)
		mlx_put_image_to_window(info->mlx, info->win, info->ar3, info->wp, 0);
	i++;
	if (i > 9)
		i = 1;
}

void	cross_ar(t_info *info)
{
	static	int i = 1;

	if (i < 10)
		mlx_put_image_to_window(info->mlx, info->win, info->arc1, info->wp, 0);
	else if (i < 20)
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

void	fire_pp(t_info *info)
{
	static	int i = 1;

	if (i < 2)
		mlx_put_image_to_window(info->mlx, info->win, info->pp1, info->wp, 0);
	else if (i < 4)
		mlx_put_image_to_window(info->mlx, info->win, info->pp2, info->wp, 0);
	else if (i <= 6)
		mlx_put_image_to_window(info->mlx, info->win, info->pp3, info->wp, 0);
	else if (i <= 8)
		mlx_put_image_to_window(info->mlx, info->win, info->pp4, info->wp, 0);
	else if (i <= 10)
		mlx_put_image_to_window(info->mlx, info->win, info->pp5, info->wp, 0);
	i++;
	if (i > 10)
		i = 1;
}
