/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:00:52 by dateixei          #+#    #+#             */
/*   Updated: 2022/07/29 20:21:45 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	input_valid(int argc, char *map_path, t_game *game)
{
	if (argc != 2)
		exit(printf("Error\nValidating arguments\n") > 0);
	if (ft_strncmp(map_path + strlen(map_path) - 4, ".ber", 4) != 0)
		exit(printf("Error\nMap file must be .ber\n") > 0);
	if (open(map_path, O_RDONLY) == -1)
		exit(printf("Error\nIts not a valid file\n") > 0);
	game->map.map_path = map_path;
	game->size_img = 64;
	game->valid_char = "ECPT10";
	game->player.img = NULL;
	game->player.img_path = NULL;
	game->trap.img_path = NULL;
	game->trap.img = NULL;
	game->collect.img = NULL;
	game->step.img = NULL;
	game->exit.img = NULL;
	game->floor.img = NULL;
	game->wall.img = NULL;
}
