/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsteffan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:55:13 by fsteffan          #+#    #+#             */
/*   Updated: 2021/04/26 18:10:02 by fsteffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parcer.h"
#include "mlx.h"

static void	screen_size_check(t_vars *vars)
{
	int	width;
	int	height;

	mlx_get_screen_size(vars->mlx, &width, &height);
	if (vars->map_data.width < 32)
		vars->map_data.width = 32;
	if (vars->map_data.height < 32)
		vars->map_data.height = 32;
	if (vars->map_data.width > width)
		vars->map_data.width = width;
	if (vars->map_data.height > height)
		vars->map_data.height = height;
}

void	do_mlx(t_player player, t_map map)
{
	t_vars	vars;

	vars.player = player;
	vars.map_data = map;
	vars.sprite_list = NULL;
	vars.keys = keys_init();
	vars.mlx = mlx_init();
	screen_size_check(&vars);
	texture_init(&vars);
	if (map.bmp_flag == 1)
		render_screenshot(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.map_data.width,
			vars.map_data.height, "fsteffans Cub3D");
	mlx_hook(vars.win, 17, 1L << 17, exit_normally, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_loop_hook(vars.mlx, ray_caster, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop(vars.mlx);
}

static void	start_engine(t_map map_data, int argc, char **argv)
{
	t_player	player;

	player = player_init();
	player = get_start_data(map_data);
	map_data = map_scale(map_data);
	map_data = put_sprite_on_map(map_data);
	if (argc == 3)
	{
		if (save_check(argv[2]) == 1)
			map_data.bmp_flag = 1;
		else
			perror_and_exit("second argument error");
	}
	delete_list(map_data.sprite_data);
	do_mlx(player, map_data);
}

int	main(int argc, char **argv)
{
	t_map	map_data;

	if (argc == 2 || argc == 3)
	{
		map_data = map_parcer_init();
		if (ext_check(argv[1]) != 1)
			perror_and_exit("map extention error");
		if (argc == 3)
		{
			if (save_check(argv[2]) == 1)
				map_data.bmp_flag = 1;
			else
				perror_and_exit("second argument error");
		}
		map_data = map_read(argv[1]);
		parser_valid_check(map_data);
		map_valid_check(map_data);
		map_data = get_sprite_data(map_data);
		start_engine(map_data, argc, argv);
	}
	else
		perror("wrong number of arguments");
	return (0);
}
