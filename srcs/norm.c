/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:57:09 by asebrech          #+#    #+#             */
/*   Updated: 2021/12/01 13:06:49 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	pars_norm(t_info *info, int *c, int i, int j)
{
	if ((info->map[i][j] == 'N')
			|| (info->map[i][j] == 'S')
			|| (info->map[i][j] == 'E')
			|| (info->map[i][j] == 'W'))
	{
		*c += 1;
		return (1);
	}
	else if (info->map[i][j] == '0')
		return (1);
	else
		return (0);
}
