/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:46:35 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/22 16:47:18 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_case_possible(t_data *data, int y, int x, t_pos **case_possible)
{
	if (data->map.all[y][x - 1] != WALL
		&& ft_is_new(*case_possible, y, x - 1) == 1)
	{
		ft_lstadd_back2(case_possible, ft_lstnew2(y, x - 1));
		ft_get_case_possible(data, y, x - 1, case_possible);
	}
	if (data->map.all[y + 1][x] != WALL
		&& ft_is_new(*case_possible, y + 1, x) == 1)
	{
		ft_lstadd_back2(case_possible, ft_lstnew2(y + 1, x));
		ft_get_case_possible(data, y + 1, x, case_possible);
	}
	if (data->map.all[y - 1][x] != WALL
		&& ft_is_new(*case_possible, y - 1, x) == 1)
	{
		ft_lstadd_back2(case_possible, ft_lstnew2(y - 1, x));
		ft_get_case_possible(data, y - 1, x, case_possible);
	}
	if (data->map.all[y][x + 1] != WALL
		&& ft_is_new(*case_possible, y, x + 1) == 1)
	{
		ft_lstadd_back2(case_possible, ft_lstnew2(y, x + 1));
		ft_get_case_possible(data, y, x + 1, case_possible);
	}
}

int	ft_find_case(t_data *data, t_pos *case_possible, char c)
{
	int	count;

	count = 0;
	while (case_possible)
	{
		if (data->map.all[case_possible->y][case_possible->x] == c)
			count++;
		case_possible = case_possible->next;
	}
	return (count);
}

int	ft_nb_coins(t_data *data)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols)
		{
			if (data->map.all[i][j] == COIN)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_free_list(t_pos *case_possible)
{
	t_pos	*tmp;

	while (case_possible)
	{
		tmp = case_possible;
		case_possible = case_possible->next;
		free(tmp);
	}
}

int	ft_is_new(t_pos *case_possible, int y, int x)
{
	while (case_possible)
	{
		if (y == case_possible->y && x == case_possible->x)
			return (0);
		case_possible = case_possible->next;
	}
	return (1);
}
