/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:36 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/27 00:23:56 by dateixei         ###   ########.fr       */
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
	game->map.map_grid = ft_calloc(1, sizeof(char**));
	if (game->map.map_grid == NULL)
		error_event("Error while allocating memory for map", game);
	i = 0;
	while (game->map.map_grid != NULL)
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
	
	i = 0;
	while (game->map.map_grid[i])
		i++;
	game->map.map_row = i;
	i = 0;
	while (game->map.map_grid[0][i])
		i++;
	game->map.map_column = i - 1;
	if (game->map.map_row == game->map.map_column)
		error_event("Error Map Must be Retangular!", game);
}

void	map_valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map_grid[i])
	{
		j = 0;
		while (game->map.map_grid[i][j])
		{
			if (game->map.map_grid[i][j] == 'E')
				game->exit.num_e += 1;
			if (game->map.map_grid[i][j] == 'C')
				game->collect.num_c += 1;
			if (game->map.map_grid[i][j] == 'P')
				game->player.num_p += 1;
			if (game->map.map_grid[i][j] != '\n' && !ft_strchr(VALID_CHAR, 
				game->map.map_grid[i][j]))
				error_event("Invalid char", game);
			j++;
		}
		if (j - 1 != game->map.map_column)
			error_event("Erro map size invalid", game);
		i++;
	}
}
