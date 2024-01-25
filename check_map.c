/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:28:39 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/22 16:48:05 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_data *data)
{
	check_rows(data);
	check_cols(data);
	if (check_rectangle(data) == 0)
		exit(EXIT_FAILURE);
	if (count_params(data) == 0)
		exit(EXIT_FAILURE);
	verif_params(data);
	check_pos_params(data);
	if (check_path(data) == 0)
	{
		ft_putstr_fd("Player must have access to all the \
collectibles and the exit !", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_rows(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
	{
		if (data->map.all[i][0] != WALL)
		{
			ft_putstr_fd("Invalid map", 1);
			exit(EXIT_FAILURE);
		}
		else if (data->map.all[i][data->map.cols] != WALL)
		{
			ft_putstr_fd("Invalid map", 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_cols(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.cols)
	{
		if (data->map.all[0][i] != WALL)
		{
			ft_putstr_fd("Invalid map", 1);
			exit(EXIT_FAILURE);
		}
		else if (data->map.all[data->map.rows - 1][i] != WALL)
		{
			ft_putstr_fd("Invalid map", 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}

}

int	count_params(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map.rows)
	{
		x = -1;
		while (++x < data->map.cols)
		{
			if (!ft_strchr("CEPW01", data->map.all[y][x]))
				return (ft_putstr_fd("Parameter not expected.", 1), 0);
			else if (data->map.all[y][x] == PLAYER)
			{
				data->map.players++;
				data->map.player.x = x;
				data->map.player.y = y;
			}
			else if (data->map.all[y][x] == COIN)
				data->map.coins++;
			else if (data->map.all[y][x] == EXIT)
				data->map.exit++;
		}
	}
	return (1);
}

void	verif_params(t_data *data)
{
	if (data->map.coins == 0)
	{
		ft_putstr_fd("Invalid map. There are no coins !", 1);
		exit(EXIT_FAILURE);
	}
	else if (data->map.exit == 0)
	{
		ft_putstr_fd("Invalid map. There is no exit !", 1);
		exit(EXIT_FAILURE);
	}
	else if (data->map.exit > 1)
	{
		ft_putstr_fd("Invalid map. There is not only one exit !", 1);
		exit(EXIT_FAILURE);
	}
	else if (data->map.players != 1)
	{
		ft_putstr_fd("Invalid map. Only one player required !", 1);
		exit(EXIT_FAILURE);
	}
	else if (data->map.enemies > 1)
	{
		ft_putstr_fd("Invalid map. Only one enemy required !", 1);
		exit(EXIT_FAILURE);
	}
}
