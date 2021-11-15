/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:40:30 by alois             #+#    #+#             */
/*   Updated: 2021/11/15 12:34:22 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	xpm_shotgun(t_info *info)
{
	info->sh1 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SH1.xpm", &info->w, &info->h);
	info->sh2 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SH2.xpm", &info->w, &info->h);
	info->sh3 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SH3.xpm", &info->w, &info->h);
	info->sh4 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SH4.xpm", &info->w, &info->h);
	info->sh5 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SH5.xpm", &info->w, &info->h);
	info->sh6 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SH6.xpm", &info->w, &info->h);
	info->shr1 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SHR1.xpm", &info->w, &info->h);
	info->shr2 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SHR2.xpm", &info->w, &info->h);
	info->shr3 = mlx_xpm_file_to_image(info->mlx, "./halo/SH/SHR3.xpm", &info->w, &info->h);
	info->sn1 = mlx_xpm_file_to_image(info->mlx, "./halo/SN/SN1.xpm", &info->w, &info->h);
	info->sn2 = mlx_xpm_file_to_image(info->mlx, "./halo/SN/SN2.xpm", &info->w, &info->h);
	info->sn3 = mlx_xpm_file_to_image(info->mlx, "./halo/SN/SN3.xpm", &info->w, &info->h);
	info->snr1 = mlx_xpm_file_to_image(info->mlx, "./halo/SN/SNR1.xpm", &info->w, &info->h);
	info->snr2 = mlx_xpm_file_to_image(info->mlx, "./halo/SN/SNR2.xpm", &info->w, &info->h);
	info->snr3 = mlx_xpm_file_to_image(info->mlx, "./halo/SN/SNR3.xpm", &info->w, &info->h);
}

void	xpm_ppistol(t_info *info)
{
	info->pp1 = mlx_xpm_file_to_image(info->mlx, "./halo/PP/PP1.xpm", &info->w, &info->h);
	info->pp2 = mlx_xpm_file_to_image(info->mlx, "./halo/PP/PP2.xpm", &info->w, &info->h);
	info->pp3 = mlx_xpm_file_to_image(info->mlx, "./halo/PP/PP3.xpm", &info->w, &info->h);
	info->pp4 = mlx_xpm_file_to_image(info->mlx, "./halo/PP/PP4.xpm", &info->w, &info->h);
	info->pp5 = mlx_xpm_file_to_image(info->mlx, "./halo/PP/PP5.xpm", &info->w, &info->h);
	info->ppr1 = mlx_xpm_file_to_image(info->mlx, "./halo/PP/PPR.xpm", &info->w, &info->h);
	info->pr1 = mlx_xpm_file_to_image(info->mlx, "./halo/PR/PR1.xpm", &info->w, &info->h);
	info->pr2 = mlx_xpm_file_to_image(info->mlx, "./halo/PR/PR2.xpm", &info->w, &info->h);
	info->pr3 = mlx_xpm_file_to_image(info->mlx, "./halo/PR/PR3.xpm", &info->w, &info->h);
	info->pr4 = mlx_xpm_file_to_image(info->mlx, "./halo/PR/PR4.xpm", &info->w, &info->h);
	info->pr5 = mlx_xpm_file_to_image(info->mlx, "./halo/PR/PR5.xpm", &info->w, &info->h);
	xpm_shotgun(info);
}

void	xpm_magnum(t_info *info)
{
	info->ma1 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MA1.xpm", &info->w, &info->h);
	info->ma2 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MA2.xpm", &info->w, &info->h);
	info->ma3 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MA3.xpm", &info->w, &info->h);
	info->ma4 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MA4.xpm", &info->w, &info->h);
	info->mac1 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAC1.xpm", &info->w, &info->h);
	info->mac2 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAC2.xpm", &info->w, &info->h);
	info->mac3 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAC3.xpm", &info->w, &info->h);
	info->mac4 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAC4.xpm", &info->w, &info->h);
	info->mac5 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAC5.xpm", &info->w, &info->h);
	info->mac6 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAC6.xpm", &info->w, &info->h);
	info->mac7 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAC7.xpm", &info->w, &info->h);
	info->mar1 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAR1.xpm", &info->w, &info->h);
	info->mar2 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAR2.xpm", &info->w, &info->h);
	info->mar3 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAR3.xpm", &info->w, &info->h);
	info->mar4 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAR4.xpm", &info->w, &info->h);
	info->mar5 = mlx_xpm_file_to_image(info->mlx, "./halo/MA/MAR5.xpm", &info->w, &info->h);
	xpm_ppistol(info);
}

void	open_xpm(t_info *info)
{
	info->hud = mlx_xpm_file_to_image(info->mlx, "./halo/HUD.xpm", &info->w, &info->h);
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
	xpm_magnum(info);
}