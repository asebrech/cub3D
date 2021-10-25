/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:03:40 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/25 11:18:26 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_wall(t_info *info)
{
	int		ya;
	int		xa;

	ya = 0;
	xa = 0;
	if (info->angle <= 180 && info->angle >= 0)
		ya = floor(info->py / info->minicub) * info->minicub - 1;
	else if (info->angle > 180 && info->angle <= 360)
		ya = floor(info->py / info->minicub) * info->minicub + info->minicub;
	xa = info->px + (info->py - ya) / tan(info->angle);
}