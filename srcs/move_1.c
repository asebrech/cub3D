/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:07:40 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/28 12:54:20 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	look_left(t_info *info, double j)
{
	info->angle += j;
	if (info->angle > 360.0)
		info->angle -= 360.0;
	minimap(info);
}

void	look_right(t_info *info, double j)
{
	info->angle -= j;
	if (info->angle < 0.0)
		info->angle += 360.0;
	minimap(info);
}
