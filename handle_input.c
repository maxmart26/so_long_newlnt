/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:41:12 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/21 18:03:29 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_data *data)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		player_move(data, data->map.player.y - 1, data->map.player.x, UP);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		player_move(data, data->map.player.y + 1, data->map.player.x, DOWN);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		player_move(data, data->map.player.y, data->map.player.x - 1, LEFT);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		player_move(data, data->map.player.y, data->map.player.x + 1, RIGHT);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		close_window(data);
	return (0);
}

void	player_move(t_data *data, int y, int x, int player_sprite)
{
	int	last_x;
	int	last_y;

	data->player_sprite = player_sprite;
	last_x = data->map.player.x;
	last_y = data->map.player.y;
	if (data->map.all[y][x] == EXIT && data->map.coins == 0)
		close_window(data);
	else if (data->map.all[y][x] == ENEMY)
		check_life(data);
	else if ((data->map.all[y][x] == FLOOR) || (data->map.all[y][x] == COIN))
	{
		data->map.all[last_y][last_x] = FLOOR;
		if (data->map.all[y][x] == COIN)
			data->map.coins--;
		data->map.player.x = x;
		data->map.player.y = y;
		data->map.all[y][x] = PLAYER;
		data->movements++;
	}
	render_map(data);
}

void	check_life(t_data *data)
{
	if (data->life > 0)
	{
		data->life--;
		return ;
	}
	close_window(data);
}

void	print_life(t_data *data)
{
	char	*life;
	char	*str;

	life = ft_itoa(data->life);
	str = ft_strjoin("Life : ", life);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 200, 20, 99999999, str);
	free(life);
	free(str);
}
