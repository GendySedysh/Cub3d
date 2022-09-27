/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:37:21 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/27 21:48:07 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "map_parcer.h"

void	render_ray(t_data img, t_vars *vars, t_ray ray, int x)
{
	int			height_to_draw;
	int			start_draw;
	int			i;

	height_to_draw = SCALE * (vars->map_data.height / (ray.len
				* cos(ray.angle - vars->player.pov)));
	if (height_to_draw >= vars->map_data.height)
		height_to_draw = vars->map_data.height;
	start_draw = vars->map_data.height / 2;
	render_texture(img, ray, vars, x);
	i = 0;
	while (i < (start_draw - height_to_draw / 2))
	{
		my_mlx_pixel_put(&img, x, i, color_convert(vars->map_data.ceiling));
		i++;
	}
	i = start_draw + height_to_draw / 2;
	while (i < vars->map_data.height)
	{
		my_mlx_pixel_put(&img, x, i, color_convert(vars->map_data.floor));
		i++;
	}
}

void	multiple_raycasting(t_data img, t_vars *vars)
{
	double	angle;
	double	delta_ray;
	int		x;

	angle = vars->player.pov - ((FOV / 2) * M_PI / 180);
	delta_ray = (double)(((FOV * M_PI / 180) / vars->map_data.width));
	x = 0;
	while (angle < vars->player.pov && x < vars->map_data.width)
	{
		raycast(img, vars, angle, x);
		angle += delta_ray;
		x++;
	}
	angle = vars->player.pov;
	while (angle < (vars->player.pov + ((FOV / 2) * M_PI / 180))
		&& x < vars->map_data.width - 1)
	{
		raycast(img, vars, angle, x);
		angle += delta_ray;
		x++;
	}
}

void	render_sprite_2(t_data img, t_vars *vars, int j, int sprite_height)
{
	int				i;
	int				new_x;
	t_ray			wall_check_ray;
	unsigned int	color;

	i = 0;
	new_x = (vars->sprite_list->x - sprite_height / 2) + j;
	wall_check_ray = cast_ray(vars, (vars->player.pov - ((FOV / 2) * M_PI
					/ 180)) + (new_x * ((double)(((FOV * M_PI
								/ 180) / vars->map_data.width)))));
	while (i < sprite_height)
	{
		if (wall_check_ray.len + 32 > vars->sprite_list->y)
		{
			color = get_pixel_color((j * 64 / sprite_height),
					(i * 64 / sprite_height), &vars->sprite);
			if (color != 0 && new_x >= 0 && new_x <= vars->map_data.width)
				my_mlx_pixel_put(&img, new_x, (vars->map_data.height / 2
						- sprite_height / 2) + i, color);
		}
		i++;
	}
}

void	render_sprite(t_data img, t_vars *vars)
{
	double		delta_ray;
	double		angle;
	int			sprite_height;
	int			j;
	t_sprite	*tmp;

	angle = vars->player.pov - ((FOV / 2) * M_PI / 180);
	delta_ray = (double)(((FOV * M_PI / 180) / vars->map_data.width));
	while (vars->sprite_list)
	{
		tmp = vars->sprite_list;
		sprite_height = SCALE * (vars->map_data.height / (vars->sprite_list->y
					* cos((angle + delta_ray * vars->sprite_list->x)
						- vars->player.pov)));
		if (sprite_height > vars->map_data.height)
			sprite_height = vars->map_data.height;
		j = 0;
		while (j < sprite_height)
		{
			render_sprite_2(img, vars, j, sprite_height);
			j++;
		}
		vars->sprite_list = vars->sprite_list->next;
		free(tmp);
	}
}

int	ray_caster(t_vars *vars)
{
	t_data		new_img;

	move(vars);
	vars->sprite_list = NULL;
	new_img.img = mlx_new_image(vars->mlx, vars->map_data.width,
			vars->map_data.height);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	multiple_raycasting(new_img, vars);
	vars->sprite_list = sort(vars->sprite_list);
	render_sprite(new_img, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, new_img.img, 0, 0);
	mlx_destroy_image(vars->mlx, new_img.img);
	return (0);
}
