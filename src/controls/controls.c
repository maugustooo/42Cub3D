#include "cub3d.h"

void rotate(t_game *game, double angle)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y * cos(angle);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
	game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
}

void move(t_game *game, int keycode, double next_x, double next_y)
{
	if(keycode == XK_w || keycode == XK_d)
	{
		if(game->map[(int)(game->player.y + next_y)][(int)game->player.x] != '1')
			game->player.y += next_y;
		if(game->map[(int)game->player.y][(int)(game->player.x + next_x)] != '1')
			game->player.x += next_x;
	}
	if(keycode == XK_s || keycode == XK_a)
	{
		if(game->map[(int)(game->player.y - next_y)][(int)game->player.x] != '1')
			game->player.y -= next_y;
		if(game->map[(int)game->player.y][(int)(game->player.x - next_x)] != '1')
			game->player.x -= next_x;
	}
}

int controls(int keycode, t_game *game)
{
	if(keycode == XK_Escape)
		ft_exit(game);
	if(keycode == XK_w || keycode == XK_s)
		move(game, keycode, game->player.dir_x * SPEED, game->player.dir_y * SPEED);
	if(keycode == XK_a || keycode == XK_d)
		move(game, keycode, game->plane_x *  SPEED, game->plane_y * SPEED);
	if(keycode == XK_Left || keycode == XK_Right)
	{
		if(keycode == XK_Left)
			rotate(game, -ROTSPEED);
		if(keycode == XK_Right)
			rotate(game, ROTSPEED);
	}
	return (0);
}
