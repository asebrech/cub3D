/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resource.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:34:38 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/11 11:37:18 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	struct_fill(t_info *info, char *str, int nb, int index)
{
	if (index == 1 && info->cno == NULL)
		info->cno = str;
	else if (index == 2 && info->cso == NULL)
		info->cso = str;
	else if (index == 3 && info->cwe == NULL)
		info->cwe = str;
	else if (index == 4 && info->cea == NULL)
		info->cea = str;
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
		ft_exit("duplicated resource\n", info, 1);
}

void	check_file(t_info *info, char *str, int index)
{
	int		fd;
	char	buf[10];

	if (open(str, O_DIRECTORY) > 0)
		ft_exit("resource file must be a file\n", info, 1);
	fd = open(str, O_RDONLY);
	if (fd <= 0)
		ft_exit("resource file not found or not valid\n", info, 1);
	read(fd, buf, 9);
	buf[9] = '\0';
	if (ft_strncmp("/* XPM */", buf, 9))
		ft_exit("resource is not in xpm format\n", info, 1);
	close(fd);
	struct_fill(info, str, -2, index);
}

void	fill_path(t_info *info, char *line, int index)
{
	int		i;
	int		j;

	i = 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i + j] && !ft_isspace(line[i + j]))
		j++;
	check_file(info, ft_substr(line, i, j), index);
	while (line[i + j] && ft_isspace(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		ft_exit("wrong format in the resource file (path)\n", info, 1);
}

char	*check_int(t_info *info, char *line, int *i)
{
	static int	k = 0;
	int			j;
	char		*str;

	j = 0;
	k++;
	while (line[*i] && ft_isspace(line[*i]))
		*i += 1;
	if (!ft_isdigit(line[*i]))
		ft_exit("wrong format in the resource file (digit)\n", info, 1);
	while (line[*i + j] && ft_isdigit(line[*i + j]))
		j++;
	str = ft_substr(line, *i, j);
	*i = *i + j;
	while (line[*i] && ft_isspace(line[*i]))
		*i += 1;
	if (line[*i] != ',' && k % 3 != 0)
		ft_exit("wrong format in the resource file (digit)\n", info, 1);
	if (line[*i] != '\0' && k % 3 == 0)
		ft_exit("wrong format in the resource file (digit)\n", info, 1);
	*i += 1;
	return (str);
}

void	fill_color(t_info *info, char *line)
{
	int			i;
	int			k;
	int			tmp;
	char		*str;
	static int	j = 4;

	k = 0;
	i = 1;
	while (k < 3)
	{
		str = check_int(info, line, &i);
		tmp = ft_atoi(str);
		if (tmp > 255 || tmp < 0)
			ft_exit("resource too big or not big enough\n", info, 1);
		struct_fill(info, NULL, tmp, ++j);
		free(str);
		k++;
	}
}
