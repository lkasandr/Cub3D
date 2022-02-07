#include "cub.h"

static void	check_color(int r, int g, int b)
{
	if (r < 0 || r > 255)
		ft_error("wrong color format!");
	if (g < 0 || g > 255)
		ft_error("wrong color format!");
	if (b < 0 || b > 255)
		ft_error("wrong color format!");
}

static int	get_r(char *line)
{
	int		color;
	int		i;

	color = 0;
	i = 0;
	while (ft_isdigit(line[i]) && line[i] != ',' && line[i])
	{
		color = color * 10 + (line[i] - '0');
		i++;
	}
	return (color);
}

static int	skip_i_rgb(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]) && line[i] != ',' && line[i])
		i++;
	while ((line[i] == ',' || line[i] == ' ') && line[i])
		i++;
	return (i);
}

int	get_rgb(char *line)
{
	int		i;
	int		r;
	int		g;
	int		b;
	int		rgb;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	rgb = 0;
	while (line[i] == ' ')
		i++;
	r = get_r(line + i);
	i = i + skip_i_rgb(line + i);
	g = get_r(line + i);
	i = i + skip_i_rgb(line + i);
	b = get_r(line + i);
	i = i + skip_i_rgb(line + i);
	if (line[i])
		ft_error("Wrong number of arguments!");
	check_color(r, g, b);
	rgb = 0xFFFFFF & (r << 16 | g << 8 | b);
	return (rgb);
}
