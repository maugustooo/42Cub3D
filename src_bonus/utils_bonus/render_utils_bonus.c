#include "cub3d_bonus.h"

int	get_color(t_game *game, int x, int y, int i)
{
	return (*(int *)(game->img[i].addr
		+ (y * game->img[i].line_len + x * (game->img[i].bpp / 8))));
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > game->screen_height - 1 || x < 0
		|| x > game->screen_width - 1)
		return ;
	pixel = (game->img[4].addr + (y * game->img[4].line_len
				+ x * (game->img[4].bpp / 8)));
	*(int *)pixel = color;
}
