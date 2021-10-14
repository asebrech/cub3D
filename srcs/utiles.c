/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:57:23 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/14 10:55:19 by asebrech         ###   ########.fr       */
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
