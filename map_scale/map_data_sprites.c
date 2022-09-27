/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:25:55 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 15:29:28 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

t_map	put_sprite_on_map(t_map map)
{
	t_sprite	*ptr;

	ptr = map.sprite_data;
	while (ptr)
	{
		map.map[ptr->y][ptr->x] = '2';
		ptr = ptr->next;
	}
	return (map);
}

int	sprite_number(t_map map)
{
	int	i;
	int	j;
	int	out;

	out = 0;
	i = 0;
	while (i < map.str_num)
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '2')
				out++;
			j++;
		}
		i++;
	}
	return (out);
}

t_map	get_sprite_data(t_map map)
{
	int			i;
	int			j;
	t_sprite	*ptr;

	map.sprite_num = sprite_number(map);
	ptr = NULL;
	i = 0;
	while (i < map.str_num)
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '2')
			{
				ft_list_push_front(&ptr, j * SCALE + SCALE / 2,
					i * SCALE + SCALE / 2);
			}
			j++;
		}
		i++;
	}
	map.sprite_data = ptr;
	return (map);
}
