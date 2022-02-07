#include "cub.h"

static float	check_ray_start(float angle)
{
	if (angle < 0)
		angle = angle + 2 * M_PI;
	if (angle > (2 * M_PI))
		angle = angle - (int)(angle / 2 / M_PI)*2 *M_PI;
	return (angle);
}

static void	calc_struct_ray_horisontal(t_all all, t_ray *ray)
{
	float	y_a;
	float	x_a;

	y_a = 0;
	x_a = 0;
	if ((ray->angle > 0) && (ray->angle < M_PI))
	{
		ray->y_hor = (int)(all.plane->y / SIZE)*SIZE + SIZE;
		y_a = SIZE;
	}
	else
	{
		ray->y_hor = (int)(all.plane->y / SIZE)*SIZE;
		y_a = -SIZE;
	}
	ray->x_hor = all.plane->x + ((ray->y_hor - all.plane->y) / tan(ray->angle));
	x_a = SIZE / tan(ray->angle);
	if ((ray->angle > M_PI) && (ray->angle < 2 * M_PI))
		x_a = -x_a;
	get_hor_coord_wall(all, ray, x_a, y_a);
	get_horisont_distance(all, ray);
}

static void	calc_struct_ray_vertical(t_all all, t_ray *ray)
{
	float	y_a;
	float	x_a;

	y_a = 0;
	x_a = 0;
	if ((ray->angle > M_PI_2) && (ray->angle < 3 * M_PI_2))
	{
		ray->x_vert = (int)(all.plane->x / SIZE)*SIZE;
		x_a = -SIZE;
	}
	else
	{
		ray->x_vert = (int)(all.plane->x / SIZE)*SIZE + SIZE;
		x_a = SIZE;
	}
	ray->y_vert = all.plane->y + (ray->x_vert - all.plane->x) * tan(ray->angle);
	y_a = SIZE * tan(ray->angle);
	if ((ray->angle > M_PI_2) && (ray->angle < 3 * M_PI_2))
		y_a = -y_a;
	get_vert_coord_wall(all, ray, x_a, y_a);
	get_vertical_distance(all, ray);
}

static void	distance_selection(t_ray *ray, float middle_angle)
{
	if (ray->s_hor < ray->s_vert)
	{
		ray->s = ray->s_hor * cos(ray->angle - middle_angle);
		ray->x = ray->x_hor;
		ray->y = ray->y_hor;
	}
	if (ray->s_vert < ray->s_hor)
	{
		ray->s = ray->s_vert * cos(ray->angle - middle_angle);
		ray->x = ray->x_vert;
		ray->y = ray->y_vert;
	}
}

void	raycasting(t_all all, t_img img, t_ray ray, float middle_angle)
{
	int			i;
	t_sprite	*sprite;

	i = 0;
	while (i < all.value->scr_w)
	{
		ray.sprite = NULL;
		ray.angle = check_ray_start(ray.angle);
		calc_struct_ray_horisontal(all, &ray);
		calc_struct_ray_vertical(all, &ray);
		distance_selection(&ray, middle_angle);
		draw_ceil_floor(all, img, i);
		draw_wall(all, img, i, ray);
		sprite = ray.sprite;
		while (sprite)
		{
			if (sprite->s < ray.s)
				draw_sprite(all, img, i, sprite);
			sprite = sprite->next;
		}
		ray.angle = ray.angle + all.plane->angle_ray;
		free_sprites(ray.sprite);
		i++;
	}
}
