#include "cub.h"

static void	initial_struct_val(t_val *value)
{
	value->scr_h = 0;
	value->scr_w = 0;
	value->north = NULL;
	value->south = NULL;
	value->west = NULL;
	value->east = NULL;
	value->sprite = NULL;
	value->f_color = -1;
	value->c_color = -1;
	value->map = NULL;
	value->array = NULL;
	value->map_i = 0;
	value->map_j = 0;
}

static void	parse_line(char *line, t_val *value, t_img img)
{
	line = skip_space(line, value);
	if (!(ft_strncmp(line, "R ", 2)))
		return (parse_resolution(line, value, img));
	else if (!(ft_strncmp(line, "NO ", 3)))
		return (parse_north_texture(line, value));
	else if (!(ft_strncmp(line, "SO ", 3)))
		return (parse_south_texture(line, value));
	else if (!(ft_strncmp(line, "WE ", 3)))
		return (parse_west_texture(line, value));
	else if (!(ft_strncmp(line, "EA ", 3)))
		return (parse_east_texture(line, value));
	else if (!(ft_strncmp(line, "S ", 2)))
		return (parse_sprite_texture(line, value));
	else if (!(ft_strncmp(line, "F ", 2)))
		return (parse_color_floor(line, value));
	else if (!(ft_strncmp(line, "C ", 2)))
		return (parse_color_ceil(line, value));
	else if (check_value(*value) != 0)
		return (parse_map(line, value));
	else
	{
		if (*line == '\0')
			return (skip_empty_line());
		ft_error("Wrong number of identifier!");
	}
}

static void	check_map(char **map, t_val *value)
{
	int		i;

	i = 0;
	while (map[i])
	{
		check_symbols(map[i], value);
		i++;
	}
	if (number_of_player(map) != 1)
	{
		free(value->map);
		ft_error("Too many players!\n");
	}
	check_first_last_line(map, value);
	check_space_in_map(map, value);
	check_map_empty_line(map, value);
	check_behind_map(map, value);
}

static void	get_map_size(t_val *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (value->map[value->map_i])
	{
		j = 0;
		while (value->map[value->map_i][j])
			j++;
		if (j > value->map_j)
			value->map_j = j;
		value->map_i++;
	}
}

void	parse_file(t_val *value, t_img img, int fd)
{
	char	*line;

	line = NULL;
	initial_struct_val(value);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line)
		{
			parse_line(line, value, img);
			free(line);
		}
	}
	if (line)
	{
		parse_line(line, value, img);
		free(line);
	}
	value->map = ft_split(value->array, 'B');
	free(value->array);
	check_map(value->map, value);
	get_map_size(value);
}
