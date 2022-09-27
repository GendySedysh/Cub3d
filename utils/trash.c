/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:53:25 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 15:15:08 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

int	parser_fill_check(t_map map_data)
{
	if (map_data.parser_control.resolution < 1)
		return (0);
	if (map_data.parser_control.npath < 1)
		return (0);
	if (map_data.parser_control.wpath < 1)
		return (0);
	if (map_data.parser_control.epath < 1)
		return (0);
	if (map_data.parser_control.spath < 1)
		return (0);
	if (map_data.parser_control.sprite < 1)
		return (0);
	if (map_data.parser_control.ceiling < 1)
		return (0);
	if (map_data.parser_control.floor < 1)
		return (0);
	return (1);
}

void	map_chars_check(t_map map_data, int i, int j)
{
	int	x;

	x = 0;
	while (map_data.map[i][j])
	{
		if (map_char_check(map_data.map[i][j]) == 0)
			x = paser_free_and_exit("Invalid map | Alien character", map_data);
		j++;
	}
	if (x)
		return ;
}

int	map_char_check(char c)
{
	if (c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == '0' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	string_check(char c)
{
	if (c == ' ' || c == '\t' || c == 'N' || c == 'O' || c == 'E'
		|| c == 'W' || c == 'A' || c == 'S' || c == 'R' || c == 'C'
		|| c == 'F' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int	parcer_check(char c)
{
	if (c == 'R' || c == 'W' || c == 'S' || c == 'E' || c == 'N'
		|| c == 'F' || c == 'C' || c == ' ' || c == '\t' || c == ',')
		return (1);
	return (0);
}
