/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:32:11 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/14 13:03:46 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# define PI 3.14159

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_info
{
	t_data	img;
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	int		x;
	int		y;
	t_list	*lst;
	char	**map;
	int		map_len;
	char	*path;
	t_data	no;
	t_data	so;
	t_data	we;
	t_data	ea;
	char	*cno;
	char	*cso;
	char	*cwe;
	char	*cea;
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
	char	player;
	double	angle;
	double	px;
	double	py;
	double	minipx;
	double	minipy;
	double	wall_x;
	double	wall_y;
	char	wall_type;
	double	wall_len;
	int		txt_x;
	int		txt_y;
	double	minicub;
	double	cub;
	double	fov;
	double	plane;
	int		up;
	int		down;
	int		right;
	int		left;
	int		lookr;
	int		lookl;
	int		mouse;
	int		mousex;
	int		run;
}				t_info;

// utiles
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_exit(char *str, t_info *info, int index);
double	to_radian(double nb);
void	player_start(int i, int j, t_info *info);
int		mlx_pixel_get(t_data *data, int x, int y);
int		create_trgb(int t, int r, int g, int b);
void	dda(double *x, double *y, t_info *info);
int		ft_close(t_info *info);
int		render_next_frame(t_info *info);

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
void	move(t_info *info);
void	minimap(t_info *info);
void	find_wall(t_info *info, double angle);
void	print_screen(t_info *info);
void	map(t_info *info);

// find wall
int		find_v(t_info *info, double *v, double angle);
void	final_wall_v_1(t_info *info, double *v, double *inc, double angle);
void	final_wall_v(t_info *info, double *v, double angle);

// sprite
void	sprite(t_info *info);

#endif
