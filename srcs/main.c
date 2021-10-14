/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:27:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/14 17:34:02 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_struct(t_info *info)
{
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
}

static void	check_arg(char *str, t_info *info)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4 || !(ft_strnstr(&str[len - 4], ".cub", 4)))
	{
		ft_putstr_fd("Error\nWrong argument format\n", 2);
		exit(1);
	}
	if (open(str, O_DIRECTORY) > 0)
	{
		ft_putstr_fd("Error\n.cub is not a file\n", 2);
		exit(1);
	}
	if (open(str, O_RDONLY) <= 0)
	{
		ft_putstr_fd("Error\n.cub not found or not valid\n", 2);
		exit(1);
	}
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
	}
	else
		printf("cub3D need one argument\n");
	return (0);
}
