#include "cub3d_bonus.h"

bool is_valid_position(t_game *game, double x, double y)
{
    int map_x = (int)x;
    int map_y = (int)y;
    if (map_x < 0 || map_x >= game->widthmap || map_y < 0 || map_y >= game->heightmap)
    {  
        return false;
    }
    return (game->map[map_y][map_x] == '0' || game->map[map_y][map_x] == 'X' || game->map[map_y][map_x] == 'd');
}

bool is_path_clear(t_game *game, double x1, double y1, double x2, double y2)
{
    double delta_x = x2 - x1;
    double delta_y = y2 - y1;
    double step = fmax(fabs(delta_x), fabs(delta_y));
    
    if (step == 0)
        return true;
    
    double step_x = delta_x / step;
    double step_y = delta_y / step;

    double current_x = x1;
    double current_y = y1;
    
    for (int i = 0; i <= step; i++)
    {
		if (!is_valid_position(game, current_x, current_y))
			return false;
        current_x += step_x + 0.1;
        current_y += step_y;
    }

    return true;
}

bool has_line_of_sight(t_game *game, double x1, double y1, double x2, double y2)
{
    return (is_path_clear(game, x1, y1, x2, y2));
}

void handle_enemy(t_game *game)
{
	int i = 0;
	while (i < game->enemy_count)
	{
		if(!game->enemy[i].died && !game->enemy[i].attacking)
		{
			if(has_line_of_sight(game, game->enemy[i].x, game->enemy[i].y, game->player.x, game->player.y))
			{
				double direction_x = game->player.x - game->enemy[i].x;
				double direction_y = game->player.y - game->enemy[i].y;
				double magnitude = sqrt(direction_x * direction_x + direction_y * direction_y);
				if (magnitude != 0)
				{
					direction_x /= magnitude;
					direction_y /= magnitude;
				}
				double new_x = game->enemy[i].x + direction_x * 0.04;
				double new_y = game->enemy[i].y + direction_y * 0.04;
				if (is_path_clear(game, game->enemy[i].x, game->enemy[i].y, new_x, new_y))
				{
					game->enemy[i].x = new_x;
					game->enemy[i].y = new_y;
				}
				game->enemy[i].moving = true;
			}
			else
				game->enemy[i].moving = false;
		}
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
