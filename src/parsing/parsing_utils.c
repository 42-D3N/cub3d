/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:42:20 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 18:13:03 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"

void	all_zero(t_parsing **map_parsing)
{
	(*map_parsing)->no_path = NULL;
	(*map_parsing)->so_path = NULL;
	(*map_parsing)->we_path = NULL;
	(*map_parsing)->ea_path = NULL;
	(*map_parsing)->map = NULL;
	(*map_parsing)->file = NULL;
	(*map_parsing)->floor[0] = -1;
	(*map_parsing)->floor[1] = -1;
	(*map_parsing)->floor[2] = -1;
	(*map_parsing)->ceiling[0] = -1;
	(*map_parsing)->ceiling[1] = -1;
	(*map_parsing)->ceiling[2] = -1;
}

int	ft_is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	*free_par_data(t_parsing *map_parsing)
{
	if (map_parsing->map)
		ft_arrfree((void **)map_parsing->map);
	if (map_parsing->file)
		ft_arrfree((void **)map_parsing->file);
	return (NULL);
}
