/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 09:56:19 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/24 22:54:48 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

int	check_map_chars(char **map, int i, int j)
{
	if (map[i][j] && (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == '2'
		|| map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
		|| map[i][j] == 'W'))
		return (1);
	return (0);
}

int	check_space_near_o(t_map map_data, int i, int j)
{
	if ((check_map_chars(map_data.map, i - 1, j - 1)) == 0)
		paser_free_and_exit("Invalid map", map_data);
	if ((check_map_chars(map_data.map, i - 1, j) == 0))
		paser_free_and_exit("Invalid map", map_data);
	if ((check_map_chars(map_data.map, i - 1, j + 1)) == 0)
		paser_free_and_exit("Invalid map", map_data);
	if ((check_map_chars(map_data.map, i, j - 1) == 0))
		paser_free_and_exit("Invalid map", map_data);
	if ((check_map_chars(map_data.map, i, j + 1) == 0))
		paser_free_and_exit("Invalid map", map_data);
	if ((check_map_chars(map_data.map, i + 1, j - 1)) == 0)
		paser_free_and_exit("Invalid map", map_data);
	if ((check_map_chars(map_data.map, i + 1, j) == 0))
		paser_free_and_exit("Invalid map", map_data);
	if ((check_map_chars(map_data.map, i + 1, j + 1)) == 0)
		paser_free_and_exit("Invalid map", map_data);
	return (1);
}

int	map_string_begin_check(t_map map_data, int i, int j)
{
	int		flag;

	flag = 0;
	if (map_data.map[i][j] != '1')
	{
		if (map_data.map[i][j] == ' ' || map_data.map[i][j] == '\t')
		{
			while (map_data.map[i][j])
			{
				if (map_data.map[i][j] == '1')
					flag++;
				j++;
			}
			if (flag >= 1)
				return (1);
		}
		else
			paser_free_and_exit("Invalid map | Begin of the string", map_data);
	}
	return (1);
}

int	map_str_check(int i, t_map map_data)
{
	int		j;
	int		player_count;

	j = 0;
	player_count = 0;
	while (map_data.map[i][j])
	{
		if (map_data.map[i][j] == '0' || map_data.map[i][j] == '2')
			check_space_near_o(map_data, i, j);
		if (map_data.map[i][j] == 'N' || map_data.map[i][j] == 'S' ||
			map_data.map[i][j] == 'W' || map_data.map[i][j] == 'E')
		{
			player_count++;
			check_space_near_o(map_data, i, j);
		}
		j++;
	}
	return (player_count);
}

int	map_valid_check(t_map map_data)
{
	int		i;
	int		player_count;

	player_count = 0;
	i = 0;
	while (i < map_data.str_num)
	{
		map_string_begin_check(map_data, i, 0);
		map_chars_check(map_data, i, 0);
		player_count += map_str_check(i, map_data);
		i++;
	}
	if (player_count != 1)
		paser_free_and_exit("Invalid map | Player error", map_data);
	return (1);
}
