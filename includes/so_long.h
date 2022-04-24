/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:00:24 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/24 15:12:46 by dateixei         ###   ########.fr       */
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
# include "libft.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player {
	int		player_pos_x;
	int		player_pos_y;
	char	*player_img_path;
	void	*player_img;
}				t_player;


typedef struct	s_win {
	void	*win_ptr;
	int		width;
	int		height;
}				t_win;

typedef struct	s_game {
	void		*mlx;
	t_data		*data;
	t_win		*win;
	t_player	*player;
}				t_game;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_win(t_game *game);
int		key_hook(int keycode, t_game *game);
int		mouse_hook(int x, int y, t_game *game);
int		render_next_frame(t_game *game);
void	game_memory_allocation(t_game *game);
void	game_init(t_game *game);
void	window_init(t_game *game);
void	pixel_init(t_game *game);
void	player_init(t_game *game);

//Game close events
void	destroy_images(t_game *game);

# endif