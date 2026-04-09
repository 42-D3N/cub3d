/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:57:33 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 17:54:25 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"

bool	check_data_paths(char *data, char *msg)
{
	int	fd;

	if (!data)
	{
		ft_dprintf(2, "%s", msg);
		return (true);
	}
	fd = open(data, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "%s", msg);
		return (true);
	}
	close(fd);
	return (false);
}

bool	check_datas(t_parsing *parse_data)
{
	if (parse_data->ceiling[0] == -1 || parse_data->ceiling[1] == -1
		|| parse_data->ceiling[2] == -1)
	{
		ft_dprintf(2, "Error\nMissing ceiling RGB codes.\n");
		return (true);
	}
	if (parse_data->floor[0] == -1 || parse_data->floor[1] == -1
		|| parse_data->floor[2] == -1)
	{
		ft_dprintf(2, "Error\nMissing floor RGB codes.\n");
		return (true);
	}
	if (check_data_paths(parse_data->no_path, "Error\nWrong NO texture file\n"))
		return (true);
	if (check_data_paths(parse_data->so_path, "Error\nWrong SO texture file\n"))
		return (true);
	if (check_data_paths(parse_data->we_path, "Error\nWrong WE texture file\n"))
		return (true);
	if (check_data_paths(parse_data->ea_path, "Error\nWrong EA texture file\n"))
		return (true);
	return (false);
}

int	parsing(t_parsing *parse_data, char **argv)
{
	int		fd;

	all_zero(&parse_data);
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4))
		return (ft_dprintf(2, "Error\nWrong map format.\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_dprintf(2, "Error\nCan't open file.\n"), 1);
	if (get_file(fd, &parse_data->file))
		return (ft_dprintf(2, "Error\nEmpty file.\n"), 1);
	if (get_texture(parse_data))
		return (1);
	if (get_allrgb(parse_data))
		return (1);
	if (check_datas(parse_data))
		return (1);
	if (get_map(&parse_data->map, parse_data->file))
		return (ft_dprintf(2, "Error\nNo map.\n"), 1);
	if (flood_fill_setup(parse_data->map, NULL))
		return (1);
	if (map_checker(parse_data))
		return (1);
	return (0);
}
//debug_info(parse_data);
