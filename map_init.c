/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:28:20 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/25 12:25:50 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strappend(char **s1, char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	check_empty_line(char *map)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
		ft_putstr_fd("Empty line at the beginning of the map !", 1);
	else if (map[ft_strlen(map) - 1] == '\n')
		ft_putstr_fd("Empty line at the end of the map !", 1);
	while (map[i] && map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			ft_putstr_fd("Empty line in the map", 1);
		i++;
	}
}

int	is_ber_file(const char *argv)
{
	char	*str;

	str = ft_strrchr(argv, '.');
	if (str)
		if (ft_strncmp(str, ".ber", ft_strlen(str)) == 0)
			return (1);
	return (0);
}

void	check_args(int ac, char **argv)
{
	if (ac > 2)
	{
		ft_putstr_fd("Could not open multiple maps.", 1);
		exit (EXIT_FAILURE);
	}
	else if (ac == 2 && (is_ber_file(argv[1]) == 0))
	{
		ft_putstr_fd("Map is not a ber file.", 1);
		exit (EXIT_FAILURE);
	}
	else
		return ;
}

void	map_init(t_data *data, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
	{
		ft_putstr_fd("Map could not be opened.", 1);
		exit(EXIT_FAILURE);
	}
	map_temp = ft_strdup("");
	data->map.rows = 0;
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		data->map.rows++;
	}
	close(map_fd);
	check_empty_line(map_temp);
	data->map.all = ft_split(map_temp, '\n');
	data->map_alloc = 1;
	free(map_temp);
}
