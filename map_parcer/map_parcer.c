/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:57:06 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 15:33:56 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

int	map_ext_cmp(const char *s1, const char *s2, int i)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	color_compare(t_color color1, t_color color2)
{
	if (color1.red != color2.red)
		return (0);
	if (color1.green != color2.green)
		return (0);
	if (color1.blue != color2.blue)
		return (0);
	return (1);
}

t_map	parce_map_settings(char *line, t_map map_settings, int fd)
{
	int		rd;

	rd = get_next_line(fd, &line);
	while (rd > 0)
	{
		map_settings = fill_map_settings(line, map_settings);
		free(line);
		if (parser_fill_check(map_settings))
			map_settings.str_num++;
		rd = get_next_line(fd, &line);
	}
	if (rd == 0)
	{
		map_settings = fill_map_settings(line, map_settings);
		free(line);
	}
	map_settings.pacer_size -= map_settings.str_num;
	map_settings.str_num += map_settings.pacer_size;
	return (map_settings);
}

t_map	map_malloc_and_save(t_map map_settings, int fd, char *line)
{
	char	**map;
	int		rd;
	int		i;

	i = 1;
	map = (char **)malloc(sizeof(char *) * (map_settings.str_num + 1));
	if (!(map))
		perror_and_exit("Malloc error");
	map[0] = ft_strdup(line);
	free(line);
	rd = get_next_line(fd, &line);
	while (rd > 0)
	{
		map[i++] = ft_strdup(line);
		free(line);
		rd = get_next_line(fd, &line);
	}
	if (rd == 0)
	{
		if (i < map_settings.str_num)
			map[i++] = ft_strdup(line);
		free(line);
	}
	map_settings.map = map;
	return (map_settings);
}

t_map	map_read(const char *map_path)
{
	int		fd;
	t_map	map_settings;
	char	*line;
	int		i;

	i = 0;
	map_settings = map_parcer_init();
	fd = open(map_path, O_RDONLY);
	if (fd > 0)
		map_settings = parce_map_settings(line, map_settings, fd);
	else
		paser_free_and_exit(".cub file error", map_settings);
	close(fd);
	parser_valid_check(map_settings);
	fd = open(map_path, O_RDONLY);
	get_next_line(fd, &line);
	while (i < map_settings.pacer_size || !my_isprint(line[0]))
	{
		free(line);
		get_next_line(fd, &line);
		i++;
	}
	map_settings.str_num -= i;
	return (map_malloc_and_save(map_settings, fd, line));
}
