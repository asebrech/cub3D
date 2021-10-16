/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:52:33 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/16 19:17:16 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	lst_to_char(t_info *info, t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp->next && ++i)
		tmp = tmp->next;
	info->map = malloc(sizeof(char *) * i);
	info->map_len = i - 1;
	i = 0;
	while (lst->next)
	{
		info->map[i] = lst->content;
		lst = lst->next;
		i++;
	}
	info->map[i] = NULL;
}

void	check_char(t_info *info, int i, int j)
{
	if ((info->map[i][j] != '0' && info->map[i][j] != '1'
		&& info->map[i][j] != 'W' && info->map[i][j] != 'N'
		&& info->map[i][j] != 'E' && info->map[i][j] != 'S'
		&& info->map[i][j] != ' '))
		ft_exit("forbidden character in the map\n", info, 1);
}

int	check_left_right(t_info *info, int i, int j)
{
	int		k;

	k = j;
	while (info->map[i][k])
	{
		if (!info->map[i][k + 1])
		{
			printf("toto\n");
			return (1);
		}
		else if (info->map[i][k + 1] == '1')
			break ;
		k++;
	}
	k = j;
	while (k >= 0)
	{
		if (k - 1 == -1)
		{
			printf("hello\n");
			return (1);
		}
		else if (info->map[i][k - 1] == '1')
			break ;
		k--;
	}
	return (0);
}

int	check_up_down(t_info *info, int i, int j)
{
	int		k;

	k = i;
	printf("%c", info->map[i][j]);
	while (info->map[k] != NULL)
	{
		if (info->map[k + 1] == NULL || !info->map[k + 1][j])
		{
			printf("there\n");
			return (1);
		}
		else if (info->map[k + 1][j] == '1')
			break ;
		k++;
	}
	k = i;
	while (k >= 0)
	{
		if (k - 1 == -1 || !info->map[k][j])
		{
			printf("the way\n");
			return (1);
		}
		else if (info->map[k - 1][j] == '1')
			break ;
		k--;
	}
	return (0);
}

void	check_wall(t_info *info)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (info->map[++i] != NULL)
	{
		if (!info->map[i])
			ft_exit("wall is not closed 1\n", info, 1);
		j = -1;
		while (info->map[i][++j])
		{
			//printf("%c", info->map[i][j]);
			check_char(info, i, j);
			k = j;
			while (info->map[i][k] && info->map[i][k] == ' ')
				k++;
			if (!info->map[i][k] || j == 0)
				j = k - 1;
			else if (info->map[i][j] == '0' || info->map[i][j] == ' '
				|| info->map[i][j] == 'N')
				if (check_left_right(info, i, j) || check_up_down(info, i, j))
					ft_exit("wall is not closed 2\n", info, 1);
			k = j;
		}
		printf(" end \n");
	}
}

void	parse_map(t_info *info, t_list *lst)
{
	lst_to_char(info, lst);
	check_wall(info);
	printf("succes !\n");
}
