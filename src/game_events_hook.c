/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 01:22:57 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/25 01:23:00 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook!\nKeycode = %d\n", keycode);
	if (keycode == 65307 || keycode == 113)
		close_win(game);
	return (0);
}

