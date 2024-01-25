/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:02:20 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/24 13:52:11 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	render_enemy(t_data *data, int y, int x)
{
	if (data->enemy_sprite == LEFT)
		render_sprite(data, data->e_left, y, x);
	else
		render_sprite(data, data->e_right, y, x);
}

void	check_enemy(t_data *data, int y, int x)
{
	if (data->enemy_sprite == RIGHT && (data->map.all[y][x + 1] == WALL
		|| data->map.all[y][x + 1] == EXIT || data->map.all[y][x + 1] == COIN
		|| data->map.all[y][x + 1] == PLAYER))
	{
		is_player(data, y, x + 1);
		data->enemy_sprite = LEFT;
		render_enemy(data, y, x);
	}
	else if (data->enemy_sprite == LEFT && (data->map.all[y][x - 1] == WALL
		|| data->map.all[y][x - 1] == EXIT || data->map.all[y][x - 1] == COIN
		|| data->map.all[y][x - 1] == PLAYER))
	{
		is_player(data, y, x - 1);
		data->enemy_sprite = RIGHT;
		render_enemy(data, y, x);
	}
	else
		enemy_move(data, y, x);
}

void	enemy_pos(t_data *data)
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
			{
				data->map.enemy.x = x;
				data->map.enemy.y = y;
			}
			x++;
		}
		y++;
	}
}

void	enemy_move(t_data *data, int y, int x)
{
	int	last_x;
	int	last_y;

	enemy_pos(data);
	last_x = data->map.enemy.x;
	last_y = data->map.enemy.y;
	if (data->enemy_sprite == LEFT)
	{
		data->map.all[last_y][last_x] = FLOOR;
		render_sprite(data, data->floor, last_y, last_x);
		data->map.enemy.x = x - 1;
		data->map.enemy.y = y;
		data->map.all[y][x - 1] = ENEMY;
		render_sprite(data, data->e_left, y, x - 1);
	}
	else if (data->enemy_sprite == RIGHT)
	{
		data->map.all[last_y][last_x] = FLOOR;
		render_sprite(data, data->floor, last_y, last_x);
		data->map.enemy.x = x + 1;
		data->map.enemy.y = y;
		data->map.all[y][x + 1] = ENEMY;
		render_sprite(data, data->e_right, y, x + 1);
	}
}

int	render_enemy_map(t_data *data)
{
	static int	i;

	if (i == 100)
	{
		print_life(data);
		enemy_pos(data);
		if (data->map.enemy.x == 0 && data->map.enemy.y == 0)
			return (0);
		check_enemy(data, data->map.enemy.y, data->map.enemy.x);
	}
	if (i == 200000)
		i = 0;
	i++;
	return (0);
}
