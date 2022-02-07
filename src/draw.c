#include "cub.h"

void	draw_ceil_floor(t_all all, t_img img, int i)
{
	int	h_ceil;
	int	start_point;
	int	h_floor;

	h_ceil = (int)(roundf(all.value->scr_h / 2));
	h_floor = all.value->scr_h - h_ceil;
	start_point = 0;
	while (h_ceil > 0)
	{
		my_mlx_pixel_put(&img, i, start_point, all.value->c_color);
		h_ceil--;
		start_point++;
	}
	while (h_floor > 0)
	{
		my_mlx_pixel_put(&img, i, start_point, all.value->f_color);
		h_floor--;
		start_point++;
	}
}

void	draw_wall(t_all all, t_img img, int i, t_ray ray)
{
	float	h_float;
	int		h;
	int		start_point;
	int		point;

	h_float = roundf((SIZE / ray.s) * all.plane->dist_pp);
	h = (int)h_float;
	start_point = all.value->scr_h / 2 - h / 2;
	if (start_point < 0)
		point = 0;
	else
		point = start_point;
	while (h > 0 && point < all.value->scr_h)
	{
		ray.color = get_color(ray, img,
				(int)((point - start_point) / (h_float / SIZE)));
		if (ray.color != 0xFF000000)
			my_mlx_pixel_put(&img, i, point, ray.color);
		point++;
		h--;
	}
}

void	draw_sprite(t_all all, t_img img, int i, t_sprite *sprite)
{
	int				h;
	float			h_float;
	int				start_point;
	unsigned int	color;
	int				point;

	start_point = 0;
	color = 0;
	h_float = roundf((SIZE / sprite->s) * all.plane->dist_pp);
	h = (int)h_float;
	start_point = all.value->scr_h / 2 - h / 2;
	if (start_point < 0)
		point = 0;
	else
		point = start_point;
	while (h > 0 && point < all.value->scr_h)
	{
		color = my_mlx_pixel_get(&img.sprite, (int)(sprite->c + SIZE / 2),
				(int)((point - start_point) / (h_float / SIZE)));
		if (color != 0xFF000000 && fabs(sprite->c) <= SIZE / 2)
			my_mlx_pixel_put(&img, i, point, color);
		point++;
		h--;
	}
}

void	draw_frame(t_all *all)
{
	t_ray	ray;
	float	middle_angle;

	all->plane->x = all->player->x * SIZE + 0.5 * SIZE;
	all->plane->y = all->player->y * SIZE + 0.5 * SIZE;
	initial_struct_ray(&ray, *all);
	middle_angle = ray.angle + all->plane->angle_ray
		* (all->value->scr_w * 0.5 + 1);
	raycasting(*all, *all->img, ray, middle_angle);
}
