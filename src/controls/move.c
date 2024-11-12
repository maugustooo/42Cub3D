#include "cub3d.h"

int	move_up(t_game *game, double next_x, double next_y)
{
	int move;

	move = 0;
	if(game->map[(int)(game->player.y + next_y)][(int)game->player.x] != '1')
	{
		game->player.y += next_y;
		move = 1;
	}
	if(game->map[(int)game->player.y][(int)(game->player.x + next_x)] != '1')
	{
		game->player.x += next_x;
		move = 1;
	}
	return (move);
}

int	move_down(t_game *game, double next_x, double next_y)
{
	int move;

	move = 0;
	if(game->map[(int)(game->player.y - next_y)][(int)game->player.x] != '1')
	{
		game->player.y -= next_y;
		move = 1;
	}
	if(game->map[(int)game->player.y][(int)(game->player.x - next_x)] != '1')
	{
		game->player.x -= next_x;
		move = 1;
	}
	return (move);
}

int	move_right(t_game *game, double next_x, double next_y)
{
	int move;

	move = 0;
	if(game->map[(int)(game->player.y + next_y)][(int)game->player.x] != '1')
	{
		game->player.y += next_y;
		move = 1;
	}
	if(game->map[(int)game->player.y][(int)(game->player.x + next_x)] != '1')
	{
		game->player.x += next_x;
		move = 1;
	}
	return (move);
}

int	move_left(t_game *game, double next_x, double next_y)
{
	int move;

	move = 0;
	if(game->map[(int)(game->player.y - next_y)][(int)game->player.x] != '1')
	{
		game->player.y -= next_y;
		move = 1;
	}
	if(game->map[(int)game->player.y][(int)(game->player.x - next_x)] != '1')
	{
		game->player.x -= next_x;
		move = 1;
	}
	return (move);
}
