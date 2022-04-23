/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:03:17 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/23 15:59:30 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	window_init(game);
	pixel_init(game);
}

void	window_init(t_game *game)
{
	game->win->height = 100;
	game->win->width = 100;
	game->win->win_ptr = mlx_new_window(game->mlx, game->win->height, game->win->width, "teste");
	return ;
}

void	pixel_init(t_game *game)
{
	
	
	// game->data->img = mlx_new_image(game->mlx, 100, 100);
	game->data->addr = mlx_get_data_addr(game->data->img, &game->data->bits_per_pixel, &game->data->line_length, &game->data->endian);
	// my_mlx_pixel_put(game->data->img, 50, 50, 0x00FF0000);
	// mlx_put_image_to_window(game->mlx, game->win->win_ptr, game->data->img, 50, 50);
}