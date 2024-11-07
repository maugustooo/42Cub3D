#include "cub3d.h"

int	get_color(t_game *game, int x, int y, int i)
{
	return (*(int *)(game->img[i].addr
		+ (y * game->img[i].line_len + x * (game->img[i].bpp / 8))));
}

void put_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > game->heightmap - 1 || x < 0
		|| x > game->widthmap - 1)
		return ;
	pixel = (game->img[2].addr + (y * game->img[2].line_len
				+ x * (game->img[2].bpp / 8)));
	*(int *)pixel = color;
}
