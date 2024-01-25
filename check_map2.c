/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:14:01 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/22 16:45:04 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_pos_params(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map.rows)
	{
		x = -1;
		while (++x < data->map.cols)
		{
			if (data->map.all[y][x] == COIN || data->map.all[y][x] == PLAYER
				|| data->map.all[y][x] == ENEMY || data->map.all[y][x] == EXIT)
			{
				if (data->map.all[y + 1][x] == WALL
					&& data->map.all[y][x + 1] == WALL
					&& data->map.all[y - 1][x] == WALL
					&& data->map.all[y][x - 1] == WALL)
				{
					ft_putstr_fd("Error. Sprite surrounded by walls.", 1);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}

int	check_rectangle(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
	{
		if (ft_strlen(data->map.all[i]) != ft_strlen(data->map.all[0]))
			return (ft_putstr_fd("Map is not a rectangle !", 1), 0);
		i++;
	}
	return (1);
}

int	find_player(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.cols)
		{
			if (data->map.all[y][x] == PLAYER)
			{
				data->map.player.x = x;
				data->map.player.y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_pos	*ft_lstnew2(int y, int x)
{
	t_pos	*new;

	new = malloc(sizeof(t_pos));
	if (!new)
		return (NULL);
	new->y = y;
	new->x = x;
	new->next = NULL;
	return (new);
}

int	check_path(t_data *data)
{
	t_pos	*case_possible;
	int		y;
	int		x;

	find_player(data);
	y = data->map.player.y;
	x = data->map.player.x;
	case_possible = ft_lstnew2(y, x);
	if (!case_possible)
		return (0);
	ft_get_case_possible(data, y, x, &case_possible);
	if (ft_find_case(data, case_possible, 'E') == 0)
		return (ft_free_list(case_possible), 0);
	if (ft_nb_coins(data) != ft_find_case(data, case_possible, 'C'))
		return (ft_free_list(case_possible), 0);
	return (ft_free_list(case_possible), 1);
}
