/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:54:01 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/24 03:33:38 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook!\nKeycode = %d\n", keycode);
	if (keycode == 100)
	{
		while (game->win->height > game->player->player_pos_x)
		{
			game->player->player_pos_x += 10;
			mlx_destroy_image(game->mlx, game->player->player_img);
			game->player->player_img = mlx_xpm_file_to_image(game->mlx, game->player->player_img_path, &game->win->width, &game->win->height);
			mlx_put_image_to_window(game->mlx, game->win->win_ptr, game->player->player_img, game->player->player_pos_x, game->player->player_pos_y);
		}
	}
	return (0);
}

int	mouse_hook(int x, int y, t_game *game)
{
	// printf("Hello from mouse_hook!\nMouse Hook x = %d\nMouse Hook y = %d\n", x, y);
	int color;
	
	color = rand();
	mlx_pixel_put(game->mlx, game->win, x, y, color);
	return (0);
}
int	close_win(int keycode, t_game *game)
{
	if (keycode == 65307)
		mlx_destroy_window(game->mlx, game->win->win_ptr);
	return (0);
}