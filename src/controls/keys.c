#include "cub3d.h"

int handle_key_press(int keycode, t_game *game)
{
	if(keycode == XK_Escape)
		ft_exit(game);
	if (keycode == XK_w)
		game->player.move_y += 1;
	if (keycode == XK_s)
		game->player.move_y += -1;
	if (keycode == XK_a)
		game->player.move_x += -1;
	if (keycode == XK_d)
		game->player.move_x += 1;
	// if (keycode == XK_Left)
	// 	game->player->rotate = -1;
	// if (keycode == XK_Right)
	// 	game->player->rotate = 1;
	return (0);
}

int handle_key_release(int keycode, t_game *game)
{
	if(keycode == XK_Escape)
		ft_exit(game);
	if (keycode == XK_w && game->player.move_y >= 1)
		game->player.move_y = 0;
	if (keycode == XK_s && game->player.move_y <= -1)
		game->player.move_y = 0;
	if (keycode == XK_a && game->player.move_x <= -1)
		game->player.move_x = 0;
	if (keycode == XK_d && game->player.move_x >= 1)
		game->player.move_x = 0;
	// if (keycode == XK_Left || keycode == XK_Right)
	// 	game->player->rotate = 0;
	return (0);
}
