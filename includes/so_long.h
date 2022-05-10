/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:00:24 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/09 21:44:38 by dateixei         ###   ########.fr       */
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
# include "../libft/libft.h"

typedef struct	s_posit {
	int	x;
	int	y;
}				t_posit;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player {
	t_posit	*player_posit;
	char	*player_img_path;
	void	*player_img;
}				t_player;

typedef struct	s_win {
	void	*win_ptr;
	int		width;
	int		height;
}				t_win;

typedef struct	s_map {
	t_posit		map_posit;
	int			map_x;
	int			map_y;
	int			num_c;
	int			num_e;
	int			num_p;
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

//Game close events
int			close_win(t_game *game);
void		destroy_images(t_game *game);

// Game render events
static void	map_render(t_game *game);
static void	player_render(t_game *game);
int			win_render(t_game *game);

// Player events
void		player_move_right(t_game *game);
void		player_move_left(t_game *game);
void		player_move_up(t_game *game);
void		player_move_down(t_game *game);

# endif