#include "cub.h"

void	get_hor_coord_wall(t_all all, t_ray *ray, float x_a, float y_a)
{
	while ((ray->x_hor >= 0) && (ray->x_hor < (all.value->map_j * SIZE))
		&& (ray->y_hor >= 0) && (ray->y_hor < (all.value->map_i * SIZE)))
	{
		ray->x_grid = ray->x_hor / SIZE;
		ray->y_grid = ray->y_hor / SIZE;
		if ((ray->angle > M_PI) && (ray->angle < 2 * M_PI))
			ray->y_grid = ray->y_grid - 1;
		if ((ray->y_grid < all.value->map_i && ray->x_grid < all.value->map_j
				&& (ray->y_grid >= 0) && (ray->x_grid >= 0))
			&& (all.value->map[ray->y_grid][ray->x_grid] != '1')
			&& (all.value->map[ray->y_grid][ray->x_grid] != ' '))
		{
			if (all.value->map[ray->y_grid][ray->x_grid] == '2')
				proc_sprite(all, ray);
			ray->x_hor = ray->x_hor + x_a;
			ray->y_hor = ray->y_hor + y_a;
			ray->x_grid = ray->x_hor / SIZE;
			ray->y_grid = ray->y_hor / SIZE;
		}
		else
			break ;
	}
}

void	get_horisont_distance(t_all all, t_ray *ray)
{
	ray->sprite_s = sqrt(powf((ray->sprite_x - all.plane->x), 2)
			+ powf((ray->sprite_y - all.plane->y), 2));
	ray->sprite_c = ((ray->y_hor - all.plane->y) * ray->sprite_x
			- (ray->x_hor - all.plane->x) * ray->sprite_y
			+ ray->x_hor * all.plane->y - ray->y_hor * all.plane->x)
		/ sqrt(powf((ray->y_hor - all.plane->y), 2)
			+ powf((ray->x_hor - all.plane->x), 2));
	ray->s_hor = sqrt(powf((ray->x_hor - all.plane->x), 2)
			+ powf((ray->y_hor - all.plane->y), 2));
}

void	get_vert_coord_wall(t_all all, t_ray *ray, float x_a, float y_a)
{
	while ((ray->x_vert >= 0) && (ray->x_vert < (all.value->map_j * SIZE))
		&& (ray->y_vert >= 0) && (ray->y_vert < (all.value->map_i * SIZE)))
	{
		ray->x_grid = ray->x_vert / SIZE;
		ray->y_grid = ray->y_vert / SIZE;
		if ((ray->angle > M_PI_2) && (ray->angle < 3 * M_PI_2))
			ray->x_grid = ray->x_grid - 1;
		if ((ray->y_grid < all.value->map_i && ray->x_grid < all.value->map_j
				&& (ray->y_grid >= 0) && (ray->x_grid >= 0))
			&& (all.value->map[ray->y_grid][ray->x_grid] != '1')
			&& (all.value->map[ray->y_grid][ray->x_grid] != ' '))
		{
			if (all.value->map[ray->y_grid][ray->x_grid] == '2')
				proc_sprite(all, ray);
			ray->x_vert = ray->x_vert + x_a;
			ray->y_vert = ray->y_vert + y_a;
			ray->x_grid = ray->x_vert / SIZE;
			ray->y_grid = ray->y_vert / SIZE;
		}
		else
			break ;
	}
}

void	get_vertical_distance(t_all all, t_ray *ray)
{
	ray->sprite_s = sqrt(powf((ray->sprite_x - all.plane->x), 2)
			+ powf((ray->sprite_y - all.plane->y), 2));
	ray->sprite_c = ((ray->y_vert - all.plane->y) * ray->sprite_x
			- (ray->x_vert - all.plane->x) * ray->sprite_y
			+ ray->x_vert * all.plane->y - ray->y_vert * all.plane->x)
		/ sqrt(powf((ray->y_vert - all.plane->y), 2)
			+ powf((ray->x_vert - all.plane->x), 2));
	ray->s_vert = sqrt(powf((ray->x_vert - all.plane->x), 2)
			+ powf((ray->y_vert - all.plane->y), 2));
}
