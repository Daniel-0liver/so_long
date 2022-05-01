/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:33:50 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/01 02:31:35 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_right(t_game *game)
{
	game->player->player_posit->x += 50;
}

void	player_move_left(t_game *game)
{
	game->player->player_posit->x -= 50;
}

void	player_move_up(t_game *game)
{
	game->player->player_posit->y -= 50;
}

void	player_move_down(t_game *game)
{
	game->player->player_posit->y += 50;
}
