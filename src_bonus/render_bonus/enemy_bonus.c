#include "cub3d_bonus.h"

// void draw_enemy(t_game *game, int x)
// {
// 	if (game->is_enemy == false)
// 		return;
// 	int sprite_height = SCREEN_HEIGHT / game->walldist;
// 	sprite_height /= 2;
// 	int start_y = (SCREEN_HEIGHT / 2);
// 	if (start_y < 0)
// 		start_y = 0;
// 	printf("sprite_height: %d\n", sprite_height);
// 	int end_y = ((SCREEN_HEIGHT / 2) + sprite_height);
// 	if (end_y >= SCREEN_HEIGHT)
// 		end_y = SCREEN_HEIGHT - 1;
// 	printf("start_y: %d end_y: %d\n", start_y, end_y);
// 	// int start_x = -sprite_height / 2 + SCREEN_HEIGHT / game->walldist;
// 	// if (start_x < 0)
// 	// 	start_x = 0;
// 	// int end_x = sprite_height / 2 + SCREEN_HEIGHT / game->walldist;
// 	// if (end_x >= SCREEN_WIDTH)
// 	// 	end_x = SCREEN_WIDTH - 1;
// 	double sprite_x = game->player.x + game->walldist * game->enemy.ray_dir_x;
// 	sprite_x-= floor(sprite_x);
// 	printf("game->walldist: %f\n", game->walldist);
// 	int start_x = SCREEN_HEIGHT / 2;
// 	int end_x = SCREEN_HEIGHT / 2+ sprite_height;
// 	printf("start_x: %d end_x: %d\n", start_x, end_x);
// 	int tex_x = sprite_x * 64;
// 	// if((end_y - start_y) == (end_x - start_x))
// 		printf("end_y - start_y: %d end_x - start_x: %d\n", end_y - start_y, end_x - start_x);
// 	// printf("x: %d start_x: %d end_x: %d\n", x, start_x, end_x);
// 	for (int y = start_y; y < end_y; y++)
// 	{
// 		if(x > end_x || x < start_x)
// 			break;
// 		int tex_y = ((y - start_y) * 64) / sprite_height;
// 		if (tex_y < 0)
// 			tex_y = 0;
// 		if (tex_y >= 64)
// 			tex_y = sprite_height - 1;
// 		unsigned int color = get_color(game, tex_x, tex_y, ENEM);
// 		// if ((color & 0xFF000000) != 0xFF000000 && game->wall_side == 0)
// 			put_pixel(game, x, y, color);
// 	}
// }

// void	wall_stuff_enemy(t_game *game)
// {
// 	int	wall;

// 	wall = 0;
// 	while (wall == 0)
// 	{
// 		game->is_enemy = false;
// 		game->wall = false;
// 		game->door = false;
// 		if (game->enemy.side_dist_x < game->enemy.side_dist_y)
// 		{
// 			game->enemy.side_dist_x += game->enemy.delta_dist_x;
// 			game->enemy.map_x += game->enemy.step_x;
// 			game->enemy.wall_side = 0;
// 		}
// 		else
// 		{
// 			game->enemy.side_dist_y += game->enemy.delta_dist_y;
// 			game->enemy.map_y += game->enemy.step_y;
// 			game->enemy.wall_side = 1;
// 		}
// 		if (game->map[game->enemy.map_y][game->enemy.map_x] == '1')
// 		{
// 			game->wall = true;
// 			wall = 1;
// 		}
// 		if(game->map[game->map_y][game->map_x] == 'D')
// 		{
// 			game->door = true;
// 			wall = 1;
// 		}
// 		if(game->map[game->enemy.map_y][game->enemy.map_x] == 'X')
// 		{
// 			game->is_enemy = true;
// 			game->enemy.x = game->enemy.map_x + 0.5;
// 			game->enemy.y = game->enemy.map_y + 0.5;
// 			wall = 1;
// 		}
// 	}
// }

// void	get_step_enemy(t_game *game)
// {
// 	if (game->enemy.ray_dir_x < 0)
// 	{
// 		game->enemy.step_x = -1;
// 		game->enemy.side_dist_x = (game->player.x - game->enemy.map_x) * game->enemy.delta_dist_x;
// 	}
// 	else
// 	{
// 		game->enemy.step_x = 1;
// 		game->enemy.side_dist_x = (game->enemy.map_x + 1.0 - game->player.x)
// 			* game->enemy.delta_dist_x;
// 	}
// 	if (game->enemy.ray_dir_y < 0)
// 	{
// 		game->enemy.step_y = -1;
// 		game->enemy.side_dist_y = (game->player.y - game->enemy.map_y)
// 			* game->enemy.delta_dist_y;
// 	}
// 	else
// 	{
// 		game->enemy.step_y = 1;
// 		game->enemy.side_dist_y = (game->enemy.map_y + 1.0 - game->player.y)
// 			* game->enemy.delta_dist_y;
// 	}
// }

// void	get_distance_enemy(t_game *game)
// {
// 	if (game->enemy.ray_dir_x == 0)
// 		game->enemy.delta_dist_x = INT_MAX;
// 	else
// 		game->enemy.delta_dist_x = fabs(1 / game->enemy.ray_dir_x);
// 	if (game->enemy.ray_dir_y == 0)
// 		game->enemy.delta_dist_y = INT_MAX;
// 	else
// 		game->enemy.delta_dist_y = fabs(1 / game->enemy.ray_dir_y);
// }

// void	init_raycasting_enemy(t_game *game, int x)
// {
// 	game->enemy.map_x = (int)game->player.x;
// 	game->enemy.map_y = (int)game->player.y;
// 	game->enemy.cam_x = (2 * x) / (double)SCREEN_WIDTH - 1;
// 	game->enemy.ray_dir_x = game->player.dir_x + game->plane_x * game->enemy.cam_x;
// 	game->enemy.ray_dir_y = game->player.dir_y + game->plane_y * game->enemy.cam_x;
// }
// int handle_enemy(t_game *game)
// {
// 	int x;
	
// 	x = 0;
// 	while (x < SCREEN_WIDTH && game->is_enemy == false)
// 	{
// 		init_raycasting_enemy(game, x);
// 		get_distance_enemy(game);
// 		get_step_enemy(game);
// 		wall_stuff_enemy(game);
// 		if(game->is_enemy == true)
// 		{
// 			game->walldist = game->enemy.y - game->player.y + (1 - game->enemy.step_y) / 2;
// 			// draw_enemy(game, x);
// 		}
// 		x++;
// 	}
// 	while (x < SCREEN_WIDTH / game->walldist && game->is_enemy == true)
// 	{
// 		init_raycasting_enemy(game, x);
// 		// get_distance_enemy(game);
// 		// get_step_enemy(game);
// 		// wall_stuff_enemy(game);
// 		// if (game->wall_side == 0)
// 		// 	game->enemy.walldist = game->enemy.x - game->player.x + (1 - game->enemy.step_x) / 2;
// 		if(game->is_enemy == true)
// 			draw_enemy(game, x);
// 		x++;
// 	}
// 	return (0);
// }

void handle_enemy(t_game *game)
{
    // if (game->enemy.health <= 0)
    // {
    //  game->enemy.state = 0;
    //  game->map[(int)game->enemy.y][(int)game->enemy.x] = '0';
    // }
    // if (game->enemy.state == 0)
    // {
    //  game->enemy.x = game->enemy.x + 0.1;
    //  game->enemy.y = game->enemy.y + 0.1;
    //  game->enemy.health = 100;
    //  game->enemy.state = 1;
    // }
	printf("game->enemy.x: %f, game->enemy.y: %f\n", game->enemy.x, game->enemy.y);
	printf("game->ray_dir_x: %f, game->ray_dir_y: %f\n", game->ray_dir_x, game->ray_dir_y);
    double inv_det = 1.0 / (game->plane_x * game->ray_dir_y - game->plane_y * game->ray_dir_x);
	double transform_x = inv_det * (game->ray_dir_x * (game->enemy.y - game->player.x) - game->ray_dir_y * (game->enemy.x - game->player.y));
	double transform_y = inv_det * (-game->plane_y * (game->enemy.x - game->player.x) + game->plane_x * (game->enemy.y - game->player.y));
	printf("inv_det: %f, transform_x: %f, transform_y: %f\n", inv_det, transform_x, transform_y);
    int screen_x = (int)((SCREEN_WIDTH / 2) * (1 + transform_x / transform_y));
    int sprite_height = abs((int)(SCREEN_HEIGHT / transform_y));
    int sprite_width = sprite_height;
	printf("screen_x: %d, sprite_height: %d, sprite_width/2: %d\n", screen_x, sprite_height, sprite_width/2);
    int start_x = screen_x - sprite_width / 2;
    if (start_x < 0)
        start_x = 0;
    int end_x = screen_x + sprite_width / 2;
    if (end_x >= SCREEN_WIDTH)
        end_x = SCREEN_WIDTH - 1;
    int start_y = SCREEN_HEIGHT / 2 - sprite_height / 2;
    if (start_y < 0)
        start_y = 0;
    int end_y = SCREEN_HEIGHT / 2 + sprite_height / 2;
    if (end_y >= SCREEN_HEIGHT)
        end_y = SCREEN_HEIGHT - 1;
    printf("start_x: %d, end_x: %d, start_y: %d, end_y: %d\n", start_x, end_x, start_y, end_y);
    for (int x = start_x; x < end_x; x++)
    {
        int tex_x = ((x - start_x) * 64) / sprite_width;
        if (tex_x >= 64)
            tex_x = sprite_width - 1;
        for (int y = start_y; y < end_y; y++)
        {
            int tex_y = ((y - start_y) * 64) / sprite_height;
            if (tex_y < 0)
                tex_y = 0;
            if (tex_y >= 64)
                tex_y = sprite_height - 1;
            unsigned int color = get_color(game, tex_x, tex_y, ENEM);
            // Render the pixel if it's not transparent (e.g., 0xFF000000 is fully transparent)
            if ((color & 0xFF000000) != 0xFF000000)
                put_pixel(game, x, y, color);
        }
    }
}