#include "cub3d_bonus.h"

void	put_pixel_to_image(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	pixel = (game->fps_img.addr + (y * game->fps_img.line_len
			+ x * (game->fps_img.bpp / 8)));
	*(int *)pixel = color;
}

void draw_filled_rectangle(t_game *game, int x, int y, int width, int height, int color)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            put_pixel_to_image(game, x + j, y + i, color);
        }
    }
}

void draw_char_to_image(t_game *game, char c, int x, int y, uint32_t color)
{
	uint8_t font_bitmap[128][8] = {
    ['0'] = {0x3C, 0x66, 0x6E, 0x76, 0x66, 0x66, 0x3C, 0x00},
    ['1'] = {0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00},
    ['2'] = {0x3C, 0x66, 0x06, 0x1C, 0x30, 0x60, 0x7E, 0x00},
    ['3'] = {0x3C, 0x66, 0x06, 0x1C, 0x06, 0x66, 0x3C, 0x00},
    ['4'] = {0x0C, 0x1C, 0x3C, 0x6C, 0x7E, 0x0C, 0x0C, 0x00},
    ['5'] = {0x7E, 0x60, 0x7C, 0x06, 0x06, 0x66, 0x3C, 0x00},
    ['6'] = {0x3C, 0x66, 0x60, 0x7C, 0x66, 0x66, 0x3C, 0x00},
    ['7'] = {0x7E, 0x06, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00},
    ['8'] = {0x3C, 0x66, 0x66, 0x3C, 0x66, 0x66, 0x3C, 0x00},
    ['9'] = {0x3C, 0x66, 0x66, 0x3E, 0x06, 0x66, 0x3C, 0x00},
    ['F'] = {0x7E, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x60, 0x00},
    ['P'] = {0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60, 0x60, 0x00},
    ['S'] = {0x3C, 0x66, 0x60, 0x3C, 0x06, 0x66, 0x3C, 0x00},
    [':'] = {0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00},
};
    if (ft_isascii(c) == 0)
        return;
    for (int row = 0; row < 16; row++)
    {
        uint8_t row_data = font_bitmap[(int)c][row];
        for (int col = 0; col < 16; col++)
        {
            if (row_data & (1 << (7 - col)))
                put_pixel_to_image(game, x + col, y + row, color);
        }
    }
}

void	init_fps(t_fps *fps)
{
    gettimeofday(&fps->last_time, NULL);
    fps->frame_count = 0;
    fps->elapsed_time = 0.0;
    fps->fps = 0;
}

void	update_fps(t_game *game)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    double delta_time = (current_time.tv_sec - game->fps.last_time.tv_sec) +
                        (current_time.tv_usec - game->fps.last_time.tv_usec) / 1000000.0;

    game->fps.elapsed_time += delta_time;
    game->fps.frame_count++;
    game->fps.last_time = current_time;

    if (game->fps.elapsed_time >= 1.0)
	{
        game->fps.fps = game->fps.frame_count;
        game->fps.frame_count = 0;
        game->fps.elapsed_time = 0.0;
    }
}

void	render_fps(t_game *game)
{
	char	fps_str[10];
	int		x;
	int		y;
	int		i;

	x = 5;
	y = 5;
	i = 0;
	snprintf(fps_str, sizeof(fps_str), "FPS: %d", game->fps.fps);
	draw_filled_rectangle(game, x, y, 8 * strlen(fps_str), 8, 0x000000);
	while (fps_str[i] != '\0')
	{
		draw_char_to_image(game, fps_str[i], x + i * 8, y, 0xFFFFFF);
		i++;
	}
}
