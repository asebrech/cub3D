/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:03:40 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/27 15:43:16 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_a(t_info *info, double *a)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (info->angle <= 180 && info->angle > 0)
		a[1] = floor(info->py / info->minicub) * info->minicub - 1;
	else
		a[1] = floor(info->py / info->minicub) * info->minicub + info->minicub;
	a[0] = info->px + (info->py - a[1]) / tan(to_radian(info->angle));
	tmpy = floor(a[1] / info->minicub);
	tmpx = floor(a[0] / info->minicub);
	if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
		|| tmpx > (int)ft_strlen(info->map[tmpy]))
		return (1);
	if (info->map[tmpy][tmpx] == '1')
		return (0);
	return (1);
}

void	final_wall_a(t_info *info, double *a)
{
	int		ya;
	int		xa;
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (info->angle <= 180 && info->angle > 0)
		ya = info->minicub * -1;
	else
		ya = info->minicub;
	xa = info->minicub / tan(to_radian(info->angle));
	while (1)
	{
		a[1] = a[1] + ya;
		if (info->angle <= 180 && info->angle > 0)
			a[0] = a[0] + xa;
		else
			a[0] = a[0] - xa;
		tmpy = floor(a[1] / info->minicub);
		tmpx = floor(a[0] / info->minicub);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (info->map[tmpy][tmpx] == '1')
			break ;
	}
}	

int	find_b(t_info *info, double *b)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (info->angle > 90 && info->angle < 270)
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

void	final_wall_b(t_info *info, double *b)
{
	int		yb;
	int		xb;
	int		tmpy;
	int		tmpx;

	yb = 0;
	xb = 0;
	if (info->angle > 90 && info->angle <= 270)
		xb = info->minicub * -1;
	else
		xb = info->minicub;
	yb = info->minicub * tan(to_radian(info->angle));
	while (1)
	{
		if (info->angle > 90 && info->angle <= 270)
			b[1] = b[1] + yb;
		else
			b[1] = b[1] - yb;
		b[0] = b[0] + xb;
		tmpy = floor(b[1] / info->minicub);
		tmpx = floor(b[0] / info->minicub);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (info->map[tmpy][tmpx] == '1')
			break ;
	}
}

void	find_wall(t_info *info, double *a, double *b)
{
	if (find_a(info, a))
		final_wall_a(info, a);
	if (find_b(info, b))
		final_wall_b(info, b);
}
