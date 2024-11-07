
#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

#define SPEED 0.1

typedef enum e_error
{
	ERROR_ARGS,
	ERROR_FILE,
	ERROR_MAP,
	ERROR_MALLOC,
	ERROR_COLOR,
	ERROR_TEXTURE,
	ERROR_MLX,
	ERROR_ORDER,
	ERROR_DUP,
}				t_error;

typedef enum e_files
{
	FILE_WALL,
	FILE_FLOOR
}				t_files;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_textr
{
	char	*north;
	char	*east;
	char	*south;
	char	*west;
	char	*floor;
	char	*ceiling;
}				t_textr;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_point;

typedef struct s_game
{
	char	**map;
	
	int		x;
	int		y;
	int		tlines;
	int		mapstart;
	int		mapend;
	int		width;
	int		heightmap;
	int		widthmap;

	void	*mlx_ptr;
	void	*window;

	bool	mapflag;
	int		rgb_sky[3];
	int		rgb_floor[3];
	
	t_point	player;

	t_img	img[2];
}				t_game;


t_textr	*init_textr(void);
void	parse(char **argv, t_game *game, t_textr *textr);
void	check_extension(char *file);
void	read_map(char *file, t_game *game);
void	check_textures(t_game *game, t_textr *textr);
void	check_map_content(t_game *game);
void	check_file(char *file, t_game *game);
void	check_duplicate_text(t_game *game, t_textr *textr);
void	read_textures(char *file, t_game *game, t_textr *textures);
char	*return_no_extra_spaces(char *tmp);
void	check_text_content(t_game *game, t_textr *textures, int i);
void	check_rgb(char *color, t_game *game, int type);
void	check_colors(t_game *game, t_textr *textr);
void	check_order(char *file, t_game *game);
void	map_content_validation(t_game *game);
int		sepuku(t_game *game, enum e_error i);
int		ft_exit(t_game *game);

int		controls(int keycode, t_game *game);
void	init_img(t_game *game);
void	render(t_game *game);

#endif