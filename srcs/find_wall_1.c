/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:15:16 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/27 17:55:17 by asebrech         ###   ########.fr       */
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

void	final_wall_a_1(t_info *info, double *a, int ya, int xa)
{
	int		tmpy;
	int		tmpx;

	while (1)
	{
		a[1] = a[1] + ya;
		if (info->angle <= 180 && info->angle > 0)
			a[0] = a[0] + xa;
		else
			a[0] = a[0] - xa;
		tmpy = floor(a[1] / (double)info->minicub);
		tmpx = floor(a[0] / (double)info->minicub);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (info->map[tmpy][tmpx] == '1')
			break ;
	}
}

void	final_wall_a(t_info *info, double *a)
{
	int		ya;
	int		xa;

	if (info->angle <= 180 && info->angle > 0)
		ya = info->minicub * -1;
	else
		ya = info->minicub;
	xa = info->minicub / tan(to_radian(info->angle));
	final_wall_a_1(info, a, ya, xa);
}	
