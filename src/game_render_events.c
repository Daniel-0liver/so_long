/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:46 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/15 02:31:35 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_render(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->map.wall_img, 
	466, 466);
}

static void	player_render(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->player.player_img, 
	game->player.player_posit->x, game->player.player_posit->y);
}

int	win_render(t_game *game)
{
	map_render(game);
	player_render(game);
	return (0);
}