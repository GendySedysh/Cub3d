/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_screenshot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:51:02 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/26 16:06:08 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "map_parcer.h"

void	render_screenshot(t_vars *vars)
{
	t_data	new_img;

	vars->sprite_list = NULL;
	new_img.img = mlx_new_image(vars->mlx, vars->map_data.width,
			vars->map_data.height);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	multiple_raycasting(new_img, vars);
	vars->sprite_list = sort(vars->sprite_list);
	render_sprite(new_img, vars);
	vars->img = new_img;
	pic_export(vars);
	parcer_free(vars->map_data);
	mlx_destroy_image(vars->mlx, new_img.img);
	exit(0);
}
