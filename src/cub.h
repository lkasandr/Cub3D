/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:19:53 by lkasandr          #+#    #+#             */
/*   Updated: 2021/04/23 15:58:54 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx_mms/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# define BUFFER_SIZE 2000
# define SPEED 0.12
# define ROT 0.07
# define NEAR 0.05
# define SIZE 64

typedef struct s_sprite {
	float			c;
	float			s;
	struct s_sprite	*next;
}					t_sprite;

typedef struct s_ray
{
	float			angle;
	float			x_hor;
	float			y_hor;
	float			s_hor;
	float			x_vert;
	float			y_vert;
	float			s_vert;
	int				x_grid;
	int				y_grid;
	float			x;
	float			y;
	float			s;
	unsigned int	color;
	float			sprite_x;
	float			sprite_y;
	float			sprite_s;
	float			sprite_c;
	t_sprite		*sprite;
}					t_ray;

typedef struct s_player
{
	float	x;
	float	y;
	float	dir;
}			t_player;

typedef struct s_plane
{
	float	fov;
	float	centr_x;
	float	centr_y;
	float	dist_pp;
	float	angle_ray;
	int		x;
	int		y;
}			t_plane;

typedef struct s_val
{
	int		scr_h;
	int		scr_w;
	int		h;
	int		w;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		f_color;
	int		c_color;
	char	*array;
	char	**map;
	int		map_i;
	int		map_j;
}			t_val;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		end;
}			t_tex;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	turn_left;
	int	turn_right;
}		t_key;

typedef struct s_img {
	void	*mlx;
	void	*mlx_win;
	t_tex	tex_n;
	t_tex	tex_s;
	t_tex	tex_w;
	t_tex	tex_e;
	t_tex	sprite;
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		end;
}			t_img;

typedef struct s_all
{
	t_val		*value;
	t_player	*player;
	t_plane		*plane;
	t_img		*img;
	t_key		key;
}				t_all;

void	*ft_error(char *str);
void	parse_file(t_val *value, t_img img, int fd);
char	*skip_space(char *line, t_val *value);
void	parse_resolution(char *line, t_val *value, t_img img);
void	parse_north_texture(char *line, t_val *value);
void	parse_south_texture(char *line, t_val *value);
void	parse_west_texture(char *line, t_val *value);
void	parse_east_texture(char *line, t_val *value);
void	parse_sprite_texture(char *line, t_val *value);
void	check_texture(char *line);
void	parse_color_floor(char *line, t_val *value);
void	parse_color_ceil(char *line, t_val *value);
int		get_rgb(char *line);
void	parse_map(char *line, t_val *value);
void	skip_empty_line(void);
int		check_value(t_val value);
void	check_symbols(char *line, t_val *value);
int		number_of_player(char **map);
void	check_first_last_line(char **map, t_val *value);
void	check_space_in_map(char **map, t_val *value);
void	check_map_empty_line(char **map, t_val *value);
void	player_position(t_player *player, char **map);
void	initial_plane_struct(t_plane *plane, t_val value, t_player player);
void	init_struct_key(t_all *all);
void	init_all(t_all *all, t_val *value, t_player *player, t_plane *plane);
void	initial_struct_ray(t_ray *ray, t_all all);
void	init_sprite_east_text(t_all all, t_tex *tex_e, t_tex *sprite);
void	init_nsw_tex(t_all all, t_tex *tex_n, t_tex *tex_s, t_tex *tex_w);
void	draw_frame(t_all *all);
void	raycasting(t_all all, t_img img, t_ray ray, float middle_angle);
int		get_color(t_ray ray, t_img img, int i);
void	get_hor_coord_wall(t_all all, t_ray *ray, float x_a, float y_a);
void	get_horisont_distance(t_all all, t_ray *ray);
void	get_vert_coord_wall(t_all all, t_ray *ray, float x_a, float y_a);
void	get_vertical_distance(t_all all, t_ray *ray);
void	proc_sprite(t_all all, t_ray *ray);
void	make_screenshot(t_all all, t_img img);
void	free_sprites(t_sprite *sprite);
void	move_back(t_all *all);
void	move_forward(t_all *all);
void	move_right(t_all *all);
void	move_left(t_all *all);
void	move_player(t_all *all);
int		exit_game(t_all *all);
int		key_release(int key, t_all *all);
int		key_press(int key, t_all *all);
int		render_map(t_all *all);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		my_mlx_pixel_get(t_tex *tex, int x, int y);
void	draw_ceil_floor(t_all all, t_img img, int i);
void	draw_wall(t_all all, t_img img, int i, t_ray ray);
void	draw_sprite(t_all all, t_img img, int i, t_sprite *sprite);
void	check_behind_map(char **map, t_val *value);

#endif
