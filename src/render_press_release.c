#include "cub.h"

int	render_map(t_all *all)
{
	mlx_do_sync(all->img->mlx);
	move_player(all);
	all->img->img = mlx_new_image(all->img->mlx, all->value->scr_w,
			all->value->scr_h);
	draw_frame(all);
	all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bpp,
			&all->img->length, &all->img->end);
	mlx_put_image_to_window(all->img->mlx, all->img->mlx_win,
		all->img->img, 0, 0);
	mlx_destroy_image(all->img->mlx, all->img->img);
	return (0);
}

int	key_press(int key, t_all *all)
{
	if (key == 2)
		all->key.d = 1;
	if (key == 0)
		all->key.a = 1;
	if (key == 13)
		all->key.w = 1;
	if (key == 1)
		all->key.s = 1;
	if (key == 124)
		all->key.turn_left = 1;
	if (key == 123)
		all->key.turn_right = 1;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	key_release(int key, t_all *all)
{
	if (key == 2)
		all->key.d = 0;
	if (key == 0)
		all->key.a = 0;
	if (key == 13)
		all->key.w = 0;
	if (key == 1)
		all->key.s = 0;
	if (key == 124)
		all->key.turn_left = 0;
	if (key == 123)
		all->key.turn_right = 0;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
