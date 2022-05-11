/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:46 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/11 23:57:05 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_render(t_game *game);

static void	player_render(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->player.player_img, game->player.player_posit->x, game->player.player_posit->y);
}

int	win_render(t_game *game)
{
	player_render(game);
	return (0);
}