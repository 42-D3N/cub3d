/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:37:58 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 17:51:52 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"

void	debug_info(t_parsing *parsing_data)
{
	if (parsing_data->no_path)
		ft_printf("\n\n--> NO path file : [%s] <--\n", parsing_data->no_path);
	if (parsing_data->so_path)
		ft_printf("--> SO path file : [%s] <--\n", parsing_data->so_path);
	if (parsing_data->we_path)
		ft_printf("--> WE path file : [%s] <--\n", parsing_data->we_path);
	if (parsing_data->ea_path)
		ft_printf("--> EA path file : [%s] <--\n", parsing_data->ea_path);
	ft_printf("--> RGB floor : [%d] [%d] [%d] <--\n", parsing_data->floor[0], \
		parsing_data->floor[1], parsing_data->floor[2]);
	ft_printf("--> RGB ceiling  : [%d] [%d] [%d] <--\n\n\n", \
		parsing_data->ceiling[0], \
		parsing_data->ceiling[1], parsing_data->ceiling[2]);
	if (parsing_data->file)
		print_map(parsing_data->file, "File");
	if (parsing_data->map)
		print_map(parsing_data->map, "Map ");
	ft_printf("Valid !\n");
}

void	print_map(char **map, char *title)
{
	int	i;

	i = 0;
	ft_printf("======================== %s ========================\n", title);
	while (map[i])
	{
		printf("[%03d] [%s]\n", i, map[i]);
		i++;
	}
	ft_printf("======================== End  ========================\n");
}
