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

int controls(t_game *game)
{
	int moved;

	moved = 0;
	if(game->player.move_y == 1 || game->player.move_y == -1 || game->player.move_y == 0)
		printf("move_y: %d\n", game->player.move_y);
	if(game->player.move_x == 1 || game->player.move_x == -1 || game->player.move_x == 0)
		printf("move_x: %d\n", game->player.move_x);
	if(game->player.move_y == 1)
		moved = move_up(game, game->player.dir_x * SPEED, game->player.dir_y * SPEED);
	if(game->player.move_y == -1)
		move_down(game, game->player.dir_x * SPEED, game->player.dir_y * SPEED);
	if(game->player.move_x == 1)
		move_right(game, game->plane_x * SPEED, game->plane_y * SPEED);
	if(game->player.move_x == -1)
		move_left(game, game->plane_x * SPEED, game->plane_y * SPEED);
	// if(keycode == XK_w || keycode == XK_s)
	// 	move(game, keycode, game->player.dir_x * SPEED, game->player.dir_y * SPEED);
	// if(keycode == XK_a || keycode == XK_d)
	// 	move(game, keycode, game->plane_x *  SPEED, game->plane_y * SPEED);
	// if(keycode == XK_Left || keycode == XK_Right)
	// {
	// 	if(keycode == XK_Left)
	// 		rotate(game, -ROTSPEED);
	// 	if(keycode == XK_Right)
	// 		rotate(game, ROTSPEED);
	// }
	return (0);
}
