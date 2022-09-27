/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:48:07 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 15:25:50 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

void	free_map(t_map m_d)
{
	int		i;

	i = 0;
	while (i < m_d.str_num)
	{
		free(m_d.map[i]);
		i++;
	}
	free(m_d.map);
}

static int	*map_size(t_map m_d)
{
	int	*int_map;
	int	j;
	int	k;

	k = 0;
	int_map = (int *)malloc(m_d.str_num * sizeof(int));
	if (!(int_map))
		perror_and_exit("Malloc error");
	while (k < m_d.str_num)
	{
		j = 0;
		while (m_d.map[k][j])
			j++;
		int_map[k] = j;
		k++;
	}
	return (int_map);
}

static char	*malloc_map_string(int i, int *int_map)
{
	int		j;
	char	*new_map;

	j = 0;
	new_map = (char *)malloc((sizeof(char) * int_map[i / 32] * 32) + 1);
	if (!(new_map))
		perror_and_exit("Malloc error");
	while (j < int_map[i / SCALE] * SCALE)
	{
		new_map[j] = 'k';
		j++;
	}
	new_map[j] = '\0';
	return (new_map);
}

char	**malloc_map(int *int_map, t_map m_d)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (m_d.str_num * SCALE) + 1);
	if (!(new_map))
		perror_and_exit("Malloc error");
	i = 0;
	while (i < m_d.str_num * SCALE)
	{
		new_map[i] = malloc_map_string(i, int_map);
		i++;
	}
	free(int_map);
	return (new_map);
}

t_map	map_scale(t_map m_d)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	new_map = malloc_map(map_size(m_d), m_d);
	if (!(new_map))
		perror_and_exit("Malloc error");
	while (i < (m_d.str_num) * SCALE)
	{
		j = 0;
		while (new_map[i][j++])
		{
			if (nswe_check(m_d.map[i / 32][j / 32]))
				new_map[i][j] = '0';
			else
				new_map[i][j] = m_d.map[i / 32][j / 32];
		}
		i++;
	}
	free_map(m_d);
	m_d.map = new_map;
	m_d.str_num = m_d.str_num * SCALE;
	return (m_d);
}
