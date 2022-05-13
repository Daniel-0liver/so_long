/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:36 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/13 01:17:30 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_read(t_game *game)
{
	int		fd;
	int		i;
	
	fd = open(game->map.map_path, O_RDONLY);
	if (fd < 0)
		error_event("Error while opening file", 1, game);
	i = 0;
	while (game->map.map_grid[i])
	{
		game->map.map_grid[i] = get_next_line(fd);
		ft_printf("%s\n", game->map.map_grid[i]);
		if (game->map.map_grid[i])
			return ;
		ft_printf("%d\n", i);
		i++;
	}
}
