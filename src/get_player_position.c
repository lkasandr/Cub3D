#include "cub.h"

static void	initial_struct_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dir = 0;
}

static void	get_player_dir(t_player *player, char *a)
{
	if (*a == 'N')
		player->dir = 3 * M_PI_2;
	if (*a == 'S')
		player->dir = M_PI_2;
	if (*a == 'W')
		player->dir = M_PI;
	if (*a == 'E')
		player->dir = 0;
}

void	player_position(t_player *player, char **map)
{
	int		i;
	int		j;
	char	*a;

	initial_struct_player(player);
	i = 0;
	a = NULL;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			a = ft_strchr("SWEN", map[i][j]);
			if (a)
			{
				player->x = j;
				player->y = i;
				get_player_dir(player, a);
			}
		}
	}
}
