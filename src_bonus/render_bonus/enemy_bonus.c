#include "cub3d_bonus.h"

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
	int i = 0;
	while (i < game->enemy_count)
	{
		double inv_det = 1.0 / (game->plane_x * game->player.dir_y - game->plane_y * game->player.dir_x);
		double transform_x = inv_det * (game->player.dir_y * (game->player.x - game->enemy[i].x) - game->player.dir_x * (game->player.y - game->enemy[i].y));
		double transform_y = inv_det * (-game->plane_y * (game->player.x - game->enemy[i].x) + game->plane_x * (game->player.y - game->enemy[i].y));
		int vMoveScreen = (int)(-200 / transform_y);
		int screen_x = (int)((SCREEN_WIDTH / 2) * (1 + transform_x / transform_y));
		double sprite_height = fabs((SCREEN_HEIGHT / transform_y));
		double sprite_width = sprite_height;
		sprite_height /=1.5;
		sprite_width /=1.5;
		int start_x =  (int)-sprite_width / 2 + screen_x;
		if (start_x < 0)
			start_x = 0;
		int end_x = (int)sprite_width / 2 + screen_x;
		if (end_x >= SCREEN_WIDTH)
			end_x = SCREEN_WIDTH - 1;
		int start_y =  -(int)sprite_height / 2 + SCREEN_HEIGHT / 2 + vMoveScreen;
		if (start_y < 0)
			start_y = 0;
		int end_y = SCREEN_HEIGHT / 2 + (int)sprite_height / 2 + vMoveScreen;
		if (end_y >= SCREEN_HEIGHT)
			end_y = SCREEN_HEIGHT - 1;
		for (int x = start_x; x < end_x; x++)
		{
			int tex_x = (int)(256 * (x - (-(int)sprite_width / 2 + screen_x)) * 64 / (int)sprite_width) / 256;
			if(-transform_y > 0 && x > 0 && x < SCREEN_WIDTH && -transform_y < game->z_buffer[x])
			{
				for (int y = start_y; y < end_y; y++)
				{
					int d = (y - vMoveScreen) * 256 - SCREEN_HEIGHT * 128 + (int)sprite_height * 128; //256 and 128 factors to avoid floats
					int tex_y = ((d * game->enemy[i].frame_height) / (int)sprite_height) / 256;
					unsigned int color = get_color(game, game->enemy[i].curr_frame * game->enemy[i].frame_width + tex_x, tex_y, ENEM);
					if (((color & 0xFF000000) != 0xFF000000))
						put_pixel(game, x, y, color); 
				}
				game->enemy_near = true;
			}
			else
				game->enemy_near = false;
		}
		i++;
	}
}
