# include "cub3d.h"

void	draw(t_game *game, int x, int texture)
{
	int	color;

	color = get_color(game, game->tex_x, game->tex_y, texture);
	put_pixel(game, x, game->mapstart, color);
}

void	define_texture(t_game *game, int start, int line_height)
{
	if (game->wall_side == 0)
		game->wall_x = game->player.y + game->perpwalldist * game->ray_dir_y;
	else
		game->wall_x = game->player.x + game->perpwalldist * game->ray_dir_x;
	game->wall_x -= floor(game->wall_x);
	game->tex_x = game->wall_x * 128;
	if (game->wall_side == 0 && game->ray_dir_x > 0)
		game->tex_x = 128 - game->tex_x - 1;
	if (game->wall_side == 1 && game->ray_dir_y < 0)
		game->tex_x = 128 - game->tex_x - 1;
	game->step = 1.0 * 128 / line_height;
	game->tex_pos = (start - game->heightmap / 2
			+ line_height / 2) * game->step;
}

int set_column_size(t_game *game, int line_height)
{
	line_height = game->heightmap / game->perpwalldist;
	game->mapstart = -line_height / 2 + game->heightmap / 2;
	if (game->mapstart < 0)
		game->mapstart = 0;
	game->mapend = line_height / 2 + game->heightmap / 2;
	if (game->mapend >= game->heightmap)
		game->mapend = game->heightmap - 1;
	return (line_height);
}

void draw_column(t_game *game, int x)
{
	int	line_height;

	line_height = 0;
	line_height = set_column_size(game, line_height);
	define_texture(game, game->mapstart, line_height);
	while (game->mapstart < game->mapend)
	{
		game->tex_y = (int)game->tex_pos & (128 - 1);
		game->tex_pos += game->step;
		if (game->wall_side == 1 && game->ray_dir_y < 0)
			draw(game, x, SOUTH);
		else if (game->wall_side == 1 && game->ray_dir_y > 0)
			draw(game, x, NORTH);
		else if (game->wall_side == 0 && game->ray_dir_x < 0)
			draw(game, x, WEST);
		else if (game->wall_side == 0 && game->ray_dir_x > 0)
			draw(game, x, EAST);
		game->mapstart++;
	}
}