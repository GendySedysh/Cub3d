/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:18:56 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/26 18:02:34 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

t_ray	ray_init(void)
{
	t_ray	ray;

	ray.flag = 0;
	ray.num_of_sprites = 0;
	ray.sprite_len = 0;
	ray.len = 0;
	ray.x_ray = 0;
	ray.y_ray = 0;
	ray.angle = 0;
	ray.s = 0;
	return (ray);
}

t_player	player_init(void)
{
	t_player	player;

	player.x = 0;
	player.y = 0;
	player.pov = 0;
	return (player);
}

t_sprite	sprite_init(void)
{
	t_sprite	sprite;

	sprite.x = 0;
	sprite.y = 0;
	sprite.next = NULL;
	return (sprite);
}

t_data	data_init(void)
{
	t_data	data;

	data.img = NULL;
	data.addr = NULL;
	data.bits_per_pixel = 0;
	data.line_length = 0;
	data.endian = 0;
	return (data);
}

t_vars	vars_init(void)
{
	t_vars	vars;

	vars.mlx = NULL;
	vars.win = NULL;
	vars.keys = keys_init();
	vars.map_data = map_parcer_init();
	vars.player = player_init();
	vars.texture1 = data_init();
	vars.texture2 = data_init();
	vars.texture3 = data_init();
	vars.texture4 = data_init();
	vars.sprite = data_init();
	vars.sprite_list = NULL;
	vars.img = data_init();
	return (vars);
}
