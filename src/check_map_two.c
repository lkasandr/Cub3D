#include "cub.h"

void	check_space_in_map(char **map, t_val *value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("02SNWE", map[i][j]))
			{
				if (map[i - 1][j] && map[i][j - 1] &&map[i + 1] && map[i][j + 1]
					&& (map[i - 1][j] == ' ' || map[i][j - 1] == ' '
					|| map[i + 1][j] == ' ' || map[i][j + 1] == ' '))
				{
					free(value->map);
					ft_error("Bad space in map!");
				}
			}
			j++;
		}
		i++;
	}
}

void	check_map_empty_line(char **map, t_val *value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = ft_strlen(map[i]);
	while (map[i] && (*map[i] == ' ') && (j == 1))
	{
		j = ft_strlen(map[i]);
		i++;
	}
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if ((*map[i] == ' ') && (j == 1))
		{
			if (map[i + 1] && *map[i + 1] != ' ')
			{
				free(value->map);
				ft_error("Empty line in middle of map!\n");
			}
		}
		i++;
	}
}

void	check_behind_map(char **map, t_val *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] && map[i][j] != '1')
			ft_error("bad map!\n");
		i++;
	}
}
