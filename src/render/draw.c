# include "cub3d.h"

void	draw(t_game *game, int x, int texture)
{
	int	color;

	// printf("game->tex_x: %d\n", game->tex_x);
	// printf("game->tex_y: %d\n", game->tex_y);
	color = get_color(game, game->tex_x, game->tex_y, texture);
	put_pixel(game, x, game->wall_start, color);
}

void	define_texture(t_game *game, int start, int line_height)
{
	if (game->wall_side == 0)
		game->wall_x = game->player.y + game->perpwalldist * game->ray_dir_y;
	else
		game->wall_x = game->player.x + game->perpwalldist * game->ray_dir_x;
	game->wall_x -= floor(game->wall_x);
	game->tex_x = game->wall_x * 64;
	if (game->wall_side == 0 && game->ray_dir_x > 0)
		game->tex_x = 64 - game->tex_x - 1;
	if (game->wall_side == 1 && game->ray_dir_y < 0)
		game->tex_x = 64 - game->tex_x - 1;
	game->step = 1.0 * 64 / line_height;
	game->tex_pos = (start - game->screen_height / 2
			+ line_height / 2) * game->step;
}

int set_column_size(t_game *game, int line_height)
{
	line_height = game->screen_height / game->perpwalldist;
	game->wall_start = -line_height / 2 + game->screen_height / 2;
	if (game->wall_start < 0)
		game->wall_start = 0;
	game->wall_end = line_height / 2 + game->screen_height / 2;
	if (game->wall_end >= game->screen_height)
		game->wall_end = game->screen_height - 1;
	return (line_height);
}

void draw_column(t_game *game, int x)
{
	int	line_height;

	line_height = 0;
	line_height = set_column_size(game, line_height);
	define_texture(game, game->wall_start, line_height);
	while (game->wall_start < game->wall_end)
	{
		game->tex_y = (int)game->tex_pos & (64 - 1);
		game->tex_pos += game->step;
		if (game->wall_side == 1 && game->ray_dir_y < 0)
			draw(game, x, SOUTH);
		else if (game->wall_side == 1 && game->ray_dir_y > 0)
			draw(game, x, NORTH);
		else if (game->wall_side == 0 && game->ray_dir_x < 0)
			draw(game, x, WEST);
		else if (game->wall_side == 0 && game->ray_dir_x > 0)
			draw(game, x, EAST);
		game->wall_start++;
	}
}