# include"cub3d_bonus.h"

double get_delta_time()
{
	static clock_t last_time = 0;
	clock_t current_time = clock();
	double delta_time = (double)(current_time - last_time) / CLOCKS_PER_SEC;
	last_time = current_time;
	return delta_time;
}

void draw_opening_or_closing_door(t_game *game, int line_height)
{
    double timer;
    int door_width;
    int color;
    int x;

    timer = game->door_timer_map[game->map_y][game->map_x];
    door_width = (int)(64 * (1.0 - timer));
    game->wall_start = -line_height / 2 + SCREEN_HEIGHT / 2;
    game->wall_end = line_height / 2 + SCREEN_HEIGHT / 2;
    game->step = 64.0 / line_height;
    int door_tex_start = (SCREEN_WIDTH / 2) - (door_width * 64);
    int door_tex_end = (SCREEN_WIDTH / 2) + (door_width * 64);
    x = door_tex_start;
	printf("door_tex_start: %d\n", door_tex_start);
	printf("door_tex_end: %d\n", door_tex_end);
	printf("door_width: %d\n", door_width);
    while (x < door_tex_end)
    {
        game->tex_x = (x - door_tex_start) % 64;
        game->wall_start = -line_height / 2 + SCREEN_HEIGHT / 2;
        game->tex_pos = 0.0;
        while (game->wall_start < game->wall_end)
        {
            game->tex_y = (int)game->tex_pos;
            game->tex_pos += game->step;
            color = get_color(game, game->tex_x, game->tex_y, DOOR);
            put_pixel(game, x, game->wall_start, color);
            game->wall_start++;
        }
        x++;
    }
}


void	draw_static_door(t_game *game, int x, int line_height)
{
	game->wall_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	game->wall_end = line_height / 2 + SCREEN_HEIGHT / 2;
	define_texture(game, game->wall_start, line_height);
	while (game->wall_start < game->wall_end)
	{
		game->tex_y = (int)game->tex_pos;
		game->tex_pos += game->step;
		put_pixel(game, x, game->wall_start, get_color(game, game->tex_x, game->tex_y, DOOR));
		game->tex_x++;
		game->wall_start++;
	}
}

void	update_door_timers(t_game *game, double delta_time)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->heightmap)
	{
		x = 0;
		while (x < game->widthmap)
		{
			if (game->door_state_map[y][x] == 1
				|| game->door_state_map[y][x] == 3)
			{
				if (game->door_state_map[y][x] == 1)
					game->door_timer_map[y][x] += delta_time * 0.3;
				else
					game->door_timer_map[y][x] -= delta_time * 0.3;
				if (game->door_timer_map[y][x] <= 0)
				{
					game->door_timer_map[y][x] = 0;
					game->door_state_map[y][x] = 0;
				}
				else if (game->door_timer_map[y][x] >= 1)
				{
					game->door_timer_map[y][x] = 1;
					game->door_state_map[y][x] = 2;
				}
			}
			x++;
		}
		y++;
	}
}

void	draw_door(t_game *game, int x)
{
	int	line_height;
	int	door_state;

	(void)x;
	line_height = SCREEN_HEIGHT / game->walldist;
	door_state = game->door_state_map[game->map_y][game->map_x];
	if (door_state == 1 || door_state == 3)
		draw_opening_or_closing_door(game, line_height);
}
