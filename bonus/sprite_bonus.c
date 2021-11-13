/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:44:56 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/13 16:02:44 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	sprite(t_info *info)
{
	t_data	halo;

	halo.img = mlx_xpm_file_to_image(info->mlx, "./halo/AR/AR1.xpm", &info->w, &info->h);
	mlx_put_image_to_window(info->mlx, info->win, halo.img, (info->x / 2) - 500, 0);
}