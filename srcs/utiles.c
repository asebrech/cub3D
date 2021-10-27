/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:57:23 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/27 15:00:13 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	to_radian(double nb)
{
	return (nb * PI / 180);
}

void	ft_exit(char *str, t_info *info, int index)
{
	int		i;

	if (index == 1)
		ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	free(info->no);
	free(info->so);
	free(info->we);
	free(info->ea);
	i = -1;
	while (info->map && info->map[++i] != NULL)
		free(info->map[i]);
	free(info->map);
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
