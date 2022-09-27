/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:39:45 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/25 14:35:15 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"

int	perror_and_exit(char *str)
{
	perror(str);
	exit(0);
}

int	paser_free_and_exit(char *str, t_map map_data)
{
	perror(str);
	parcer_free(map_data);
	exit(0);
}

int	exit_normally(t_vars *vars)
{
	delete_list(vars->sprite_list);
	parcer_free(vars->map_data);
	close_win(vars);
	exit(0);
}

int	exit_with_error(char *str, t_vars *vars, int flag)
{
	perror(str);
	delete_list(vars->sprite_list);
	parcer_free(vars->map_data);
	if (flag == 1)
		close_win(vars);
	exit(0);
}
