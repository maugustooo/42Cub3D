#include "cub3d.h"

void	put_pixel_minimap(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= game->screen_width || y < 0 || y >= game->screen_height)
		return ;
	pixel = (game->minimap.addr + (y * game->minimap.line_len
				+ x * (game->minimap.bpp / 8)));
	*(int *)pixel = color;
}

void	draw_minimap_square(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			put_pixel_minimap(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void draw_player_square(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			put_pixel_minimap(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	render_player_on_minimap(t_game *game)
{
	int player_x;
	int player_y;
	int color;

	player_x = (int)game->player.x * 10;
	player_y = (int)game->player.y * 10;
	color = 0xFF0000;
	draw_minimap_square(game, player_x, player_y, color);
}

void	render_minimap(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (x < game->widthmap)
	{
		y = 0;
		while (y < game->heightmap)
		{
			if (game->map[y][x] == '1')
				draw_minimap_square(game, x * 10, y * 10, 0xFFFFFF);
			else if (game->map[y][x] != '1')
				draw_minimap_square(game, x * 10, y * 10, 0x000000);
			y++;
		}
		x++;
	}
	render_player_on_minimap(game);
}
