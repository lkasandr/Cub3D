#include "cub.h"

static void	turn_left(t_all *all)
{
	all->player->dir = all->player->dir + ROT;
}

static void	turn_right(t_all *all)
{
	all->player->dir = all->player->dir - ROT;
}

void	move_player(t_all *all)
{
	if (all->key.a == 1)
		move_left(all);
	if (all->key.d == 1)
		move_right(all);
	if (all->key.w == 1)
		move_forward(all);
	if (all->key.s == 1)
		move_back(all);
	if (all->key.turn_left == 1)
		turn_left(all);
	if (all->key.turn_right == 1)
		turn_right(all);
}
