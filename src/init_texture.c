#include "cub.h"

static void	check_size_texture(int width, int height, t_all all)
{
	if (width != 64 || height != 64)
	{
		free(all.value->map);
		ft_error("Wrong texture size!\n");
	}
}

void	init_nsw_tex(t_all all, t_tex *tex_n, t_tex *tex_s, t_tex *tex_w)
{
	int	width;
	int	height;

	tex_n->img = mlx_xpm_file_to_image(all.img->mlx,
			all.value->north, &width, &height);
	check_size_texture(width, height, all);
	tex_n->addr = mlx_get_data_addr(tex_n->img, &tex_n->bpp,
			&tex_n->length, &tex_n->end);
	tex_s->img = mlx_xpm_file_to_image(all.img->mlx, all.value->south,
			&width, &height);
	check_size_texture(width, height, all);
	tex_s->addr = mlx_get_data_addr(tex_s->img, &tex_s->bpp,
			&tex_s->length, &tex_s->end);
	tex_w->img = mlx_xpm_file_to_image(all.img->mlx, all.value->west,
			&width, &height);
	check_size_texture(width, height, all);
	tex_w->addr = mlx_get_data_addr(tex_w->img, &tex_w->bpp,
			&tex_w->length, &tex_w->end);
}

void	init_sprite_east_text(t_all all, t_tex *tex_e, t_tex *sprite)
{
	int	width;
	int	height;

	sprite->img = mlx_xpm_file_to_image(all.img->mlx,
			all.value->sprite, &width, &height);
	check_size_texture(width, height, all);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->length, &sprite->end);
	tex_e->img = mlx_xpm_file_to_image(all.img->mlx, all.value->east,
			&width, &height);
	check_size_texture(width, height, all);
	tex_e->addr = mlx_get_data_addr(tex_e->img, &tex_e->bpp,
			&tex_e->length, &tex_e->end);
}
