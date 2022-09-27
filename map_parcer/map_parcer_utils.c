/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:14:07 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 16:10:11 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"
#include <stdio.h>

static char	*skip_while_no_num(char *line)
{
	char	c;

	c = '1';
	while (!my_isdigit(*line) && *line)
	{
		if (*line == '-')
			break ;
		c = *line++;
	}
	if (c)
		return (line);
	return (line);
}

static t_map	resolution_check(t_map map, char *line)
{
	char	c;

	while ((*line != 'N' || *line != 'W' || *line != 'S' || *line != 'E'
			|| *line != 'C' || *line != 'F') && *line)
	{
		if (my_isdigit(*line))
			map.parser_control.resolution = 0;
		c = *line++;
	}
	if (map.width <= 0 || map.height <= 0)
		map.parser_control.resolution = 3;
	if (c)
		return (map);
	return (map);
}

t_map	get_resolution(t_map map, char *line)
{
	char	c;

	c = '1';
	while (*line != 'R' && *line)
		c = *line++;
	line = skip_while_no_num(line);
	map.width = my_atoi(line);
	while (my_isdigit(*line) && *line)
		c = *line++;
	if (!(*line))
		return (resolution_check(map, line));
	line = skip_while_no_num(line);
	map.height = my_atoi(line);
	while (my_isdigit(*line) && *line)
		c = *line++;
	if (c)
		return (resolution_check(map, line));
	return (resolution_check(map, line));
}

t_color	get_color(t_color color, char *line)
{
	char	c;

	c = '1';
	line = skip_while_no_num(line);
	color.red = my_atoi(line);
	while (my_isdigit(*line) && *line)
		c = *line++;
	line = skip_while_no_num(line);
	color.green = my_atoi(line);
	while (my_isdigit(*line) && *line)
		c = *line++;
	line = skip_while_no_num(line);
	color.blue = my_atoi(line);
	while (my_isdigit(*line) && *line)
		c = *line++;
	while (*line++)
	{
		if (*line != 32 || *line != '\t' || *line != '\n' || *line != '\0')
			c = '1';
		else
			color.red = -1;
	}
	if (c)
		return (color);
	return (color);
}

char	*get_texture_path(char *line)
{
	char	*str;
	int		k;
	int		i;

	i = 0;
	k = 0;
	while (line[k] != '.')
	{
		if (string_check(line[k]) == 0)
			return (0);
		k++;
	}
	i = k;
	while (my_isprint(line[k]))
		k++;
	str = (char *)malloc(sizeof(char) * (k - i) + 1);
	if (!(str))
		perror_and_exit("Malloc error");
	k = 0;
	while (line[i])
		str[k++] = line[i++];
	str[k] = '\0';
	return (str);
}
