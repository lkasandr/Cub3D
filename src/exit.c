#include "cub.h"

int	exit_game(t_all *all)
{
	free(all->value->map);
	exit(EXIT_SUCCESS);
	return (1);
}

void	*ft_error(char *str)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
