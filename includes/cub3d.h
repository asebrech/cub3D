/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:32:11 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/27 18:21:21 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# define PI 3.14159

typedef struct s_info
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	char	**map;
	int		map_len;
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
	char	player;
	double	angle;
	int		px;
	int		py;
	int		minicub;
	int		cub;
}				t_info;

// utiles
void	my_mlx_pixel_put(t_info *data, int x, int y, int color);
void	ft_exit(char *str, t_info *info, int index);
void	ft_print_struct(t_info *info);
double	to_radian(double nb);
void	player_start(int i, int j, t_info *info);

// parsing
void	ft_parsing(t_info *info);
void	fill_color(t_info *info, char *line);
char	*check_int(t_info *info, char *line, int *i);
void	fill_path(t_info *info, char *line, int index);
void	check_file(t_info *info, char *str, int index);
void	struct_fill(t_info *info, char *str, int nb, int index);
void	parse_map(t_info *info, t_list *lst);

// cub3d
void	cub3d(t_info *info);
void	move(t_info *info, int keycode);
void	minimap(t_info *info);
void	find_wall(t_info *info, double *c);
void	move(t_info *info, int keycode);

// find wall
int		find_a(t_info *info, double *b);
void	final_wall_a_1(t_info *info, double *b, int yb, int xb);
void	final_wall_a(t_info *info, double *a);

#endif
