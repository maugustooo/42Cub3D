
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

typedef enum e_files
{
	FILE_WALL,
	FILE_FLOOR
}	t_files;

typedef enum e_error
{
	ERROR_ARGS,
} t_error;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_textr
{
	char	*north;
	char	*east;
	char	*south;
	char	*west;
	char	*floor;
	char	*ceiling;
}	t_textr;

typedef struct s_game
{
	char	**map;
	
	int		x;
	int		y;
	int		tlines;
	int		mapstart;
	int		mapend;
	int		widthmap;
	int		heightmap;

	void	*mlx_ptr;
	void	*window;

	bool	mapflag;
	int		rgb_sky[3];
	int		rgb_floor[3];
	t_img	img[2];
}				t_game;


t_textr *init_textr(void);
void	parse(char **argv, t_game *game, t_textr *textr);
void	check_extension(char *file);
void	read_map(char *file, t_game *game);
void	check_textures(t_game *game, t_textr *textr);
void	check_map_content(t_game *game);
void    check_file(char *file);
int		sepuku(t_game *game);
void	read_textures(char *file, t_game *game, t_textr *textures);

int controls(int keycode, t_game *game);
void init_img(t_game *game);
void render(t_game *game);

#endif