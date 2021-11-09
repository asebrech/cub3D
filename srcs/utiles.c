/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:57:23 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/09 16:08:13 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_start(int i, int j, t_info *info)
{
	info->px = j * info->cub + info->cub / 2;
	info->py = i * info->cub + info->cub / 2;
	if (info->player == 'N')
		info->angle = 90;
	else if (info->player == 'S')
		info->angle = 270;
	else if (info->player == 'E')
		info->angle = 360;
	else if (info->player == 'W')
		info->angle = 180;
}

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

void	ft_print_struct(t_info *info)
{
	printf("NO = %s\n", info->cno);
	printf("SO = %s\n", info->cso);
	printf("WE = %s\n", info->cwe);
	printf("EA = %s\n", info->cea);
	printf("Fr = %d\n", info->fr);
	printf("Fg = %d\n", info->fg);
	printf("Fb = %d\n", info->fb);
	printf("Cr = %d\n", info->cr);
	printf("Cg = %d\n", info->cg);
	printf("Cb = %d\n", info->cb);
}
