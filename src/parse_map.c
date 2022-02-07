#include "cub.h"

static char	*join_line(char *map, char *line)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 0;
	array = malloc(sizeof(char *) * (ft_strlen(map) + ft_strlen(line) + 2));
	if (!array)
		return (NULL);
	if (map)
	{
		while (map[i])
			array[j++] = map[i++];
	}
	i = 0;
	while (line[i])
		array[j++] = line[i++];
	array[j] = 'B';
	array[j + 1] = '\0';
	free(map);
	return (array);
}

void	parse_map(char *line, t_val *value)
{
	if (*line == '\0')
	{
		value->array = join_line(value->array, " ");
		return ;
	}
	value->array = join_line(value->array, line);
}
