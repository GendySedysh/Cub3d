/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:06:30 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/26 18:06:50 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "map_parcer.h"

unsigned int	color_convert(t_color input_color)
{
	unsigned int	color;

	color = 0 << 24 | (input_color.red << 16)
		| (input_color.green << 8) | (input_color.blue);
	return (color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(int x, int y, t_data *img)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	raycast(t_data img, t_vars *vars, double angle, int x)
{
	t_ray		ray;
	t_ray		prev_ray;
	double		delta_ray;

	ray = cast_ray(vars, angle);
	delta_ray = (double)(((FOV * M_PI / 180) / vars->map_data.width));
	render_ray(img, vars, ray, x);
	prev_ray = cast_ray(vars, angle - delta_ray);
	if (ray.num_of_sprites != 0 && prev_ray.num_of_sprites == 0)
		ft_list_push_front(&vars->sprite_list, x, (int)ray.sprite_len);
}
