/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:32:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/14 17:33:20 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	struct_fill(t_info *info, char *str, int nb, int index)
{
	printf("str %s\n", str);
	printf("nb %d\n", nb);
	printf("i %d\n", index);
	if (index == 1 && info->no == NULL)
		info->no = str;
	else if (index == 2 && info->so == NULL)
		info->so = str;
	else if (index == 3 && info->we == NULL)
		info->we = str;
	else if (index == 4 && info->ea == NULL)
		info->ea = str;
	else if (index == 5 && info->fr == -1)
		info->fr = nb;
	else if (index == 6 && info->fg == -1)
		info->fg = nb;
	else if (index == 7 && info->fb == -1)
		info->fb = nb;
	else if (index == 8 && info->cr == -1)
		info->cr = nb;
	else if (index == 9 && info->cg == -1)
		info->cg = nb;
	else if (index == 10 && info->cb == -1)
		info->cb = nb;
	else
		ft_exit("duplicate resource\n", info, 1);
}

void	check_file(t_info *info, char *str, int index)
{
	int		fd;
	char	*line;	

	line = NULL;
	if (open(str, O_DIRECTORY) > 0)
		ft_exit("resource is not a file\n", info, 1);
	fd = open(str, O_RDONLY);
	if (fd <= 0)
		ft_exit("resource not found or not valid\n", info, 1);
	get_next_line(fd, &line);
	if (ft_strncmp("/* XPM */", line, 9))
	{
		free(line);
		ft_exit("resource is not in xpm format\n", info, 1);
	}
	free(line);
	struct_fill(info, str, -2, index);
}

void	fill_path(t_info *info, char *line, int index)
{
	int		i;
	int		j;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	j = 0;
	while (!ft_isspace(line[i + j]))
		j++;
	check_file(info, ft_substr(line, i, j), index);
	while (ft_isspace(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		ft_exit("wrong format in the resource file\n", info, 1);
}

char	*check_int(t_info *info, char *line, int *i)
{
	static int	k = 0;
	int			j;
	char		*str;

	j = 0;
	k++;
	while (ft_isspace(line[*i]))
		*i += 1;
	if (!ft_isdigit(line[*i]))
		ft_exit("wrong format in the ressources file (digit)\n", info, 1);
	while (ft_isdigit(line[*i + j]))
		j++;
	str = ft_substr(line, *i, j);
	*i = *i + j;
	while (ft_isspace(line[*i]))
		*i += 1;
	if (line[*i] != ',' && k % 3 != 0)
		ft_exit("wrong format in the ressources file (digit)\n", info, 1);
	if (line[*i] != '\0' && k % 3 == 0)
		ft_exit("wrong format in the ressources file (digit)\n", info, 1);
	*i += 1;
	return (str);
}

void	fill_color(t_info *info, char *line)
{
	int			i;
	int			tmp;
	char		*str;
	static int	j = 4;

	i = 1;
	str = check_int(info, line, &i);
	tmp = ft_atoi(str);
	if (tmp > 255 || tmp < 0)
		ft_exit("wrong format in the ressources file (digit)\n", info, 1);
	struct_fill(info, NULL, tmp, ++j);
	free(str);
	str = check_int(info, line, &i);
	tmp = ft_atoi(str);
	if (tmp > 255 || tmp < 0)
		ft_exit("wrong format in the ressources file (digit)\n", info, 1);
	struct_fill(info, NULL, tmp, ++j);
	free(str);
	str = check_int(info, line, &i);
	tmp = ft_atoi(str);
	if (tmp > 255 || tmp < 0)
		ft_exit("wrong format in the ressources file (digit)\n", info, 1);
	struct_fill(info, NULL, tmp, ++j);
	free(str);
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
		fill_color(info, line + i);
	else if (!ft_strncmp("C", (line + i), 1))
		fill_color(info, line + i);
	else if (line[i] == '\0')
		;
	else
		ft_exit("too much or not enough resource\n", info, 1);
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
