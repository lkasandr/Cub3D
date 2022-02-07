#include "cub.h"

void	move_left(t_all *all)
{
	float	new_x;
	float	new_y;
	float	s;
	float	d;

	new_x = all->player->x + cos(all->player->dir - M_PI_2) * SPEED * 0.7;
	new_y = all->player->y + sin(all->player->dir - M_PI_2) * SPEED * 0.7;
	s = new_x + NEAR;
	d = new_x - NEAR;
	if (all->value->map[(int)roundf(all->player->y)][(int)roundf(s)] != '1' &&
		all->value->map[(int)roundf(all->player->y)][(int)roundf(d)] != '1')
		all->player->x = new_x;
	s = new_y + NEAR;
	d = new_y - NEAR;
	if (all->value->map[(int)roundf(s)][(int)roundf(all->player->x)] != '1' &&
		all->value->map[(int)roundf(d)][(int)roundf(all->player->x)] != '1')
		all->player->y = new_y;
}

void	move_right(t_all *all)
{
	float	new_x;
	float	new_y;
	float	s;
	float	d;

	new_x = all->player->x + cos(all->player->dir + M_PI_2) * SPEED * 0.7;
	new_y = all->player->y + sin(all->player->dir + M_PI_2) * SPEED * 0.7;
	s = new_x + NEAR;
	d = new_x - NEAR;
	if (all->value->map[(int)roundf(all->player->y)][(int)roundf(s)] != '1' &&
		all->value->map[(int)roundf(all->player->y)][(int)roundf(d)] != '1')
		all->player->x = new_x;
	s = new_y + NEAR;
	d = new_y - NEAR;
	if (all->value->map[(int)roundf(s)][(int)roundf(all->player->x)] != '1' &&
		all->value->map[(int)roundf(d)][(int)roundf(all->player->x)] != '1')
		all->player->y = new_y;
}

void	move_forward(t_all *all)
{
	float	new_x;
	float	new_y;
	float	s;
	float	d;

	new_x = all->player->x + cos(all->player->dir) * SPEED;
	new_y = all->player->y + sin(all->player->dir) * SPEED;
	s = new_x + NEAR;
	d = new_x - NEAR;
	if (all->value->map[(int)roundf(all->player->y)][(int)roundf(s)] != '1' &&
		all->value->map[(int)roundf(all->player->y)][(int)roundf(d)] != '1')
		all->player->x = new_x;
	s = new_y + NEAR;
	d = new_y - NEAR;
	if (all->value->map[(int)roundf(s)][(int)roundf(all->player->x)] != '1' &&
		all->value->map[(int)roundf(d)][(int)roundf(all->player->x)] != '1')
		all->player->y = new_y;
}

void	move_back(t_all *all)
{
	float	new_x;
	float	new_y;
	float	s;
	float	d;

	new_x = all->player->x - cos(all->player->dir) * SPEED;
	new_y = all->player->y - sin(all->player->dir) * SPEED;
	s = new_x + NEAR;
	d = new_x - NEAR;
	if (all->value->map[(int)roundf(all->player->y)][(int)roundf(s)] != '1' &&
		all->value->map[(int)roundf(all->player->y)][(int)roundf(d)] != '1')
		all->player->x = new_x;
	s = new_y + NEAR;
	d = new_y - NEAR;
	if (all->value->map[(int)roundf(s)][(int)roundf(all->player->x)] != '1' &&
		all->value->map[(int)roundf(d)][(int)roundf(all->player->x)] != '1')
		all->player->y = new_y;
}
