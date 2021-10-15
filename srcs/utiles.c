/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:57:23 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/15 17:48:16 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_exit(char *str, t_info *info, int index)
{
	if (index == 1)
		ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	free(info->no);
	free(info->so);
	free(info->we);
	free(info->ea);
	exit(index);
}

void	ft_print_struct(t_info *info)
{
	printf("NO = %s\n", info->no);
	printf("SO = %s\n", info->so);
	printf("WE = %s\n", info->we);
	printf("EA = %s\n", info->ea);
	printf("Fr = %d\n", info->fr);
	printf("Fg = %d\n", info->fg);
	printf("Fb = %d\n", info->fb);
	printf("Cr = %d\n", info->cr);
	printf("Cg = %d\n", info->cg);
	printf("Cb = %d\n", info->cb);
}
