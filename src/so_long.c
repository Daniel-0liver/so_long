/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/07/29 20:17:00 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char	**argv)
{
	t_game	game;

	input_valid(argc, argv[1], &game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(printf("Error\nWhile initialing MLX\n") > 0);
	game_init(&game);
	get_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
