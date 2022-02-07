#include "cub.h"

void	parse_north_texture(char *line, t_val *value)
{
	if (value->north)
		ft_error("Double argument of north texture!");
	line = line + 3;
	while (*line == ' ' || *line == '\t')
		line++;
	check_texture(line);
	value->north = ft_strdup(line);
	if (!value->north)
		ft_error("Bad texture!");
}

void	parse_south_texture(char *line, t_val *value)
{
	if (value->south)
		ft_error("Double argument of south texture!");
	line = line + 3;
	while (*line == ' ' || *line == '\t')
		line++;
	check_texture(line);
	value->south = ft_strdup(line);
	if (!value->south)
		ft_error("Bad texture!");
}

void	parse_west_texture(char *line, t_val *value)
{
	if (value->west)
		ft_error("Double argument of west texture!");
	line = line + 3;
	while (*line == ' ' || *line == '\t')
		line++;
	check_texture(line);
	value->west = ft_strdup(line);
	if (!value->west)
		ft_error("Bad texture!");
}

void	parse_east_texture(char *line, t_val *value)
{
	if (value->east)
		ft_error("Double argument of east texture!");
	line = line + 3;
	while (*line == ' ' || *line == '\t')
		line++;
	check_texture(line);
	value->east = ft_strdup(line);
	if (!value->east)
		ft_error("Bad texture!");
}

void	parse_sprite_texture(char *line, t_val *value)
{
	if (value->sprite)
		ft_error("Double argument of sprite!");
	line = line + 2;
	while (*line == ' ' || *line == '\t')
		line++;
	check_texture(line);
	value->sprite = ft_strdup(line);
	if (!value->sprite)
		ft_error("Bad sprite file!");
}
