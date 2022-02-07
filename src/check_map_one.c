#include "cub.h"

int	check_value(t_val value)
{
	if (value.north && value.south && value.east && value.west)
	{
		if (value.scr_h && value.scr_w)
		{
			if (value.sprite)
			{
				if (value.f_color != -1)
				{
					if (value.c_color != -1)
						return (1);
					return (0);
				}
				return (0);
			}
			return (0);
		}
		return (0);
	}
	else
		return (0);
}

void	check_symbols(char *line, t_val *value)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!(ft_strchr("012SWEN ", line[i])) || ft_strchr("\t", line[i]))
		{
			free(value->map);
			ft_error("invalid symbol in map!");
		}
		i++;
	}
}

int	number_of_player(char **map)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("SWEN", map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	check_countour_map(char **map, t_val *value, int i, int j)
{
	if (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
		{
			free(value->map);
			ft_error("Invalid map!");
		}
	}
}

void	check_first_last_line(char **map, t_val *value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][0] == '0')
		{
			free(value->map);
			ft_error("Bad map\n");
		}
		i++;
	}
	while (map[0][j] && map[0][j] == ' ')
		j++;
	while (map[0][++j])
		check_countour_map(map, value, 0, j);
	j = 0;
	i = i - 1;
	while (map[i][j] && map[i][j] == ' ')
		j++;
	while (map[i][++j])
		check_countour_map(map, value, i, j);
}
