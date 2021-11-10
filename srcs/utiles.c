/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:57:23 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/10 11:21:07 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
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
	free(info->cno);
	free(info->cso);
	free(info->cwe);
	free(info->cea);
	i = -1;
	while (info->map && info->map[++i] != NULL)
		free(info->map[i]);
	free(info->map);
	exit(index);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
