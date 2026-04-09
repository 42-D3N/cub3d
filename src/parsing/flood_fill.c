/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:47:27 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 18:15:08 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"
#include <time.h>

char	*edit_line(char *line, int max_len)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = ft_calloc(sizeof(char), max_len + 3);
	new_line[0] = '9';
	while (line[i] && i < max_len)
	{
		new_line[i + 1] = line[i];
		i++;
	}
	if (i < max_len)
	{
		while (i < max_len)
		{
			new_line[i + 1] = ' ';
			i++;
		}
	}
	new_line[i + 1] = '9';
	new_line[i + 2] = '\0';
	return (new_line);
}

void	flood_fill(char ***map, int x, int y)
{
	if (x >= 0 && y >= 0 && (*map) && (*map)[y] && (*map)[y][x] \
	&& (*map)[y][x] != '1' && (*map)[y][x] != '2')
	{
		if ((*map)[y][x] == '0' || (*map)[y][x] == 'N' || (*map)[y][x] == 'S'
			|| (*map)[y][x] == 'E' || (*map)[y][x] == 'W')
		{
			if ((*map)[y][x] != '0')
				ft_dprintf(2, "Error\nPlayer out of map.\n");
			else
				ft_dprintf(2, "Error\nBreach in map.\n");
			ft_arrfree((void **)*map);
			(*map) = NULL;
		}
		else
			(*map)[y][x] = '2';
		if ((*map))
			flood_fill(map, x, y + 1);
		if ((*map))
			flood_fill(map, x + 1, y);
		if ((*map))
			flood_fill(map, x, y - 1);
		if ((*map))
			flood_fill(map, x - 1, y);
	}
}

bool	fill_new_map(char **map, char ***new_map, int nb_line, size_t max_len)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	(*new_map) = ft_calloc(sizeof(char **), nb_line + 3);
	(*new_map)[0] = ft_calloc(sizeof(char *), max_len + 1);
	(*new_map)[nb_line + 1] = ft_calloc(sizeof(char *), max_len + 1);
	while ((size_t)x < max_len + 2)
	{
		(*new_map)[0][x] = '9';
		(*new_map)[nb_line + 1][x] = '9';
		x++;
	}
	(*new_map)[nb_line + 2] = NULL;
	while (map[y])
	{
		(*new_map)[y + 1] = edit_line(map[y], max_len);
		y++;
	}
	flood_fill(new_map, 0, 0);
	if (!(*new_map))
		return (true);
	return (false);
}

bool	flood_fill_setup(char **map, char ***returned_map)
{
	bool	error;
	int		nb_line;
	size_t	max_len;
	char	**new_map;

	error = false;
	nb_line = 0;
	max_len = 0;
	if (!map || (!map && !*map))
		return (ft_dprintf(2, "Error\nWrong map content.\n"), true);
	while (map[nb_line])
	{
		if (ft_strlen(map[nb_line]) > max_len)
			max_len = ft_strlen(map[nb_line]);
		nb_line++;
	}
	if (returned_map)
		error = fill_new_map(map, returned_map, nb_line, max_len);
	else
		error = fill_new_map(map, &new_map, nb_line, max_len);
	if (error == false && !returned_map)
		ft_arrfree((void **)new_map);
	return (error);
}
