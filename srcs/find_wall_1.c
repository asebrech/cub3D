/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:15:16 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/10 10:08:11 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_v(t_info *info, double *v, double angle)
{
	int		tmpy;
	int		tmpx;

	tmpy = 0;
	tmpx = 0;
	if (angle > 90.0 && angle <= 270.0)
		v[0] = floor(info->px / info->cub) * info->cub - 0.000000001;
	else
		v[0] = floor(info->px / info->cub) * info->cub + info->cub;
	v[1] = info->py + (info->px - v[0]) * tan(to_radian(angle));
	tmpy = floor(v[1] / info->cub);
	tmpx = floor(v[0] / info->cub);
	if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
		|| tmpx > (int)ft_strlen(info->map[tmpy]))
		return (1);
	if (info->map[tmpy][tmpx] == '1')
		return (0);
	return (1);
}

void	final_wall_v_1(t_info *info, double *v, double *inc, double angle)
{
	int		tmpy;
	int		tmpx;

	while (1)
	{
		if (angle > 90.0 && angle <= 270.0)
			v[1] = v[1] + inc[1];
		else
			v[1] = v[1] - inc[1];
		v[0] = v[0] + inc[0];
		tmpy = floor(v[1] / info->cub);
		tmpx = floor(v[0] / info->cub);
		if (tmpy < 0 || tmpx < 0 || tmpy > info->map_len
			|| tmpx > (int)ft_strlen(info->map[tmpy]))
			break ;
		if (info->map[tmpy][tmpx] == '1')
			break ;
	}
}

void	final_wall_v(t_info *info, double *v, double angle)
{
	double		inc[2];

	if (angle > 90.0 && angle <= 270.0)
		inc[0] = info->cub * -1.0;
	else
		inc[0] = info->cub;
	inc[1] = info->cub * tan(to_radian(angle));
	final_wall_v_1(info, v, inc, angle);
}
