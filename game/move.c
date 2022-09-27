/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:23:37 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/23 18:45:50 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

static void	move_w_s(t_vars *vars)
{
	if (vars->keys.w == 1)
	{
		vars->player.x = (int)(vars->player.x
				+ (SPEED * cos(vars->player.pov)));
		vars->player.y = (int)(vars->player.y
				+ (SPEED * sin(vars->player.pov)));
	}
	if (vars->keys.s == 1)
	{
		vars->player.x = (int)(vars->player.x
				- (SPEED * cos(vars->player.pov)));
		vars->player.y = (int)(vars->player.y
				- (SPEED * sin(vars->player.pov)));
	}
}

static void	move_a_d(t_vars *vars)
{
	if (vars->keys.a == 1)
	{
		vars->player.x = (int)(vars->player.x + (STRAFE_SPEED
					* cos(vars->player.pov - (M_PI / 2))));
		vars->player.y = (int)(vars->player.y + (STRAFE_SPEED
					* sin(vars->player.pov - (M_PI / 2))));
	}
	if (vars->keys.d == 1)
	{
		vars->player.x = (int)(vars->player.x + (STRAFE_SPEED
					* cos(vars->player.pov + (M_PI / 2))));
		vars->player.y = (int)(vars->player.y + (STRAFE_SPEED
					* sin(vars->player.pov + (M_PI / 2))));
	}
}

static void	move_rotate(t_vars *vars)
{
	if (vars->keys.left == 1)
		vars->player.pov -= ROTATE_SPEED * M_PI / 180;
	if (vars->keys.right == 1)
		vars->player.pov += ROTATE_SPEED * M_PI / 180;
}

void	move(t_vars *vars)
{
	int	c;

	c = '1';
	move_w_s(vars);
	move_a_d(vars);
	move_rotate(vars);
	if (vars->map_data.map[vars->player.y][vars->player.x] == '1')
	{
		c = write(1, "Game over, wall is a LAVA\n", 26);
		exit_normally(vars);
	}
	if (c)
		return ;
}
