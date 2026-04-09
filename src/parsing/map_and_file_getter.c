/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_file_getter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:07:23 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 17:15:46 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"

bool	get_file(int fd, char ***file)
{
	char	*nl;
	char	*tmp;
	char	*buff;

	buff = ft_strdup("");
	tmp = buff;
	nl = get_next_line(fd);
	if (!nl)
	{
		free(buff);
		close(fd);
		return (true);
	}
	while (nl)
	{
		buff = ft_strjoin(buff, nl);
		free(tmp);
		free(nl);
		nl = get_next_line(fd);
		tmp = buff;
	}
	*file = ft_spacelit(buff, '\n');
	free(tmp);
	close(fd);
	return (false);
}

bool	get_map(char ***map, char **file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i] && j < 6)
	{
		if (file[i][0] != '\0')
			j++;
		i++;
	}
	j = i;
	while (file && file[j] && file[j][0] == '\0')
		j++;
	if (!file[j])
		return (true);
	while (file && file[i])
		i++;
	*map = ft_calloc(sizeof(char *), i - j + 1);
	i = j;
	j = 0;
	while (file[i])
		(*map)[j++] = ft_strdup(file[i++]);
	(*map)[j] = NULL;
	return (false);
}
