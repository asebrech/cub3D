/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:03:40 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/28 13:24:38 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_b(t_info *info, double *b, double angle)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (angle > 90 && angle <= 270)
		b[0] = floor(info->px / info->minicub) * info->minicub - 1.0;
	else
		b[0] = floor(info->px / info->minicub) * info->minicub + info->minicub;
	b[1] = info->py + (info->px - b[0]) * tan(to_radian(angle));
	tmpy = floor(b[1] / info->minicub);
	tmpx = floor(b[0] / info->minicub);
	if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
		|| tmpx > (int)ft_strlen(info->map[tmpy]))
		return (1);
	if (info->map[tmpy][tmpx] == '1')
		return (0);
	return (1);
}

void	final_wall_b_1(t_info *info, double *b, double *i, double angle)
{
	int		tmpy;
	int		tmpx;

	while (1)
	{
		if (angle > 90 && angle <= 270)
			b[1] = b[1] + i[1];
		else
			b[1] = b[1] - i[1];
		b[0] = b[0] + i[0];
		tmpy = floor(b[1] / info->minicub);
		tmpx = floor(b[0] / info->minicub);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (info->map[tmpy][tmpx] == '1')
			break ;
	}
}

void	final_wall_b(t_info *info, double *b, double angle)
{
	double		i[2];

	if (angle > 90 && angle <= 270)
		i[0] = info->minicub * -1.0;
	else
		i[0] = info->minicub;
	i[1] = info->minicub * tan(to_radian(angle));
	final_wall_b_1(info, b, i, angle);
}

void	find_wall(t_info *info, double *c, double angle)
{
	double		a[2];
	double		b[2];
	double		tmp[2];

	if (find_a(info, a, angle))
		final_wall_a(info, a, angle);
	if (find_b(info, b, angle))
		final_wall_b(info, b, angle);
	tmp[0] = sqrt(pow((info->px - a[0]), 2) + pow((info->py - a[1]), 2));
	tmp[1] = sqrt(pow((info->px - b[0]), 2) + pow((info->py - b[1]), 2));
	if (tmp[0] < tmp[1])
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
