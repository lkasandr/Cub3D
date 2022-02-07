#include "cub.h"

void	initial_plane_struct(t_plane *plane, t_val value, t_player player)
{
	plane->fov = 60 * M_PI / 180;
	plane->centr_x = value.scr_w / 2;
	plane->centr_y = value.scr_h / 2;
	plane->dist_pp = 0.5 * value.scr_w / tan(plane->fov / 2);
	plane->angle_ray = plane->fov / value.scr_w;
	plane->x = player.x * SIZE + 0.5 * SIZE;
	plane->y = player.y * SIZE + 0.5 * SIZE;
}

void	init_struct_key(t_all *all)
{
	all->key.a = 0;
	all->key.d = 0;
	all->key.s = 0;
	all->key.w = 0;
	all->key.turn_left = 0;
	all->key.turn_right = 0;
}

void	init_all(t_all *all, t_val *value, t_player *player, t_plane *plane)
{
	all->plane = plane;
	all->player = player;
	all->value = value;
	init_struct_key(all);
}

void	initial_struct_ray(t_ray *ray, t_all all)
{
	ray->x = all.player->x * SIZE + 0.5 * SIZE;
	ray->y = all.player->y * SIZE + 0.5 * SIZE;
	ray->x_grid = 0;
	ray->y_grid = 0;
	ray->angle = all.player->dir - 0.5 * all.plane->fov;
	ray->sprite_x = all.plane->x;
	ray->sprite_y = all.plane->y;
	ray->sprite = NULL;
}
