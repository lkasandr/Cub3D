#include "cub.h"

static void	check_line_resolution(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!(ft_isdigit(line[i])))
		ft_error("Bad resolution!");
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		ft_error("Bad resolution!");
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		ft_error("Bad resolution!");
	while (ft_isdigit(line[i]))
		i++;
	if ((line[i] != ' ' && line[i] != '\t') && line[i] != '\0')
		ft_error("Bad resolution!");
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line[i] != '\0')
		ft_error("Bad resolution!");
}

static int	ft_atoi_cub(char *str, int max_value)
{
	int		i;
	size_t	f;

	i = 0;
	f = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		ft_error("Bad resolution!");
	while (str[i] && ft_isdigit(str[i]))
	{
		f = f * 10 + (str[i] - '0');
		i++;
	}
	if (f > (size_t)max_value)
		f = (size_t)max_value;
	if (f < 100)
		f = 100;
	return (f);
}

void	parse_resolution(char *line, t_val *value, t_img img)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	mlx_get_screen_size(img.mlx, &width, &height);
	line = line + 2;
	while (*line == ' ')
		line++;
	check_line_resolution(line);
	value->scr_w = ft_atoi_cub(line, width);
	if (!value->scr_w || value->scr_w <= 0)
		ft_error("Bad resolution!");
	while (ft_isdigit(*line))
		line++;
	value->scr_h = ft_atoi_cub(line, height);
	if (!value->scr_h || value->scr_h <= 0)
		ft_error("Bad resolution!");
}
