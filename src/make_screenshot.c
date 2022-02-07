#include "cub.h"

static int	pixel_get(t_img *tex, int x, int y)
{
	char	*dst;
	int		color;

	color = 0;
	dst = tex->addr + (y * tex->length + x * (tex->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static void	fill_temp(int i, unsigned char *temp)
{
	temp[0] = (unsigned char)(i);
	temp[1] = (unsigned char)(i >> 8);
	temp[2] = (unsigned char)(i >> 16);
	temp[3] = (unsigned char)(i >> 24);
}

static void	ft_put_color(t_all all, t_img *img, int fd)
{
	int		x;
	int		y;
	int		color;

	y = all.value->scr_h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all.value->scr_w)
		{
			color = pixel_get(img, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
	}
}

void	make_screenshot(t_all all, t_img img)
{
	int				size;
	int				fd;
	unsigned char	temp[54];
	int				i;

	i = 0;
	size = (all.value->scr_h * all.value->scr_w * 4) + 54;
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
	if (fd == -1)
		ft_error("can't create screenshot!\n");
	while (i++ < 54)
		temp[i] = 0;
	temp[0] = 'B';
	temp[1] = 'M';
	fill_temp(size, &temp[2]);
	temp[10] = (unsigned char)(54);
	temp[14] = (unsigned char)(40);
	fill_temp(all.value->scr_w, &temp[18]);
	fill_temp(all.value->scr_h, &temp[22]);
	temp[26] = (unsigned char)(1);
	temp[28] = (unsigned char)(24);
	write(fd, temp, 54);
	ft_put_color(all, &img, fd);
	close(fd);
	exit(0);
}
