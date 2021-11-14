/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:40:30 by alois             #+#    #+#             */
/*   Updated: 2021/11/14 16:14:46 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	open_xpm(t_info *info)
{
	info->ar1 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/AR1.xpm", &info->w, &info->h);
	info->ar2 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/AR2.xpm", &info->w, &info->h);
	info->ar3 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/AR3.xpm", &info->w, &info->h);
	info->arc1 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/ARC1.xpm", &info->w, &info->h);
	info->arc2 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/ARC2.xpm", &info->w, &info->h);
	info->arc3 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/ARC3.xpm", &info->w, &info->h);
	info->arr1 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/ARR1.xpm", &info->w, &info->h);
	info->arr2 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/ARR2.xpm", &info->w, &info->h);
	info->arr3 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/ARR3.xpm", &info->w, &info->h);
	info->arr4 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/ARR4.xpm", &info->w, &info->h);
	info->arr5 = mlx_xpm_file_to_image(info->mlx, "./halo/AR/ARR5.xpm", &info->w, &info->h);
}