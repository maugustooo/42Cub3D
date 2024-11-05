#include "cub3d.h"

void put_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > game->heightmap - 1 || x < 0
		|| x > game->widthmap - 1)
		return ;
	pixel = (game->img[1].addr + (y * game->img[1].line_len
				+ x * (game->img[1].bpp / 8)));
	*(int *)pixel = color;
}
int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void set_colors(t_game *game)
{
    game->rgb_sky[0] = 135;
    game->rgb_sky[1] = 206;
    game->rgb_sky[2] = 235;

    game->rgb_floor[0] = 34;
    game->rgb_floor[1] = 139;
    game->rgb_floor[2] = 34;
}

void render_background(t_game *game)
{
    int x;
    int y;

    set_colors(game);
    x = 0;
    while (x < game->widthmap)
    {
        y = 0;
        while (y < game->heightmap)
        {
            if (y < game->heightmap / 2)
                put_pixel(game, x, y, create_rgb(0, game->rgb_sky[0],
                        game->rgb_sky[1], game->rgb_sky[2]));
            else
                put_pixel(game, x, y, create_rgb(0, game->rgb_floor[0],
                        game->rgb_floor[1], game->rgb_floor[2]));
            y++;
        }
        x++;
    }
}

void render(t_game *game)
{
	render_background(game);
}
