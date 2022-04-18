/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/18 01:10:32 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	color_map_1(t_vars *vars,int w,int h)
{
  int	x;
  int	y;
  int	color;

  x = w;
  while (x--)
    {
      y = h;
      while (y--)
        {
        	color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
	  		mlx_pixel_put(vars->mlx,vars->win,x,y,color);
        }
    }
}

// int	render_next_frame(t_vars *vars)
// {
// 	t_data	img;

// 	mlx_clear_window(vars->mlx, vars->win);
// 	img.img = mlx_new_image(vars->mlx, 600, 600);
// 	img.bits_per_pixel = 1;
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// }

int	main(void)
{
	t_vars			vars;
	t_data			img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 600, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 600, 600);
	img.bits_per_pixel = 100;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
								
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	color_map_1(&vars, 600, 600);
	mlx_loop_hook(vars.mlx, color_map_1, &vars);
	mlx_hook(vars.win, 6, 1L<<6, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}