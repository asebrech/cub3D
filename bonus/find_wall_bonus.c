/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:03:40 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/11 19:19:37 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	find_h(t_info *info, double *h, double angle)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (angle <= 180.0 && angle > 0.0)
		h[1] = floor(info->py / info->cub) * info->cub - 0.000000001;
	else
		h[1] = floor(info->py / info->cub) * info->cub + info->cub;
	h[0] = info->px + (info->py - h[1]) / tan(to_radian(angle));
	tmpy = floor(h[1] / info->cub);
	tmpx = floor(h[0] / info->cub);
	if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
		|| tmpx > (int)ft_strlen(info->map[tmpy]))
		return (1);
	if (info->map[tmpy][tmpx] == '1')
		return (0);
	return (1);
}

void	final_wall_h_1(t_info *info, double *h, double *inc, double angle)
{
	int		tmpy;
	int		tmpx;

	while (1)
	{
		h[1] = h[1] + inc[1];
		if (angle <= 180.0 && angle > 0.0)
			h[0] = h[0] + inc[0];
		else
			h[0] = h[0] - inc[0];
		tmpy = floor(h[1] / (double)info->cub);
		tmpx = floor(h[0] / (double)info->cub);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (info->map[tmpy][tmpx] == '1')
			break ;
	}
}

void	final_wall_h(t_info *info, double *h, double angle)
{
	double		inc[2];

	if (angle <= 180.0 && angle > 0.0)
		inc[1] = info->cub * -1.0;
	else
		inc[1] = info->cub;
	inc[0] = info->cub / tan(to_radian(angle));
	final_wall_h_1(info, h, inc, angle);
}	

void	find_wall(t_info *info, double angle)
{
	double		h[2];
	double		v[2];
	double		tmph;
	double		tmpv;

	if (find_h(info, h, angle))
		final_wall_h(info, h, angle);
	if (find_v(info, v, angle))
		final_wall_v(info, v, angle);
	tmph = sqrt(pow((info->px - h[0]), 2) + pow((info->py - h[1]), 2));
	tmpv = sqrt(pow((info->px - v[0]), 2) + pow((info->py - v[1]), 2));
	if (tmph <= tmpv)
	{
		info->wall_x = h[0];
		info->wall_y = h[1];
		info->wall_type = 'h';
		info->wall_len = tmph;
	}
	else
	{
		info->wall_x = v[0];
		info->wall_y = v[1];
		info->wall_type = 'v';
		info->wall_len = tmpv;
	}
}
