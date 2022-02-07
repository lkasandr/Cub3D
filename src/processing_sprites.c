#include "cub.h"

void	free_sprites(t_sprite *sprite)
{
	t_sprite	*list;

	list = sprite;
	while (list)
	{
		sprite = list;
		list = sprite->next;
		free(sprite);
	}
}

static t_sprite	*push_sprite(t_ray *ray)
{
	t_sprite	*prev;
	t_sprite	*temp;
	t_sprite	*next;

	next = ray->sprite;
	prev = NULL;
	while ((next != NULL) && (next->s > ray->sprite_s))
	{
		prev = next;
		next = next->next;
	}
	temp = (t_sprite *)malloc(sizeof(t_sprite));
	if (!temp)
		ft_error("Problem with memory!\n");
	temp->c = ray->sprite_c;
	temp->s = ray->sprite_s;
	temp->next = next;
	if (prev == NULL)
	{
		ray->sprite = temp;
	}
	else
		prev->next = temp;
	return (temp);
}

void	proc_sprite(t_all all, t_ray *ray)
{
	ray->sprite_y = ray->y_grid * SIZE + SIZE / 2;
	ray->sprite_x = ray->x_grid * SIZE + SIZE / 2;
	ray->sprite_s = sqrt(powf((ray->sprite_x - all.plane->x), 2)
			+ powf((ray->sprite_y - all.plane->y), 2));
	ray->sprite_c = ((ray->y_hor - all.plane->y) * ray->sprite_x
			- (ray->x_hor - all.plane->x) * ray->sprite_y
			+ ray->x_hor * all.plane->y - ray->y_hor * all.plane->x)
		/ sqrt(powf((ray->y_hor - all.plane->y), 2)
			+ powf((ray->x_hor - all.plane->x), 2));
	if (ray->sprite == NULL)
	{
		ray->sprite = (t_sprite *)malloc(sizeof(t_sprite));
		if (!ray->sprite)
		{
			free(all.value->map);
			ft_error("Problem with memory!\n");
		}
		ray->sprite->c = ray->sprite_c;
		ray->sprite->s = ray->sprite_s;
		ray->sprite->next = NULL;
	}
	else
		push_sprite(ray);
}
