/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:05:27 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/27 15:28:50 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

static void	render_texture_1(t_data img, t_ray ray, t_vars *vars, int x)
{
	int				i;
	int				j;
	int				y;
	int				texture_height;
	unsigned int	color;

	texture_height = SCALE * (vars->map_data.height / (ray.len
				* cos(ray.angle - vars->player.pov)));
	if (texture_height >= vars->map_data.height)
		texture_height = vars->map_data.height;
	y = (vars->map_data.height / 2) - (texture_height / 2);
	i = 0;
	while (i < texture_height)
	{
		j = ((i * SCALE) / texture_height) - (((int)ray.x_ray) / SCALE);
		color = get_pixel_color(ray.s, j, &vars->texture3);
		my_mlx_pixel_put(&img, x, y + i, color);
		i++;
	}
}

static void	render_texture_2(t_data img, t_ray ray, t_vars *vars, int x)
{
	int				i;
	int				j;
	int				y;
	int				texture_height;
	unsigned int	color;

	texture_height = SCALE * (vars->map_data.height / (ray.len
				* cos(ray.angle - vars->player.pov)));
	if (texture_height >= vars->map_data.height)
		texture_height = vars->map_data.height;
	y = (vars->map_data.height / 2) - (texture_height / 2);
	i = 0;
	while (i < texture_height)
	{
		j = ((i * SCALE) / texture_height) - (((int)ray.x_ray) / SCALE);
		color = get_pixel_color(ray.s, j, &vars->texture2);
		my_mlx_pixel_put(&img, x, y + i, color);
		i++;
	}
}

static void	render_texture_3(t_data img, t_ray ray, t_vars *vars, int x)
{
	int				i;
	int				j;
	int				y;
	int				texture_height;
	unsigned int	color;

	texture_height = SCALE * (vars->map_data.height / (ray.len
				* cos(ray.angle - vars->player.pov)));
	if (texture_height >= vars->map_data.height)
		texture_height = vars->map_data.height;
	y = (vars->map_data.height / 2) - (texture_height / 2);
	i = 0;
	while (i < texture_height)
	{
		j = ((i * SCALE) / texture_height) - (((int)ray.y_ray) / SCALE);
		color = get_pixel_color(ray.s, j, &vars->texture4);
		my_mlx_pixel_put(&img, x, y + i, color);
		i++;
	}
}

static void	render_texture_4(t_data img, t_ray ray, t_vars *vars, int x)
{
	int				i;
	int				j;
	int				y;
	int				texture_height;
	unsigned int	color;

	texture_height = SCALE * (vars->map_data.height / (ray.len
				* cos(ray.angle - vars->player.pov)));
	if (texture_height >= vars->map_data.height)
		texture_height = vars->map_data.height;
	y = (vars->map_data.height / 2) - (texture_height / 2);
	i = 0;
	while (i < texture_height)
	{
		j = ((i * SCALE) / texture_height) - (((int)ray.y_ray) / SCALE);
		color = get_pixel_color(ray.s, j, &vars->texture1);
		my_mlx_pixel_put(&img, x, y + i, color);
		i++;
	}
}

void	render_texture(t_data img, t_ray ray, t_vars *vars, int x)
{
	if (ray.flag == 1)
		render_texture_1(img, ray, vars, x);
	if (ray.flag == 2)
		render_texture_2(img, ray, vars, x);
	if (ray.flag == 3)
		render_texture_3(img, ray, vars, x);
	if (ray.flag == 4)
		render_texture_4(img, ray, vars, x);
}
