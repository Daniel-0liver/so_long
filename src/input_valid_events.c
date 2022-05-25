/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:00:52 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/25 01:27:46 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	input_valid(int argc, char *map_path, t_game *game)
{
	if (argc != 2)
		error_event("Error when validating arguments", game);
	if (ft_strncmp(map_path + strlen(map_path) - 4, ".ber", 4) != 0)
		error_event("Map file must be .ber", game);
	if (!map_path)
		error_event("Map empty", game);
	game->map.map_path = map_path;
}
