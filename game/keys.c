/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:21:07 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/20 20:33:30 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307 || keycode == 33)
		exit_normally(vars);
	if (keycode == 97)
		vars->keys.a = 1;
	if (keycode == 119)
		vars->keys.w = 1;
	if (keycode == 115)
		vars->keys.s = 1;
	if (keycode == 100)
		vars->keys.d = 1;
	if (keycode == 65361)
		vars->keys.left = 1;
	if (keycode == 65363)
		vars->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 97)
		vars->keys.a = 0;
	if (keycode == 119)
		vars->keys.w = 0;
	if (keycode == 115)
		vars->keys.s = 0;
	if (keycode == 100)
		vars->keys.d = 0;
	if (keycode == 65361)
		vars->keys.left = 0;
	if (keycode == 65363)
		vars->keys.right = 0;
	return (0);
}
