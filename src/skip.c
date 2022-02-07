#include "cub.h"

void	skip_empty_line(void)
{
	int		x;

	x = 1;
}

void	check_texture(char *line)
{
	int		fd;

	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Wrong path to texture!");
	}
}

char	*skip_space(char *line, t_val *value)
{
	int		i;

	i = 0;
	if (check_value(*value) != 0)
		return (line);
	while (line[i] == ' ')
		i++;
	return (line + i);
}
