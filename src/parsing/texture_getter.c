/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:07:05 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 17:53:34 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"

static bool	store_texture(char *line, char **path)
{
	if ((*path))
	{
		ft_dprintf(2, "Error\nDuplicate texture.\n");
		return (true);
	}
	while (ft_is_whitespace(*line))
		line++;
	(*path) = line;
	return (false);
}

bool	get_texture(t_parsing *parse_data)
{
	int		i;
	bool	err;

	i = 0;
	err = false;
	while (parse_data->file[i] && err != true)
	{
		if (err != true && !ft_strncmp(parse_data->file[i], "NO", 2))
			err = store_texture(parse_data->file[i] + 2, &parse_data->no_path);
		else if (err != true && !ft_strncmp(parse_data->file[i], "SO", 2))
			err = store_texture(parse_data->file[i] + 2, &parse_data->so_path);
		else if (err != true && !ft_strncmp(parse_data->file[i], "WE", 2))
			err = store_texture(parse_data->file[i] + 2, &parse_data->we_path);
		else if (err != true && !ft_strncmp(parse_data->file[i], "EA", 2))
			err = store_texture(parse_data->file[i] + 2, &parse_data->ea_path);
		i++;
	}
	return (err);
}
