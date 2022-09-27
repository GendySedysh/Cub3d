/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:43 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 15:41:04 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

int	check_line_for_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (parcer_check(line[i]) == 0 && my_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static t_map	color_check(t_color color, t_map map_data)
{
	if (color.red > 255 || color.green > 255 || color.blue > 255)
		map_data.parser_control.floor = 3;
	if (color.red < 0 || color.green < 0 || color.blue < 0)
		map_data.parser_control.floor = 3;
	return (map_data);
}

static t_map	fill_map_settings_3(char *line, t_map map_settings, int i)
{
	if (line[i] == 'E')
	{
		if (map_ext_cmp(line, "EA", i))
		{
			map_settings.parser_control.epath += 1;
			map_settings.epath = get_texture_path(line);
		}
	}
	if (line[i] == 'F')
	{
		map_settings.parser_control.floor += 1;
		if (check_line_for_valid(line) == 0)
			map_settings.parser_control.floor += 1;
		map_settings.floor = get_color(map_settings.floor, line);
		map_settings = color_check(map_settings.floor, map_settings);
	}
	if (line[i] == 'C')
	{
		map_settings.parser_control.ceiling += 1;
		if (check_line_for_valid(line) == 0)
			map_settings.parser_control.ceiling += 1;
		map_settings.ceiling = get_color(map_settings.ceiling, line);
		map_settings = color_check(map_settings.ceiling, map_settings);
	}
	return (map_settings);
}

static t_map	fill_map_settings_2(char *line, t_map map_settings, int i)
{
	alien_char_search(line, map_settings);
	if (line[i] == 'S')
	{
		if (map_ext_cmp(line, "SO", i))
		{
			map_settings.parser_control.spath += 1;
			map_settings.spath = get_texture_path(line);
		}
		else if (map_ext_cmp(line, "S ", i))
		{
			map_settings.parser_control.sprite += 1;
			map_settings.sprite = get_texture_path(line);
		}
	}
	if (line[i] == 'W')
	{
		if (map_ext_cmp(line, "WE", i))
		{
			map_settings.parser_control.wpath += 1;
			map_settings.wpath = get_texture_path(line);
		}
	}
	map_settings = fill_map_settings_3(line, map_settings, i);
	return (map_settings);
}

t_map	fill_map_settings(char *line, t_map map_settings)
{
	int	i;

	map_settings.pacer_size++;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
		{
			map_settings.parser_control.resolution += 1;
			if (check_line_for_valid(line) == 0)
				map_settings.parser_control.resolution += 1;
			map_settings = get_resolution(map_settings, line);
		}
		if (line[i] == 'N')
		{
			if (map_ext_cmp(line, "NO", i))
			{
				map_settings.parser_control.npath += 1;
				map_settings.npath = get_texture_path(line);
			}
		}
		map_settings = fill_map_settings_2(line, map_settings, i);
		i++;
	}
	return (map_settings);
}
