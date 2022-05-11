/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:06:57 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/12 00:23:06 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *game)
{
	if (game->player.player_img != NULL)
		mlx_destroy_image(game->mlx, game->player.player_img);
	return ;
}

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win.win_ptr);
	game->win.win_ptr = NULL;
	destroy_images(game);
	exit(0);
}

void	error_event(char *error_msg, int breakpoint, t_game *game)
{
	
}