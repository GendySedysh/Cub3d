/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:18:45 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 14:41:36 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

t_parser_control	parser_control_init(void)
{
	t_parser_control	parser_control;

	parser_control.resolution = 0;
	parser_control.npath = 0;
	parser_control.spath = 0;
	parser_control.wpath = 0;
	parser_control.epath = 0;
	parser_control.sprite = 0;
	parser_control.ceiling = 0;
	parser_control.floor = 0;
	return (parser_control);
}

t_keys	keys_init(void)
{
	t_keys	keys;

	keys.w = 0;
	keys.a = 0;
	keys.s = 0;
	keys.d = 0;
	keys.left = 0;
	keys.right = 0;
	return (keys);
}

t_color	color_init(void)
{
	t_color	color;

	color.red = -1;
	color.green = -1;
	color.blue = -1;
	return (color);
}

t_map	map_parcer_init(void)
{
	t_map	map;

	map.width = 0;
	map.height = 0;
	map.npath = NULL;
	map.spath = NULL;
	map.epath = NULL;
	map.wpath = NULL;
	map.sprite = NULL;
	map.floor = color_init();
	map.ceiling = color_init();
	map.str_num = 0;
	map.map = NULL;
	map.sprite_data = NULL;
	map.sprite_num = 0;
	map.bmp_flag = 0;
	map.pacer_size = 0;
	map.parser_control = parser_control_init();
	return (map);
}
