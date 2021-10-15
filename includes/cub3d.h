/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:32:11 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/15 17:54:19 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_info
{
	char	*path;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
}				t_info;

// utiles
void	ft_exit(char *str, t_info *info, int index);
void	ft_print_struct(t_info *info);

// parsing
void	ft_parsing(t_info *info);
void	fill_color(t_info *info, char *line);
char	*check_int(t_info *info, char *line, int *i);
void	fill_path(t_info *info, char *line, int index);
void	check_file(t_info *info, char *str, int index);
void	struct_fill(t_info *info, char *str, int nb, int index);
void	parse_map(t_info *info, t_list *lst);

#endif
