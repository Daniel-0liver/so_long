/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:46 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/20 23:15:03 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_render(t_game *game)
{
	
}

void	player_render(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->player.player_img, 
	game->player.player_x, game->player.player_y);
}

void	win_render(t_game *game)
{
	map_render(game);
	player_render(game);
}