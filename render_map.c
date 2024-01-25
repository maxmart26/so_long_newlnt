/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:50:00 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/24 13:52:42 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	which_sprite(t_data *data, int y, int x)
{
	char	px;

	px = data->map.all[y][x];
	if (px == WALL)
		render_sprite(data, data->wall, y, x);
	else if (px == FLOOR)
		render_sprite(data, data->floor, y, x);
	else if (px == COIN)
		render_sprite(data, data->coin, y, x);
	else if (px == EXIT)
	{
		if (data->map.coins == 0)
			render_sprite(data, data->open_exit, y, x);
		else
			render_sprite(data, data->close_exit, y, x);
	}
	else if (px == PLAYER)
		render_player(data, y, x);
	else if (px == ENEMY)
		render_enemy(data, y, x);
}

void	render_player(t_data *data, int y, int x)
{
	if (data->player_sprite == UP)
		render_sprite(data, data->player_up, y, x);
	else if (data->player_sprite == DOWN)
		render_sprite(data, data->player_down, y, x);
	else if (data->player_sprite == LEFT)
		render_sprite(data, data->player_left, y, x);
	else if (data->player_sprite == RIGHT)
		render_sprite(data, data->player_right, y, x);
}

void	render_sprite(t_data *data, t_img sprite, int y, int x)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite.xpm_img,
		x * sprite.x, y * sprite.y);
}

void	print_movements(t_data *data)
{
	char	*movements;
	char	*str;

	movements = ft_itoa(data->movements);
	str = ft_strjoin("Movements : ", movements);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 40, 20, 99999999, str);
	free(movements);
	free(str);
}

int	render_map(t_data *data)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x <= data->map.cols)
		{
			which_sprite(data, y, x);
			x++;
		}
		y++;
	}
	print_movements(data);
	print_life(data);
	return (0);
}
