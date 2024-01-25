/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:59:03 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/24 13:45:34 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_values(t_data *data)
{
	data->map.coins = 0;
	data->map.exit = 0;
	data->map.players = 0;
	data->map.enemies = 0;
	data->movements = 0;
	data->map.cols = ft_strlen(data->map.all[0]) - 1;
	data->player_sprite = RIGHT;
	data->enemy_sprite = RIGHT;
	data->life = 5;
	data->lm = 0;
}

void	render_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data->mlx_ptr);
		ft_putstr_fd("Couldn't find mlx_ptr.", 1);
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_TITLE);
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		ft_putstr_fd("Couldn't create the window.", 1);
	}
}

void	init_sprites(t_data *data)
{
	void	*mlx;

	mlx = data->mlx_ptr;
	data->wall = ft_sprite(mlx, WALL_XPM);
	data->floor = ft_sprite(mlx, FLOOR_XPM);
	data->coin = ft_sprite(mlx, COIN_XPM);
	data->player_up = ft_sprite(mlx, P_UP_XPM);
	data->player_down = ft_sprite(mlx, P_DOWN_XPM);
	data->player_left = ft_sprite(mlx, P_LEFT_XPM);
	data->player_right = ft_sprite(mlx, P_RIGHT_XPM);
	data->open_exit = ft_sprite(mlx, OPEN_EXIT_XPM);
	data->close_exit = ft_sprite(mlx, CLOSE_EXIT_XPM);
	data->e_left = ft_sprite(mlx, E_LEFT_XPM);
	data->e_right = ft_sprite(mlx, E_RIGHT_XPM);
}

t_img	ft_sprite(void *mlx, char *path)
{
	t_img	sprite;

	sprite.xpm_img = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_img == NULL)
		ft_putstr_fd("Sprite does not exist !", 1);
	return (sprite);
}

void	is_player(t_data *data, int y, int x)
{
	if (data->map.all[y][x] == PLAYER)
		check_life(data);
	return ;
}
