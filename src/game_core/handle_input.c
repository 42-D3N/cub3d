/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:14:20 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/12 15:59:13 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/cub3d.h"

int	input_pressed(int key, t_data *data)
{
	int			i;
	const int	keys[7] = {ESC, 'w', 'a', 's', 'd', LARR, RARR};

	i = 0;
	while (i < 7)
	{
		if (key == keys[i])
			data->keys[i] = 1;
		i++;
	}
	if (key == L_CTRL && data->keys[CTRL_K])
		data->keys[CTRL_K] = 0;
	else if (key == L_CTRL && !data->keys[CTRL_K])
		data->keys[CTRL_K] = 1;
	if (key == L_SHFT)
	{
		data->keys[CTRL_K] = 0;
		data->keys[SHIFT_K] = 1;
	}
	if (data->keys[1] && data->keys[3])
		data->keys[CTRL_K] = 0;
	if (data->keys[SHIFT_K] == 1)
		data->draw.pitch = 10;
	return (0);
}

int	input_released(int key, t_data *data)
{
	if (key == 'w')
	{
		data->keys[1] = 0;
		data->keys[7] = 0;
	}
	else if (key == 'a')
		data->keys[2] = 0;
	else if (key == 's')
		data->keys[3] = 0;
	else if (key == 'd')
		data->keys[4] = 0;
	else if (key == LARR)
		data->keys[5] = 0;
	else if (key == RARR)
		data->keys[6] = 0;
	else if (key == L_SHFT)
	{
		data->keys[8] = 0;
		data->draw.pitch = 30;
	}
	return (0);
}
