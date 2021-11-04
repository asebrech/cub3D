/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:27:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/04 14:15:43 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_struct(t_info *info)
{
	info->map = NULL;
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->ea = NULL;
	info->fr = -1;
	info->fg = -1;
	info->fb = -1;
	info->cr = -1;
	info->cg = -1;
	info->cb = -1;
	info->x = 1800.0;
	info->y = 900.0;
	info->cub = 64.0;
	info->minicub = info->cub; // / 4
	info->fov = 60.0;
}

static void	check_arg(char *str, t_info *info)
{
	int	len;
	int	fd;

	len = ft_strlen(str);
	if (len <= 4 || !(ft_strnstr(&str[len - 4], ".cub", 4)))
	{
		ft_putstr_fd("Error\nWrong argument format\n", 2);
		exit(1);
	}
	fd = open(str, O_DIRECTORY);
	if (fd > 0)
	{
		ft_putstr_fd("Error\n.cub must be a file\n", 2);
		exit(1);
	}
	close (fd);
	fd = open(str, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\n.cub not found or not valid\n", 2);
		exit(1);
	}
	close (fd);
	info->path = str;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		check_arg(argv[1], &info);
		fill_struct(&info);
		ft_parsing(&info);
		cub3d(&info);
	}
	else
		printf("cub3D need one argument\n");
	return (0);
}
