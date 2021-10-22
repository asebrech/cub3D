/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:36:45 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/22 17:36:41 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_p(int i, int j, t_info *info)
{
	int		k;
	int		l;
	int		x;
	int		y;

	x = j * 48 + 12;
	y = i * 48 + 12;
	l = -1;
	while (++l < 24)
	{
		k = -1;
		while (++k < 24)
		{
			if (info->map[i][j])
				mlx_pixel_put(info->mlx, info->win, x + k, y, 0x0000FF00);
		}
		y++;
	}
}

void	print_cub(int i, int j, t_info *info)
{
	int		k;
	int		l;
	int		x;
	int		y;

	x = j * 48;
	y = i * 48;
	l = -1;
	while (++l < 48)
	{
		k = -1;
		while (++k < 48)
		{
			if (info->map[i][j])
				mlx_pixel_put(info->mlx, info->win, x + k, y, 0x000000FF);
		}
		y++;
	}
}

void	minimap(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	while (info->map[++i] != NULL)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == '1')
				print_cub(i, j, info);
			else if (info->map[i][j] == 'N')
				print_p(i, j, info);
		}
	}
}