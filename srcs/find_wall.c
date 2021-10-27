/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:03:40 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/27 18:20:45 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_b(t_info *info, double *b)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (info->angle > 90 && info->angle <= 270)
		b[0] = floor(info->px / info->minicub) * info->minicub - 1;
	else
		b[0] = floor(info->px / info->minicub) * info->minicub + info->minicub;
	b[1] = info->py + (info->px - b[0]) * tan(to_radian(info->angle));
	tmpy = floor(b[1] / info->minicub);
	tmpx = floor(b[0] / info->minicub);
	if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
		|| tmpx > (int)ft_strlen(info->map[tmpy]))
		return (1);
	if (info->map[tmpy][tmpx] == '1')
		return (0);
	return (1);
}

void	final_wall_b_1(t_info *info, double *b, int yb, int xb)
{
	int		tmpy;
	int		tmpx;

	while (1)
	{
		if (info->angle > 90 && info->angle <= 270)
			b[1] = b[1] + yb;
		else
			b[1] = b[1] - yb;
		b[0] = b[0] + xb;
		tmpy = floor(b[1] / (double)info->minicub);
		tmpx = floor(b[0] / (double)info->minicub);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (info->map[tmpy][tmpx] == '1')
			break ;
	}
}

void	final_wall_b(t_info *info, double *b)
{
	int		yb;
	int		xb;

	yb = 0;
	xb = 0;
	if (info->angle > 90 && info->angle <= 270)
		xb = info->minicub * -1;
	else
		xb = info->minicub;
	yb = info->minicub * tan(to_radian(info->angle));
	final_wall_b_1(info, b, yb, xb);
}

void	find_wall(t_info *info, double *c)
{
	double		a[2];
	double		b[2];
	double		tmp[2];

	if (find_a(info, a))
		final_wall_a(info, a);
	if (find_b(info, b))
		final_wall_b(info, b);
	tmp[0] = sqrt(pow((info->px - a[0]), 2) + pow((info->py - a[1]), 2));
	tmp[1] = sqrt(pow((info->px - b[0]), 2) + pow((info->py - b[1]), 2));
	if (tmp[0] <= tmp[1])
	{
		c[0] = a[0];
		c[1] = a[1];
	}
	else
	{
		c[0] = b[0];
		c[1] = b[1];
	}
}
