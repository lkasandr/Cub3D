#include "cub.h"

static void	initial_struct(int fd, int flag, t_img *img)
{
	t_val		value;
	t_player	player;
	t_plane		plane;
	t_all		all;

	parse_file(&value, *img, fd);
	player_position(&player, value.map);
	initial_plane_struct(&plane, value, player);
	init_all(&all, &value, &player, &plane);
	all.img = img;
	init_nsw_tex(all, &img->tex_n, &img->tex_s, &img->tex_w);
	init_sprite_east_text(all, &img->tex_e, &img->sprite);
	img->mlx_win = mlx_new_window(img->mlx, value.scr_w, value.scr_h, "Cub3D");
	img->img = mlx_new_image(img->mlx, value.scr_w, value.scr_h);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->length, &img->end);
	draw_frame(&all);
	if (flag == 1)
		make_screenshot(all, *all.img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_destroy_image(img->mlx, img->img);
	mlx_loop_hook(img->mlx, render_map, &all);
	mlx_hook(img->mlx_win, 2, (1L << 0), key_press, &all);
	mlx_hook(img->mlx_win, 3, (1L << 1), key_release, &all);
	mlx_hook(img->mlx_win, 17, (1L << 17), exit_game, &all);
	mlx_loop(img->mlx);
}

static int	check_map_path(char *map_path)
{
	int	b;

	b = ft_strlen(map_path);
	if (map_path[b - 4] != '.')
		return (-1);
	if (map_path[b - 3] != 'c')
		return (-1);
	if (map_path[b - 2] != 'u')
		return (-1);
	if (map_path[b - 1] != 'b')
		return (-1);
	return (0);
}

static int	fd_open(char *map_path)
{
	int	fd;

	fd = 0;
	if (!(ft_strstr(map_path, ".cub")))
		ft_error("Wrong expansion of file!");
	if (check_map_path(map_path) == -1)
		ft_error("Wrong expansion of file!");
	if (ft_strlen(map_path) <= 4)
		ft_error("Wrong file path!");
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		perror("Error\nCan't open file");
	return (fd);
}

static int	check_arguments(int argv, char **str)
{
	if (argv < 2 || argv > 3)
		ft_error("wrong number of arguments!");
	if (argv == 3)
	{
		if (!(ft_strstr(str[2], "--save")) && (ft_strlen(str[2]) != 6))
			ft_error("wrong second parameter!");
		else
			return (1);
	}
	return (0);
}

int	main(int argv, char **argc)
{
	t_img	img;
	int		fd;
	int		flag;

	flag = check_arguments(argv, argc);
	if (flag == -1)
		return (-1);
	fd = fd_open(argc[1]);
	if (fd == -1)
		ft_error("open failed on input file");
	img.mlx = mlx_init();
	initial_struct(fd, flag, &img);
	return (fd);
}
