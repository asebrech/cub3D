/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:22:55 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/20 20:28:48 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	player_start(int i, int j, t_info *info)
{
	info->px = j * info->cub + info->cub / 2;
	info->py = i * info->cub + info->cub / 2;
	info->minipx = j * info->minicub + info->minicub / 2;
	info->minipy = i * info->minicub + info->minicub / 2;
	if (info->player == 'N')
		info->angle = 90;
	else if (info->player == 'S')
		info->angle = 270;
	else if (info->player == 'E')
		info->angle = 360;
	else if (info->player == 'W')
		info->angle = 180;
}

void	dda(double *x, double *y, t_info *info)
{
	double	dx;
	double	dy;
	int		step;
	double	xinc;
	double	yinc;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xinc = dx / step;
	yinc = dy / step;
	while (step > 0)
	{
		if (x[0] >= 0 && y[0] >= 0 && x[0] < info->x && y[0] < info->y)
			my_mlx_pixel_put(&info->img, round(x[0]), round(y[0]), 0x00FF0000);
		x[0] = x[0] + xinc;
		y[0] = y[0] + yinc;
		step--;
	}	
}

void	display_weapon(t_info *info)
{
	if (info->weapon == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->har, 1500, 40);
	else if (info->weapon == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->hma, 1570, 40);
	else if (info->weapon == 3)
		mlx_put_image_to_window(info->mlx, info->win, info->hpp, 1560, 40);
	else if (info->weapon == 4)
		mlx_put_image_to_window(info->mlx, info->win, info->hpr, 1540, 40);
	else if (info->weapon == 5)
		mlx_put_image_to_window(info->mlx, info->win, info->hsh, 1495, 50);
	else if (info->weapon == 6)
		mlx_put_image_to_window(info->mlx, info->win, info->hsn, 1490, 40);
}

void	display_ammo(t_info *info)
{
	char	*c;
	char	*tmp;

	tmp = NULL;
	c = NULL;
	if (info->weapon == 1 && info->ar)
		c = ft_itoa(info->ar);
	else if (info->weapon == 2 && info->ma)
		c = ft_itoa(info->ma);
	else if (info->weapon == 3 && info->pp)
		c = ft_itoa(info->pp);
	else if (info->weapon == 4 && info->pr == 0)
		mlx_string_put(info->mlx, info->win, 1700, 65, 0x00FF0000, "OVERHEAT");
	else if (info->weapon == 4 && info->pr)
		c = ft_itoa(info->pr);
	else if (info->weapon == 5 && info->sh)
		c = ft_itoa(info->sh);
	else if (info->weapon == 6 && info->sn)
		c = ft_itoa(info->sn);
	else
		mlx_string_put(info->mlx, info->win, 1700, 65, 0x00FF0000, "RELOAD");
	if (c)
	{
		if (info->weapon == 3 || info->weapon == 4)
			tmp = ft_strjoin(c, "%");
		else
			tmp = ft_strjoin(c, "");
		mlx_string_put(info->mlx, info->win, 1700, 65, 0x00FF0000, tmp);
	}
	free(tmp);
	free(c);
	display_weapon(info);
}