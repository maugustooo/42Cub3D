#include "cub3d.h"

int controls(int keycode, t_game *game)
{
	if(keycode == XK_Escape)
		sepuku(game);
	// if(keycode == XK_w)
	// 	move_up(game);
	// if(keycode == XK_s)
	// 	move_down(game);
	// if(keycode == XK_a)
	// 	move_left(game);
	// if(keycode == XK_d)
	// 	move_right(game);
	// if(keycode == XK_Left)
	// 	rotate_left(game);
	// if(keycode == XK_Right)
	// 	rotate_right(game);
	return (0);
}
