/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:00:24 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/15 18:28:19 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
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

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_player {
	int			player_x;
	int			player_y;
	char		*player_img_path;
	void		*player_img;
}				t_player;

typedef struct	s_win {
	void		*win_ptr;
	int			width;
	int			height;
}				t_win;

typedef struct	s_map {
	int			map_row;
	int			map_column;
	int			num_c;
	int			num_e;
	int			num_p;
	char		**map_grid;
	char		*map_path;
	void		*map_img;
	char		*floor_path;
	void		*floor_img;
	char		*wall_path;
	void		*wall_img;
}				t_map;

typedef struct	s_game {
	void		*mlx;
	t_data		data;
	t_win		win;
	t_player	player;
	t_map		map;
}				t_game;



// Functions examples
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			render_next_frame(t_game *game);

// Game hook events
int			key_hook(int keycode, t_game *game);
int			mouse_hook(int x, int y, t_game *game);
void		get_hooks(t_game *game);

// Game init events
void		game_memory_allocation(t_game *game);
void		game_init(t_game *game);
void		window_init(t_game *game);
void		pixel_init(t_game *game);
void		player_init(t_game *game);
void		map_init(t_game *game);

//Game close events
void		close_win(t_game *game);
void		destroy_images(t_game *game);
void		error_event(char *error_msg, t_game *game);
void		game_free_memory(t_game *game);

// Game render events
void		map_render(t_game *game);
void		player_render(t_game *game);
void		win_render(t_game *game);

// Player events
void		player_move_right(t_game *game);
void		player_move_left(t_game *game);
void		player_move_up(t_game *game);
void		player_move_down(t_game *game);

// Map events
void		map_read(t_game *game);
void		map_valid_char(t_game *game);
void		map_is_rectangular(t_game *game);
# endif