/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:33:50 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/04 13:44:29 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_right(t_game *game)
{
	char	next_posit;

	next_posit = game->map.map_grid[game->player.coord.y / game->size_img]
		[(game->player.coord.x / game->size_img) + 1];
	if (next_posit == 'C')
	{
		game->map.map_grid[game->player.coord.y / game->size_img]
			[(game->player.coord.x / game->size_img) + 1] = '0';
		game->collect.num_c--;
	}
	if (next_posit == '1')
		return ;
	game->player.img_numb = 0;
	game->player.coord.x += game->size_img;
	game->player.num_moves++;
	if (next_posit == 'E' && game->collect.num_c == 0)
		ft_printf("You won!!!");
}

void	player_move_left(t_game *game)
{
	char	next_posit;

	next_posit = game->map.map_grid[game->player.coord.y / game->size_img]
		[(game->player.coord.x / game->size_img) - 1];
	if (next_posit == 'C')
	{
		game->map.map_grid[game->player.coord.y / game->size_img]
			[(game->player.coord.x / game->size_img) - 1] = '0';
		game->collect.num_c--;
	}
	if (next_posit == '1')
		return ;
	game->player.img_numb = 1;
	game->player.coord.x -= game->size_img;
	game->player.num_moves++;
	if (next_posit == 'E' && game->collect.num_c == 0)
		ft_printf("You won!!!");
}

void	player_move_up(t_game *game)
{
	char	next_posit;

	next_posit = game->map.map_grid[(game->player.coord.y - 1) / 
		game->size_img][game->player.coord.x / game->size_img];
	if (next_posit == 'C')
	{
		game->map.map_grid[(game->player.coord.y - 1) / 
			game->size_img][game->player.coord.x / game->size_img] = '0';
		game->collect.num_c--;
	}
	if (next_posit == '1')
		return ;
	game->player.coord.y -= game->size_img;
	game->player.num_moves++;
	if (next_posit == 'E' && game->collect.num_c == 0)
		ft_printf("You won!!!");
}

void	player_move_down(t_game *game)
{
	char	next_posit;

	next_posit = game->map.map_grid[(game->player.coord.y / 
		game->size_img) + 1][game->player.coord.x / game->size_img];
	if (next_posit == 'C')
	{
		game->map.map_grid[(game->player.coord.y / game->size_img) + 1]
			[game->player.coord.x / game->size_img] = '0';
		game->collect.num_c--;
	}
	if (next_posit == '1')
		return ;
	game->player.coord.y += game->size_img;
	game->player.num_moves++;
	if (next_posit == 'E' && game->collect.num_c == 0)
		ft_printf("You won!!!");
}
