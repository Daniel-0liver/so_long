/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:00:52 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/07 00:33:20 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	input_valid(int argc, char *map_path, t_game *game)
{
	if (argc != 2)
		error_event("Error\nWhen validating arguments", game, 1);
	if (ft_strncmp(map_path + strlen(map_path) - 4, ".ber", 4) != 0)
		error_event("Error\nMap file must be .ber", game, 1);
	game->map.map_grid = calloc(1, sizeof(char **));
	free(game->map.map_grid);
	if (game->map.map_grid == NULL)
		error_event("Error\nWhile allocating memory for map", game, 1);
	game->map.map_path = map_path;
	game->size_img = 64;
	game->valid_char = "ECPT10";
	game->player.img = NULL;
	game->player.img_path = NULL;
	game->trap.img_path = NULL;
	game->trap.img = NULL;
}
