#include "cub3d_bonus.h"

void	check_enemy1_5(t_game *game, int i)
{
	double	direction_x;
	double	direction_y;
	double	magnitude;
	double	new_x;
	double	new_y;

	direction_x = game->player.x - game->enemy[i].x;
	direction_y = game->player.y - game->enemy[i].y;
	magnitude = sqrt(direction_x * direction_x + direction_y * direction_y);
	if (magnitude != 0)
	{
		direction_x /= magnitude;
		direction_y /= magnitude;
	}
	new_x = game->enemy[i].x + direction_x * 0.04;
	new_y = game->enemy[i].y + direction_y * 0.04;
	if (is_path_clear(game, i))
	{
		game->enemy[i].x = new_x;
		game->enemy[i].y = new_y;
	}
	
}
void	check_enemy(t_game *game, int i)
{
	if(!game->enemy[i].died && !game->enemy[i].attacking)
	{
		if(is_path_clear(game, i))
		{
			check_enemy1_5(game, i);
			game->enemy[i].moving = true;
		}
		else
			game->enemy[i].moving = false;
	}
}

void	calculate_transform(t_game *game, int i)
{
	double inv_det;

	inv_det = 1.0 / (game->plane_x * game->player.dir_y - game->plane_y * game->player.dir_x);
	game->enemy[i].transform_x = inv_det * (game->player.dir_y * (game->player.x - game->enemy[i].x) - game->player.dir_x * (game->player.y - game->enemy[i].y));
	game->enemy[i].transform_y = inv_det * (-game->plane_y * (game->player.x - game->enemy[i].x) + game->plane_x * (game->player.y - game->enemy[i].y));
}

void handle_enemy(t_game *game)
{
	int i = 0;
	while (i < game->enemy_count)
	{
		check_enemy(game, i);
		calculate_transform(game, i);
		int vMoveScreen = (int)(-200 / game->enemy[i].transform_y);
		int screen_x = (int)((SCREEN_WIDTH / 2) * (1 + game->enemy[i].transform_x / game->enemy[i].transform_y));
		double sprite_height = fabs((SCREEN_HEIGHT / game->enemy[i].transform_y));
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
			if(-game->enemy[i].transform_y > 0 && x > 0 && x < SCREEN_WIDTH && -game->enemy[i].transform_y < game->z_buffer[x])
			{
				for (int y = start_y; y < end_y; y++)
				{
					int d = (y - vMoveScreen) * 256 - SCREEN_HEIGHT * 128 + (int)sprite_height * 128;
					int tex_y = ((d * game->enemy[i].frame_height) / (int)sprite_height) / 256;
					int sprite_line_offset = game->enemy[i].sprite_line * game->enemy[i].frame_height;
					if(game->enemy[i].die)
						sprite_line_offset += 22;
					if(game->enemy[i].die && game->enemy[i].sprite_line == 10)
						sprite_line_offset -= 2;
					if(game->enemy[i].died)
						sprite_line_offset += 22;
					if(game->enemy[i].sprite_line == 8)
						sprite_line_offset += 16;
					if(game->enemy[i].sprite_line == 9)
						sprite_line_offset += 18;
					if(game->enemy[i].sprite_line == 10 && !game->enemy[i].die)
						sprite_line_offset += 20;
					unsigned int color = get_color(game, game->enemy[i].curr_frame * game->enemy[i].frame_width +  + tex_x + 2, (tex_y + 2) + sprite_line_offset, ENEM);
					if (color != 0x00FF12)
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
