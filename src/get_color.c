#include "cub.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_tex *tex, int x, int y)
{
	char	*dst;
	int		color;

	color = 0;
	dst = tex->addr + (y * tex->length + x * (tex->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static int	choose_color_hor(t_ray ray, t_img img, int i)
{
	if (ray.angle > 0 && ray.angle <= M_PI_2)
		ray.color = my_mlx_pixel_get(&img.tex_n,
				SIZE - (int)(ray.x) % SIZE - 1, i);
	if (ray.angle > M_PI_2 && ray.angle <= M_PI)
		ray.color = my_mlx_pixel_get(&img.tex_n,
				SIZE - (int)(ray.x) % SIZE - 1, i);
	if (ray.angle > M_PI && ray.angle <= 3 * M_PI_2)
		ray.color = my_mlx_pixel_get(&img.tex_s, (int)(ray.x) % SIZE, i);
	if (ray.angle > 3 * M_PI_2 && ray.angle <= 2 * M_PI)
		ray.color = my_mlx_pixel_get(&img.tex_s, (int)(ray.x) % SIZE, i);
	return (ray.color);
}

static int	choose_color_vert(t_ray ray, t_img img, int i)
{
	if (ray.angle > 0 && ray.angle <= M_PI_2)
		ray.color = my_mlx_pixel_get(&img.tex_w, (int)(ray.y) % SIZE, i);
	if (ray.angle > M_PI_2 && ray.angle <= M_PI)
		ray.color = my_mlx_pixel_get(&img.tex_e,
				SIZE - (int)(ray.y) % SIZE - 1, i);
	if (ray.angle > M_PI && ray.angle <= 3 * M_PI_2)
		ray.color = my_mlx_pixel_get(&img.tex_e,
				SIZE - (int)(ray.y) % SIZE - 1, i);
	if (ray.angle > 3 * M_PI_2 && ray.angle <= 2 * M_PI)
		ray.color = my_mlx_pixel_get(&img.tex_w, (int)(ray.y) % SIZE, i);
	return (ray.color);
}

int	get_color(t_ray ray, t_img img, int i)
{
	ray.color = 0;
	if (ray.s_hor < ray.s_vert)
		ray.color = choose_color_hor(ray, img, i);
	if (ray.s_vert < ray.s_hor)
		ray.color = choose_color_vert(ray, img, i);
	return (ray.color);
}
