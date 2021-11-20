/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <alois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:32:11 by asebrech          #+#    #+#             */
/*   Updated: 2021/11/20 18:05:30 by alois            ###   ########.fr       */
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
	int		weapon;
	int		wp;
	int		fire;
	int		reload;
	int		cross;
	void	*ar1;
	void	*ar2;
	void	*ar3;
	void	*arc1;
	void	*arc2;
	void	*arc3;
	void	*arr1;
	void	*arr2;
	void	*arr3;
	void	*arr4;
	void	*arr5;
	void	*ma1;
	void	*ma2;
	void	*ma3;
	void	*ma4;
	void	*mac1;
	void	*mac2;
	void	*mac3;
	void	*mac4;
	void	*mac5;
	void	*mac6;
	void	*mac7;
	void	*mar1;
	void	*mar2;
	void	*mar3;
	void	*mar4;
	void	*mar5;
	void	*pp1;
	void	*pp2;
	void	*pp3;
	void	*pp4;
	void	*pp5;
	void	*ppr1;
	void	*pr1;
	void	*pr2;
	void	*pr3;
	void	*pr4;
	void	*pr5;
	void	*pr6;
	void	*sh1;
	void	*sh2;
	void	*sh3;
	void	*sh4;
	void	*sh5;
	void	*sh6;
	void	*shr1;
	void	*shr2;
	void	*shr3;
	void	*sn1;
	void	*sn2;
	void	*sn3;
	void	*snr1;
	void	*snr2;
	void	*snr3;
	void	*hud;
	int		ar;
	int		ma;
	int		pp;
	int		pr;
	int		sh;
	int		sn;
}				t_info;

// utiles
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_exit(char *str, t_info *info, int index);
double	to_radian(double nb);
void	player_start(int i, int j, t_info *info);
int		mlx_pixel_get(t_data *data, int x, int y);
int		create_trgb(int t, int r, int g, int b);
void	dda(double *x, double *y, t_info *info);

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
void	display_ammo(t_info *info);

// find wall
int		find_v(t_info *info, double *v, double angle);
void	final_wall_v_1(t_info *info, double *v, double *inc, double angle);
void	final_wall_v(t_info *info, double *v, double angle);

// sprite
void	sprite(t_info *info);
void	fire_ar(t_info *info);

// event
int		mouse(int x , int y, t_info *info);
int		ft_close(t_info *info);
int		render_next_frame(t_info *info);
//int		mouse_hook(int button, int	x, int y, t_info *info);
int		buttonpress(int button, int	x, int y, t_info *info);
int		buttonrelease(int button, int	x, int y, t_info *info);

// xpm
void	open_xpm(t_info *info);

// animation
void	fire_ar(t_info *info);
void	cross_ar(t_info *info);
void	reload_ar(t_info *info);
void	fire_ma(t_info *info);
void	cross_ma(t_info *info);
void	reload_ma(t_info *info);
void	fire_pp(t_info *info);
void	fire_pr(t_info *info);
void	fire_sh(t_info *info);
void	reload_sh(t_info *info);
void	fire_sn(t_info *info);
void	reload_sn(t_info *info);
#endif
