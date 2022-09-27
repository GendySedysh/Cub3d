/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:44:23 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 14:35:36 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"
#include "mlx.h"

int	save_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i != 6)
		return (0);
	if (str[i - 1] == 'e' && str[i - 2] == 'v' && str[i - 3] == 'a'
		&& str[i - 4] == 's' && str[i - 5] == '-' && str[i - 6] == '-')
		return (1);
	return (0);
}

int	ext_check(char *str)
{
	int		i;
	int		dot_count;
	int		flag;

	i = 0;
	flag = 0;
	dot_count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		i++;
	}
	if (str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.')
		flag = 1;
	if (flag == 1 && dot_count == 1)
		return (1);
	return (0);
}

void	parser_valid_check(t_map map_data)
{
	if (map_data.parser_control.resolution != 1)
		paser_free_and_exit("ERROR with RESOLUTION", map_data);
	if (map_data.parser_control.npath != 1)
		paser_free_and_exit("ERROR with NORTH TEXTURE PATH", map_data);
	if (map_data.parser_control.wpath != 1)
		paser_free_and_exit("ERROR with WEST TEXTURE PATH", map_data);
	if (map_data.parser_control.epath != 1)
		paser_free_and_exit("ERROR with EAST TEXTURE PATH", map_data);
	if (map_data.parser_control.spath != 1)
		paser_free_and_exit("ERROR with SOUTH TEXTURE PATH", map_data);
	if (map_data.parser_control.sprite != 1)
		paser_free_and_exit("ERROR with SPRITE TEXTURE PATH", map_data);
	if (map_data.parser_control.ceiling != 1)
		paser_free_and_exit("ERROR with CEILING/FLOOR color", map_data);
	if (map_data.parser_control.floor != 1)
		paser_free_and_exit("ERROR with CEILING/FLOOR color", map_data);
}

void	parcer_free(t_map map_data)
{
	if (map_data.npath)
		free(map_data.npath);
	if (map_data.spath)
		free(map_data.spath);
	if (map_data.wpath)
		free(map_data.wpath);
	if (map_data.epath)
		free(map_data.epath);
	if (map_data.sprite)
		free(map_data.sprite);
	if (map_data.map)
		free_map(map_data);
}

void	close_win(t_vars *vars)
{
	if (vars->texture1.img)
		mlx_destroy_image(vars->mlx, vars->texture1.img);
	if (vars->texture2.img)
		mlx_destroy_image(vars->mlx, vars->texture2.img);
	if (vars->texture3.img)
		mlx_destroy_image(vars->mlx, vars->texture3.img);
	if (vars->texture4.img)
		mlx_destroy_image(vars->mlx, vars->texture4.img);
	if (vars->sprite.img)
		mlx_destroy_image(vars->mlx, vars->sprite.img);
	if (vars->map_data.bmp_flag && vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
}
