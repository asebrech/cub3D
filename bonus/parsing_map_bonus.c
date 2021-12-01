/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:52:33 by asebrech          #+#    #+#             */
/*   Updated: 2021/12/01 14:50:32 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	lst_to_char(t_info *info, t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	if (!tmp)
		ft_exit("ressource file must have a map\n", info, 1);
	while (tmp->next && ++i)
		tmp = tmp->next;
	info->map = malloc(sizeof(char *) * (i + 2));
	tmp = lst;
	i = 0;
	while (tmp->next)
	{
		info->map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	info->map[i] = tmp->content;
	info->map[i + 1] = NULL;
	info->map_len = i;
}

void	check_char(t_info *info, int i, int j)
{
	if ((info->map[i][j] != '0' && info->map[i][j] != '1'
		&& info->map[i][j] != 'W' && info->map[i][j] != 'N'
		&& info->map[i][j] != 'E' && info->map[i][j] != 'S'
		&& info->map[i][j] != ' '))
		ft_exit("forbidden character in the map\n", info, 1);
	if (info->map[i][j] != '1' && info->map[i][j] != ' '
		&& info->map[i][j] != '0')
	{
		info->player = info->map[i][j];
		player_start(i, j, info);
	}
}

int	check_left_right(t_info *info, int i, int j)
{
	int		k;

	k = j;
	while (info->map[i][k])
	{
		if (info->map[i][k] == ' ')
			return (1);
		if (info->map[i][k] == '1')
			break ;
		if (!info->map[i][k + 1])
			return (1);
		k++;
	}
	k = j;
	while (k >= 0)
	{
		if (info->map[i][k] == ' ')
			return (1);
		if (info->map[i][k] == '1')
			break ;
		if (k - 1 == -1)
			return (1);
		k--;
	}
	return (0);
}

int	check_up_down(t_info *info, int i, int j)
{
	int		k;

	k = i;
	while (info->map[k] != NULL)
	{
		if (info->map[k][j] == ' ')
			return (1);
		if (info->map[k][j] == '1')
			break ;
		if (info->map[k] == NULL || !(info->map[k][j]))
			return (1);
		k++;
	}
	k = i;
	while (k >= 0)
	{
		if (info->map[k][j] == ' ')
			return (1);
		if (info->map[k][j] == '1')
			break ;
		if (k - 1 == -1 || !info->map[k][j])
			return (1);
		k--;
	}
	return (0);
}

void	parse_map(t_info *info, t_list *lst)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = -1;
	lst_to_char(info, lst);
	while (info->map[++i] != NULL)
	{
		if (!info->map[i])
			ft_exit("wall is not closed\n", info, 1);
		j = -1;
		while (info->map[i][++j])
		{
			check_char(info, i, j);
			if (pars_norm(info, &c, i, j))
			{
				if (check_up_down(info, i, j)
					|| check_left_right(info, i, j) || c > 1)
					ft_exit("wall is not closed or duplicated spawn character\n",
						info, 1);
			}
		}
	}
}
