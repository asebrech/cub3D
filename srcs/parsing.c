/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:32:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/15 16:46:38 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	struc_is_full(t_info *info)
{
	if (info->no != NULL && info->so != NULL && info->we != NULL
		&& info->ea != NULL && info->fr != -1 && info->fg != -1
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

void	ft_print_struct(t_info *info)
{
	printf("NO = %s\n", info->no);
	printf("SO = %s\n", info->so);
	printf("WE = %s\n", info->we);
	printf("EA = %s\n", info->ea);
	printf("Fr = %d\n", info->fr);
	printf("Fg = %d\n", info->fg);
	printf("Fb = %d\n", info->fb);
	printf("Cr = %d\n", info->cr);
	printf("Cg = %d\n", info->cg);
	printf("Cb = %d\n", info->cb);
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
		{
			if (parse_line(info, line))
			{
				printf("%s\n", line);
				j = 1;
			}
			else
				free(line);
		}
		else
			printf("%s\n", line);
	}
	close(fd);
}
