/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/10 15:24:00 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char	**argv)
{
	t_game	game;
	
	(void)argv;
	argc = 2;
	input_valid(argc, "maps/map.ber", &game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		error_event("Error\nWhile initialing MLX", &game, 1);
	game_init(&game);
	get_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}