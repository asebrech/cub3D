/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:32:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/13 18:07:24 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	struct_fill(t_info *info, char *str, int index)
{
	if (index == 1 && info->no == NULL)
		info->no = str;
	else if (index == 2 && info->so == NULL)
		info->so = str;
	else if (index == 3 && info->we == NULL)
		info->we = str;
	else if (index == 4 && info->ea == NULL)
		info->ea = str;
	else if (index == 5 && info->f == NULL)
		info->f = str;
	else if (index == 6 && info->c == NULL)
		info->c = str;
	else
		ft_exit("duplicate resource\n", info);
}

void	check_file(t_info *info, char *str, int index)
{
	int		fd;
	char	*line;	

	line = NULL;
	if (open(str, O_DIRECTORY) > 0)
		ft_exit("resource is not a file\n", info);
	fd = open(str, O_RDONLY);
	if (fd <= 0)
		ft_exit("resource not found or not valid\n", info);
	get_next_line(fd, &line);
	if (ft_strncmp("/* XPM */", line, 10))
	{
		free(line);
		ft_exit("resource is not in xpm format\n", info);
	}
	free(line);
	struct_fill(info, str, index);
}

void	fill_path(t_info *info, char *line, int index)
{
	int		i;
	int		j;

	i = 0;
	while (!ft_isspace(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	j = 0;
	while (!ft_isspace(line[i + j]))
		j++;
	check_file(info, ft_substr(line, i, j), index);
	while (ft_isspace(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		ft_exit("wrong format in the resource file\n", info);
}

void	parse_line(t_info *info, char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!ft_strncmp("NO", (line + i), 2))
		fill_path(info, line + i, 1);
	else if (!ft_strncmp("SO", (line + i), 2))
		fill_path(info, line + i, 2);
	else if (!ft_strncmp("WE", (line + i), 2))
		fill_path(info, line + i, 3);
	else if (!ft_strncmp("EA", (line + i), 2))
		fill_path(info, line + i, 4);
	else if (!ft_strncmp("F", (line + i), 1))
		fill_path(info, line + i, 5);
	else if (!ft_strncmp("C", (line + i), 1))
		fill_path(info, line + i, 6);
	else if (line[i] == '\0')
		;
	else
		ft_exit("too much or not enough resource\n", info);
}

void	fill_resource(t_info *info)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open(info->path, O_RDONLY);
	line = NULL;
	while (i)
	{
		i = get_next_line(fd, &line);
		if (i < 0)
			break ;
		parse_line(info, line);
		free(line);
	}
}

void	ft_parsing(t_info *info)
{
	fill_resource(info);
}
