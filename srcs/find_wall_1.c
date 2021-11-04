/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:15:16 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/04 18:37:41 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_a(t_info *info, double *a, double angle)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (angle <= 180 && angle > 0)
		a[1] = floor(info->py / info->cub) * info->cub - 0.000000001;
	else
		a[1] = floor(info->py / info->cub) * info->cub + info->cub;
	a[0] = info->px + (info->py - a[1]) / tan(to_radian(angle));
	tmpy = floor(a[1] / info->cub);
	tmpx = floor(a[0] / info->cub);
	if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
		|| tmpx > (int)ft_strlen(info->map[tmpy]))
		return (1);
	if (info->map[tmpy][tmpx] == '1')
		return (0);
	return (1);
}

void	final_wall_a_1(t_info *info, double *a, double *i, double angle)
{
	int		tmpy;
	int		tmpx;

	while (1)
	{
		a[1] = a[1] + i[1];
		if (angle <= 180 && angle > 0)
			a[0] = a[0] + i[0];
		else
			a[0] = a[0] - i[0];
		tmpy = floor(a[1] / (double)info->cub);
		tmpx = floor(a[0] / (double)info->cub);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (info->map[tmpy][tmpx] == '1')
			break ;
	}
}

void	final_wall_a(t_info *info, double *a, double angle)
{
	double		i[2];

	if (angle <= 180 && angle > 0)
		i[1] = info->cub * -1.0;
	else
		i[1] = info->cub;
	i[0] = info->cub / tan(to_radian(angle));
	final_wall_a_1(info, a, i, angle);
}	
