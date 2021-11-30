/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:20:20 by alois             #+#    #+#             */
/*   Updated: 2021/11/30 15:14:57 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_close(t_info *info)
{
	ft_exit(NULL, info, 0);
	return (0);
}

int	render_next_frame(t_info *info)
{
	info->mouse = info->mousex - (info->x / 2);
	move(info);
	mlx_mouse_move(info->win, info->x / 2, info->y / 2);
	info->mousex = info->x / 2;
	if (!info->up && !info->down && !info->right
		&& !info->left && !info->lookr && !info->lookl)
		print_screen(info);
	return (0);
}

int	mouse(int x, int y, t_info *info)
{
	info->mousex = x;
	(void)y;
	return (0);
}

int	buttonpress(int button, int x, int y, t_info *info)
{
	if (button == 1)
		info->fire = button;
	(void)x;
	(void)y;
	return (0);
}

int	buttonrelease(int button, int x, int y, t_info *info)
{
	info->fire = 0;
	(void)info;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}
