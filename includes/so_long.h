/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:00:24 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/01 00:48:06 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../libft/include/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;


typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_player {
	int			num_moves;
	int			img_numb;
	int			num_p;
	int			render;
	char		**img_path;
	void		**img;
	t_coord		coord;
}				t_player;

typedef struct	s_win {
	void		*win_ptr;
	int			width;
	int			height;
}				t_win;

typedef struct	s_collect
{
	int			num_c;
	void		*img;
	char		*img_path;
	t_coord		coord;
}				t_collect;

typedef struct	s_floor
{
	void		*img;
	char		*img_path;
	t_coord		coord;
}				t_floor;

typedef struct	s_wall
{
	void		*img;
	char		*img_path;
	t_coord		coord;
}				t_wall;

typedef struct	s_exit
{
	int			num_e;
	void		*img;
	char		*img_path;
	t_coord		coord;
}				t_exit;

typedef struct	s_map {
	int			map_row;
	int			map_column;
	char		*map_path;
	char		**map_grid;
}				t_map;

typedef struct	s_game {
	void		*mlx;
	char		*valid_char;
	int			size_img;
	t_data		data;
	t_win		win;
	t_player	player;
	t_map		map;
	t_exit		exit;
	t_floor		floor;
	t_wall		wall;
	t_collect	collect;
}				t_game;

// Input Validation events
void		input_valid(int argc, char *map_path, t_game *game);

// Functions examples
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			render_next_frame(t_game *game);

// Game hook events
int			key_hook(int keycode, t_game *game);
int			mouse_hook(int x, int y, t_game *game);
void		get_hooks(t_game *game);

// Game init events
void		game_init(t_game *game);
void		window_init(t_game *game);
void		pixel_init(t_game *game);
void		path_init(t_game *game);
void		player_img_init(t_game *game);
void		img_int(t_game *game);

//Game close events
void		close_win(t_game *game);
void		destroy_images(t_game *game);
void		error_event(char *error_msg, t_game *game);
void		game_free_memory(t_game *game);

// Game render events
void		map_render(t_game *game);
void		player_render(t_game *game);
void		win_render(t_game *game);
void		exit_render(t_game *game);

// Player events
void		player_move_right(t_game *game);
void		player_move_left(t_game *game);
void		player_move_up(t_game *game);
void		player_move_down(t_game *game);

// Map events
void		map_read(t_game *game);
void		map_valid_char(t_game *game);
void		map_is_rectangular(t_game *game);
void		map_is_closed(t_game *game);
void		char_valid_event(t_game *game, int i, int j, char c);

# endif