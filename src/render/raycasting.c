#include "cub3d.h"

void init_raycasting(t_game *game, int x)
{
	game->map_x = (int)game->pos_x;
	game->map_y = (int)game->pos_y;
	game->cam_x = 2 * x / (double)game->widthmap - 1;
	game->ray_dir_x = game->player_angle + game->plane_x * game->cam_x;
	game->ray_dir_y = game->player_angle + game->plane_y * game->cam_x;
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->widthmap)
	{
		init_raycasting(game, x);
		get_delta_dist(game);
		get_step(game);
		digital_differential_analyser(game);
		if (game->wall_side == 0)
			game->perpwalldist = (game->side_dist_x - game->delta_dist_x);
		else
			game->perpwalldist = (game->side_dist_y - game->delta_dist_y);
		draw_column(game, x);
		x++;
	}
}