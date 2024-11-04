#include "cub3d.h"

int controls(int keycode, t_game *game)
{
	if (keycode == 65307)
		sepuku(game);
	return (0);
}
