/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:15:14 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/26 18:07:07 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

t_ray	flag_for_ray(t_ray ray, t_vars *vars)
{
	double	d_s;

	if (vars->map_data.map[(int)ray.y_ray + 1][(int)ray.x_ray] != '1')
		ray.flag = 1;
	else if (vars->map_data.map[(int)ray.y_ray - 1][(int)ray.x_ray] != '1')
		ray.flag = 2;
	else if (vars->map_data.map[(int)ray.y_ray][(int)ray.x_ray + 1] != '1')
		ray.flag = 3;
	else if (vars->map_data.map[(int)ray.y_ray][(int)ray.x_ray - 1] != '1')
		ray.flag = 4;
	if (ray.flag == 1 || ray.flag == 2)
		d_s = ray.x_ray;
	else
		d_s = ray.y_ray;
	ray.s = d_s;
	return (ray);
}

t_ray	cast_ray(t_vars *vars, double angle)
{
	t_ray	ray;
	double	i;

	i = 0;
	ray = ray_init();
	ray.angle = angle;
	ray.x_ray = vars->player.x;
	ray.y_ray = vars->player.y;
	while (vars->map_data.map[(int)ray.y_ray][(int)ray.x_ray] != '1')
	{
		if (vars->map_data.map[(int)ray.y_ray][(int)ray.x_ray] == '2')
		{
			if (ray.num_of_sprites == 0)
				ray.sprite_len = i;
			ray.num_of_sprites++;
		}
		ray.x_ray = (vars->player.x + (i * cos(angle)));
		ray.y_ray = (vars->player.y + (i * sin(angle)));
		i += 0.05;
	}
	ray.len = i;
	ray = flag_for_ray(ray, vars);
	return (ray);
}

static t_player	start_data_utils(char c, int i, int j)
{
	t_player	player;

	player = player_init();
	player.x = j * SCALE;
	player.y = i * SCALE;
	if (c == 'N')
		player.pov = 0 * M_PI / 180;
	if (c == 'S')
		player.pov = 180 * M_PI / 180;
	if (c == 'W')
		player.pov = 270 * M_PI / 180;
	if (c == 'E')
		player.pov = 90 * M_PI / 180;
	return (player);
}

t_player	get_start_data(t_map m_d)
{
	int			i;
	int			j;
	t_player	player;

	i = 0;
	player = player_init();
	while (i < m_d.str_num)
	{
		j = 0;
		while (m_d.map[i][j])
		{
			if (m_d.map[i][j] == 'N' || m_d.map[i][j] == 'S' ||
				m_d.map[i][j] == 'W' || m_d.map[i][j] == 'E')
				player = start_data_utils(m_d.map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (player);
}
