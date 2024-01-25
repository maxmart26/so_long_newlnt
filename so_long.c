/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:34:27 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/21 18:00:37 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_enemy(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.cols)
		{
			if (data->map.all[y][x] == ENEMY)
				data->map.enemies++;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	data = malloc(sizeof(t_data));
	check_args(argc, argv);
	map_init(data, argv[1]);
	init_values(data);
	is_enemy(data);
	check_map(data);
	render_window(data);
	init_sprites(data);
	render_map(data);
	mlx_loop_hook(data->mlx_ptr, render_enemy_map, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, close_window, data);
	mlx_loop(data->mlx_ptr);
	free_all(data);
}
