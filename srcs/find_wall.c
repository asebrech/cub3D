/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:03:40 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/27 11:59:39 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_a(t_info *info, double *a)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (info->angle <= 180 && info->angle >= 0)
		a[1] = floor(info->py / info->minicub) * info->minicub - 1;
	else if (info->angle > 180 && info->angle <= 360)
		a[1] = floor(info->py / info->minicub) * info->minicub + info->minicub;
	a[0] = info->px + (info->py - a[1]) / tan(to_radian(info->angle));
	tmpy = floor(a[1] / info->minicub);
	tmpx = floor(a[0] / info->minicub);
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
	
	if (info->angle <= 180 && info->angle >= 0)
		ya = info->minicub * -1;
	else if (info->angle > 180 && info->angle <= 360)
		ya = info->minicub;
	
	/*
	if (sin(to_radian(info->angle) > 0))
	{
		printf("non\n");
		ya = info->minicub;
	}
	else
	{
		printf("ok\n");
		ya = info->minicub * -1;
	}
	*/
	xa = info->minicub / tan(to_radian(info->angle));
	while (info->map[tmpy][tmpx] != '1')
	{
		a[1] = a[1] + ya;
		a[0] = a[0] + xa;
		tmpy = floor(a[1] / info->minicub);
		tmpx = floor(a[0] / info->minicub);
	}
}	

int	find_b(t_info *info, double *b)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (info->angle > 90.0 && info->angle < 270.0)
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
	/*
	if (info->angle > 90 && info->angle < 270)
		xb = info->minicub * -1;
	else
		xb = info->minicub;
	*/
	if (cos(to_radian(info->angle)) > 0)
		xb = info->minicub;
	else
		xb = info->minicub * -1;
	yb = info->minicub * tan(to_radian(info->angle));
	write(1, "avant\n", 6);
	while (1)
	{
		if (cos(to_radian(info->angle)) > 0)
			b[1] = b[1] - yb;
		else
			b[1] = b[1] + yb;
		b[0] = b[0] + xb;
		tmpy = floor(b[1] / info->minicub);
		tmpx = floor(b[0] / info->minicub);
		printf("y ; %d    y:  %f        %d     %d\n", tmpy, b[1], yb, xb);
		printf("x ; %d    x:  %f\n", tmpx, b[0]);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (!info->map[tmpy][tmpx] || info->map[tmpy][tmpx] == '1')
			break ;
	}
	write(1, "apres\n", 6);
}

void	find_wall(t_info *info, double *a, double *b)
{
	/*
	if (find_a(info, a))
		final_wall_a(info, a);*/
	a = NULL;
	//find_b(info, b);
	if(find_b(info, b))
		final_wall_b(info, b);
}
