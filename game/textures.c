/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:05:21 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/20 20:58:11 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"
#include "mlx.h"

static void	texture_sprite_init(t_vars *vars)
{
	t_data		sprite;
	int			j;

	j = 64;
	sprite.img = mlx_xpm_file_to_image(vars->mlx, vars->map_data.sprite,
			&j, &j);
	if (!sprite.img)
		exit_with_error("No SPRITE texture", vars, 0);
	else
		sprite.addr = mlx_get_data_addr(sprite.img,
				&sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);
	vars->sprite = sprite;
}

static void	texture_init2(t_vars *vars)
{
	t_data		textr3;
	t_data		textr4;
	int			i;

	i = 32;
	textr3.img = mlx_xpm_file_to_image(vars->mlx, vars->map_data.wpath,
			&i, &i);
	if (!textr3.img)
		exit_with_error("No WEST texture", vars, 0);
	else
		textr3.addr = mlx_get_data_addr(textr3.img, &textr3.bits_per_pixel,
				&textr3.line_length, &textr3.endian);
	vars->texture3 = textr3;
	textr4.img = mlx_xpm_file_to_image(vars->mlx, vars->map_data.spath,
			&i, &i);
	if (!textr4.img)
		exit_with_error("No SOUTH texture", vars, 0);
	else
		textr4.addr = mlx_get_data_addr(textr4.img, &textr4.bits_per_pixel,
				&textr4.line_length, &textr4.endian);
	vars->texture4 = textr4;
	texture_sprite_init(vars);
}

void	texture_init(t_vars *vars)
{
	t_data		textr1;
	t_data		textr2;
	int			i;

	i = 32;
	textr1.img = mlx_xpm_file_to_image(vars->mlx, vars->map_data.npath,
			&i, &i);
	if (!textr1.img)
		exit_with_error("No NORTH texture", vars, 0);
	else
		textr1.addr = mlx_get_data_addr(textr1.img, &textr1.bits_per_pixel,
				&textr1.line_length, &textr1.endian);
	vars->texture1 = textr1;
	textr2.img = mlx_xpm_file_to_image(vars->mlx, vars->map_data.epath,
			&i, &i);
	if (!textr2.img)
		exit_with_error("No EAST texture", vars, 0);
	else
		textr2.addr = mlx_get_data_addr(textr2.img, &textr2.bits_per_pixel,
				&textr2.line_length, &textr2.endian);
	vars->texture2 = textr2;
	texture_init2(vars);
}
