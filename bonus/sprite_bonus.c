/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:44:56 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/11 20:45:03 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	sprite(t_info *info)
{
	t_data	halo;
	int	x;
	int	y;

	halo.img = mlx_xpm_file_to_image(info->mlx, "./halo.xpm", &info->w, &info->h);
	//mlx_put_image_to_window(info->mlx, info->win, test, 0, 0);
	halo.addr = mlx_get_data_addr(halo.img, &halo.bits_per_pixel,
			&halo.line_length, &halo.endian);
	y = -1;
	while (++y < info->y / 2)
	{
		x = -1;
		while (++x < info->x / 2)
		{
			if (x >= 0 && y >= 0 && x < info->x && y < info->y)
				my_mlx_pixel_put(&info->img, x, y,
					mlx_pixel_get(&halo, x - 64 * (info->x / 64), y - 64 * (info->y / 64)));
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}