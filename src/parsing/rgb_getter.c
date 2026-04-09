/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:06:46 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/14 12:03:00 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"

static int	color_atoi(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			nbr = (nbr * 10) + (str[i] - 48);
		else
			return (-1);
		i++;
	}
	return (nbr);
}

static bool	check_rgb_line(char *line)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(line[i]))
		i++;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || ft_is_whitespace(line[i]) || line[i] == ',')
			i++;
		else
			break ;
	}
	if (line[i])
		return (true);
	return (false);
}

static bool	get_rgb(char *s, int (*data)[3])
{
	int		i;
	int		j;
	long	tmp;
	bool	err;
	char	**strs;

	i = 0;
	j = 0;
	err = false;
	if (err != true)
		err = check_rgb_line(s);
	if ((*data)[0] != -1 || (*data)[1] != -1 || (*data)[2] != -1)
		return (true);
	strs = ft_split(s, ',');
	while (err == false && strs[i])
	{
		tmp = color_atoi(strs[i]);
		if (tmp > 255 || tmp < 0 || (i >= 3 && s[i]))
			err = true;
		(*data)[j] = tmp;
		i++;
		j++;
	}
	ft_arrfree((void **)strs);
	return (err);
}

bool	get_allrgb(t_parsing *parsing_data)
{
	int		i;
	bool	err;

	i = 0;
	err = false;
	while (parsing_data->file[i] && err != true)
	{
		if (err != true && !ft_strncmp(parsing_data->file[i], "C", 1))
			err = get_rgb(parsing_data->file[i] + 2, &parsing_data->ceiling);
		else if (err != true && !ft_strncmp(parsing_data->file[i], "F", 1))
			err = get_rgb(parsing_data->file[i] + 2, &parsing_data->floor);
		i++;
	}
	if (err == true)
		ft_dprintf(2, "Error\nDuplicate or invalid RGB codes.\n");
	return (err);
}
