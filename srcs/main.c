/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:27:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/30 14:47:39 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_struct(t_info *info)
{
	info->up = 0;
	info->down = 0;
	info->right = 0;
	info->left = 0;
	info->lookr = 0;
	info->lookl = 0;
	info->map = NULL;
	info->cno = NULL;
	info->cso = NULL;
	info->cwe = NULL;
	info->cea = NULL;
	info->lst = NULL;
	info->map = NULL;
	info->player = 0;
	fuck_the_norm(info);
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
