/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/15 18:23:47 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_game	game;
	
	game_memory_allocation(&game);
	game.mlx = mlx_init();
	game_init(&game);
	get_hooks(&game);
	mlx_loop(game.mlx);
}