/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:16:17 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 18:14:21 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"

bool	double_player(char **map)
{
	int	i;
	int	j;
	int	nb_players;

	i = 0;
	nb_players = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				nb_players++;
			j++;
		}
		i++;
	}
	if (nb_players != 1)
		return (true);
	return (false);
}

bool	check_spaces(char **map)
{
	int		i;
	int		j;
	bool	err;

	i = 0;
	err = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				err = true;
			j++;
		}
		i++;
	}
	return (err);
}

bool	map_checker(t_parsing *parsing_data)
{
	bool	err;
	char	**returned_map;

	err = false;
	if (parsing_data == NULL)
		return (true);
	if (double_player(parsing_data->map))
	{
		ft_dprintf(2, "Error\nMultiple players in map.\n");
		return (true);
	}
	flood_fill_setup(parsing_data->map, &returned_map);
	if (check_spaces(returned_map))
	{
		ft_dprintf(2, "Error\nSpace in map.\n");
		err = true;
	}
	ft_arrfree((void **)returned_map);
	return (err);
}
