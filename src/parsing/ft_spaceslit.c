/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceslit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:09:43 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 17:15:41 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/parsing.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

static int	ft_strlen_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**free_array(int i, char **arr)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

char	**ft_spacelit(char const *s, char c)
{
	int		i;
	int		nbword;
	int		len;
	char	**arr;

	i = 0;
	nbword = count_word(s, c);
	arr = malloc(sizeof(char *) * (nbword + 1));
	if (!arr)
		return (NULL);
	while (i < nbword)
	{
		if (*s == c && *s)
			s++;
		len = ft_strlen_c((char *) s, c);
		arr[i] = ft_substr(s, 0, len);
		if (!arr[i])
			return (free_array(i, arr));
		s += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
