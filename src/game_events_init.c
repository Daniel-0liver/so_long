/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:23:58 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/25 01:24:01 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	game_memory_allocation(t_game *game)
{
	game->data = ft_calloc(1, sizeof(t_data));
	game->win = ft_calloc(1, sizeof(t_win));
	game->player = ft_calloc(1, sizeof(t_player));
	return ;
}

void	game_init(t_game *game)
{
	window_init(game);
	player_init(game);
	// pixel_init(game);
}

void	window_init(t_game *game)
{
	game->win->height = 500;
	game->win->width = 500;
	game->win->win_ptr = mlx_new_window(game->mlx, game->win->height, game->win->width, "teste");
	return ;
}

void	player_init(t_game *game)
{
	game->player->player_img_path = "./src/player.xpm";
	game->player->player_pos_x = 10;
	game->player->player_pos_y = 10;
	game->player->player_img = mlx_xpm_file_to_image(game->mlx, game->player->player_img_path, &game->win->width, &game->win->height);
	return ;
}

void	pixel_init(t_game *game)
{
	// game->data->img = mlx_new_image(game->mlx, 50, 50);
	// game->data->addr = mlx_get_data_addr(game->data->img, &game->data->bits_per_pixel, &game->data->line_length, &game->data->endian);
	// my_mlx_pixel_put(game->data->img, 20, 20, 0x00FF0000);
	// mlx_put_image_to_window(game->mlx, game->win->win_ptr, game->data->img, 50, 50);
	// return ;
}