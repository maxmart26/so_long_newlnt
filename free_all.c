/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:41:36 by lnunez-t          #+#    #+#             */
/*   Updated: 2023/12/27 16:47:16 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_data *data)
{
	destroy_sprites(data);
	free_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

void	destroy_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->floor.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->coin.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->player_up.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->player_down.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->player_left.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->player_right.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->open_exit.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->close_exit.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->e_left.xpm_img);
	mlx_destroy_image(data->mlx_ptr, data->e_right.xpm_img);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.rows)
		free(data->map.all[i++]);
	free(data->map.all);
}
