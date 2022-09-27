/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:05:02 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 15:46:09 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

void	alien_char_search(char *line, t_map map_settings)
{
	int	i;

	i = 0;
	if (parser_fill_check(map_settings) == 0)
	{
		while (line[i] == ' ')
			i++;
		if (string_check(line[i]) == 0)
			paser_free_and_exit("Alien char in parcer", map_settings);
	}
}

static void	fill_bmp_header(int fd, t_vars *vars)
{
	int			tmp;
	int			ret;

	tmp = 0x42;
	ret = write(fd, &tmp, 1);
	tmp = 0x4D;
	ret = write(fd, &tmp, 1);
	tmp = (vars->map_data.height * vars->map_data.width) * 4 + 14 + 40;
	ret = write(fd, &tmp, 4);
	tmp = 0;
	ret = write(fd, &tmp, 2);
	ret = write(fd, &tmp, 2);
	tmp = 54;
	ret = write(fd, &tmp, 4);
	if (ret < 0)
		return ;
}

static void	fill_dib_header(int fd, t_vars *vars)
{
	int			tmp;
	int			ret;

	tmp = 40;
	ret = write(fd, &tmp, 4);
	tmp = vars->map_data.width;
	ret = write(fd, &tmp, 4);
	tmp = vars->map_data.height;
	ret = write(fd, &tmp, 4);
	tmp = 1;
	ret = write(fd, &tmp, 2);
	tmp = 32;
	ret = write(fd, &tmp, 2);
	tmp = 0;
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	if (ret < 0)
		return ;
}

void	pic_export(t_vars *vars)
{
	int			fd;
	int			x;
	int			y;
	int			tmp;

	fd = open("cub3d.bmp", O_RDWR | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
	fill_bmp_header(fd, vars);
	fill_dib_header(fd, vars);
	y = vars->map_data.height - 1;
	while (y > -1)
	{
		x = 0;
		while (x < vars->map_data.width)
		{
			tmp = get_pixel_color(x, y, &vars->img);
			if (write(fd, &tmp, 4) < 0)
				return ;
			x++;
		}
		y--;
	}
}
