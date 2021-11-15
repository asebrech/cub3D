/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:32:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/15 11:27:38 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	struc_is_full(t_info *info)
{
	if (info->cno != NULL && info->cso != NULL && info->cwe != NULL
		&& info->cea != NULL && info->fr != -1 && info->fg != -1
		&& info->fb != -1 && info->cr != -1 && info->cg != -1 && info->cb != -1)
		return (1);
	else
		return (0);
}

int	parse_line(t_info *info, char *line)
{
	int		i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
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
		return (0);
	else if (struc_is_full(info))
		return (1);
	else
		ft_exit("incorrect resource format\n", info, 1);
	return (0);
}

void	get_map(t_list **alst, char *line, t_info *info)
{
	t_list		*new;
	static int	i = 0;
	int			j;

	j = 0;
	while (line[j] && ft_isspace(line[j]))
		j++;
	if (line[j] == '\0')
		ft_exit("forbidden new line in the map\n", info, 1);
	if (i == 0)
		*alst = ft_lstnew(line);
	else
	{
		new = ft_lstnew(line);
		ft_lstadd_back(alst, new);
	}
	i++;
}

void	dumb_norm(t_info *info, char *line, t_list **lst, int *j)
{
	if (parse_line(info, line))
	{
		get_map(lst, line, info);
		*j = 1;
	}
	else
		free(line);
}

void	ft_parsing(t_info *info)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 1;
	j = 0;
	fd = open(info->path, O_RDONLY);
	while (i)
	{
		i = get_next_line(fd, &line);
		if (!j)
			dumb_norm(info, line, &info->lst, &j);
		else
			get_map(&info->lst, line, info);
	}
	close(fd);
	parse_map(info, info->lst);
	if (!info->player)
		ft_exit("there must be at least one player\n", info, 1);
}
