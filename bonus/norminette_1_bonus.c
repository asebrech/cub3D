/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:25:55 by asebrech          #+#    #+#             */
/*   Updated: 2021/12/01 13:08:38 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	prifle_norm(t_info *info, int *k, int *j)
{
	if (*k == 100)
	{
		info->pr = 100;
		*k = 0;
	}
	if (*k)
		*k += 1;
	if (*j > 0 && info->weapon == 4)
	{
		fire_pr(info);
		*j -= 1;
	}
	else if (*k > 0 && info->weapon == 4)
		mlx_put_image_to_window(info->mlx, info->win, info->pr6, info->wp, 0);
	else if (info->weapon == 4)
		mlx_put_image_to_window(info->mlx, info->win, info->pr1, info->wp, 0);
}

void	xpm_norm(t_info *info)
{
	info->mac5 = mlx_xpm_file_to_image(info->mlx,
			"./halo/MA/MAC5.xpm", &info->w, &info->h);
	info->mac6 = mlx_xpm_file_to_image(info->mlx,
			"./halo/MA/MAC6.xpm", &info->w, &info->h);
	info->mac7 = mlx_xpm_file_to_image(info->mlx,
			"./halo/MA/MAC7.xpm", &info->w, &info->h);
	info->mar1 = mlx_xpm_file_to_image(info->mlx,
			"./halo/MA/MAR1.xpm", &info->w, &info->h);
	info->mar2 = mlx_xpm_file_to_image(info->mlx,
			"./halo/MA/MAR2.xpm", &info->w, &info->h);
	info->mar3 = mlx_xpm_file_to_image(info->mlx,
			"./halo/MA/MAR3.xpm", &info->w, &info->h);
	info->mar4 = mlx_xpm_file_to_image(info->mlx,
			"./halo/MA/MAR4.xpm", &info->w, &info->h);
	info->mar5 = mlx_xpm_file_to_image(info->mlx,
			"./halo/MA/MAR5.xpm", &info->w, &info->h);
}

void	xpm_norminette(t_info *info)
{
	info->shr3 = mlx_xpm_file_to_image(info->mlx,
			"./halo/SH/SHR3.xpm", &info->w, &info->h);
	info->sn1 = mlx_xpm_file_to_image(info->mlx,
			"./halo/SN/SN1.xpm", &info->w, &info->h);
	info->sn2 = mlx_xpm_file_to_image(info->mlx,
			"./halo/SN/SN2.xpm", &info->w, &info->h);
	info->sn3 = mlx_xpm_file_to_image(info->mlx,
			"./halo/SN/SN3.xpm", &info->w, &info->h);
	info->snr1 = mlx_xpm_file_to_image(info->mlx,
			"./halo/SN/SNR1.xpm", &info->w, &info->h);
	info->snr2 = mlx_xpm_file_to_image(info->mlx,
			"./halo/SN/SNR2.xpm", &info->w, &info->h);
	info->snr3 = mlx_xpm_file_to_image(info->mlx,
			"./halo/SN/SNR3.xpm", &info->w, &info->h);
}

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
