#include "cub.h"

static int	skip_i_line_color(char *line)
{
	int		i;

	i = 0;
	if (!ft_isdigit(line[i]) && line[i] != ' ')
		ft_error("Wrong color format!");
	while (line[i] && line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		ft_error("Wrong color format!");
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	return (i);
}

static void	check_line_color(char *line)
{
	int		i;

	i = 0;
	i = i + skip_i_line_color(line + i);
	if (line[i] && (line[i] != ','))
		ft_error("Wrong color format!");
	else
		i++;
	i = i + skip_i_line_color(line + i);
	if (line[i] && (line[i] != ','))
		ft_error("Wrong color format!");
	else
		i++;
	i = i + skip_i_line_color(line + i);
	if (line[i])
		ft_error("Wrong color format!");
}

void	parse_color_floor(char *line, t_val *value)
{
	if (value->f_color != -1)
		ft_error("Double argument of floor's color!");
	line = line + 2;
	check_line_color(line);
	value->f_color = get_rgb(line);
}

void	parse_color_ceil(char *line, t_val *value)
{
	if (value->c_color != -1)
		ft_error("Double argument of ceil's color!");
	line = line + 2;
	check_line_color(line);
	value->c_color = get_rgb(line);
}
