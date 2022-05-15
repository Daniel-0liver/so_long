/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:36 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/15 02:28:54 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_read(t_game *game)
{
	int		fd;
	int		i;
	
	fd = open(game->map.map_path, O_RDONLY);
	if (fd < 0)
		error_event("Error while opening file", game);
	i = 0;
	while (game->map.map_grid[i])
	{
		game->map.map_grid[i] = get_next_line(fd);
		if (game->map.map_grid[i] == NULL)
			return ;
		i++;
	}
}

void	map_is_rectangular(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (game->map.map_grid[i])
		i++;
	game->map.map_row = i;
}

void	map_valid_char(t_game *game)
{
// 	int	i;

// 	i = 0;
// 	while (game->map.map_grid[])
// 	{
		
// 	}
} 