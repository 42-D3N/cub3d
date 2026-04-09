/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:57:37 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/11/14 11:33:46 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./.includes/cub3d.h"

static void	set_orientation(t_player *player, t_camera *camera, char dir)
{
	if (dir == 'N')
	{
		player->dir_x = -1;
		camera->plane_y = 0.66;
	}
	if (dir == 'S')
	{
		player->dir_x = 1;
		camera->plane_y = -0.66;
	}
	if (dir == 'E')
	{
		camera->plane_x = 0.66;
		player->dir_y = 1;
	}
	if (dir == 'W')
	{
		camera->plane_x = -0.66;
		player->dir_y = -1;
	}
}

void	find_player(char **map, t_player *player, t_camera *camera)
{
	int	i;
	int	j;
	int	found_player;

	i = 0;
	found_player = 0;
	while (map[i] && !found_player)
	{
		j = 0;
		while (map[i][j] && !found_player)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				found_player = 1;
			j++;
		}
		i++;
	}
	player->pos_x = i - 0.5;
	player->pos_y = j - 0.5;
	set_orientation(player, camera, map[i - 1][j - 1]);
	player->map = map;
}

void	init_keys(int *keys)
{
	keys[0] = 0;
	keys[1] = 0;
	keys[2] = 0;
	keys[3] = 0;
	keys[4] = 0;
	keys[5] = 0;
	keys[6] = 0;
	keys[7] = 0;
	keys[8] = 0;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	data_init(t_data *data, t_parsing *parsing)
{
	init_keys(data->keys);
	data->ceiling_color = create_trgb(0, data->parsing_data.ceiling[0], \
		data->parsing_data.ceiling[1], data->parsing_data.ceiling[2]);
	data->floor_color = create_trgb(0, data->parsing_data.floor[0], \
		data->parsing_data.floor[1], data->parsing_data.floor[2]);
	camera_init(&data->camera);
	player_init(&data->player);
	data->draw.pitch = 30;
	xpm_img_init(data->mlx, &data->textures[0], parsing->no_path);
	xpm_img_init(data->mlx, &data->textures[1], parsing->ea_path);
	xpm_img_init(data->mlx, &data->textures[2], parsing->so_path);
	xpm_img_init(data->mlx, &data->textures[3], parsing->we_path);
	if (!(&data->textures[0])->img || !(&data->textures[1])->img
		|| !(&data->textures[2])->img || !(&data->textures[3])->img)
		return (ft_dprintf(2, "Error\nImage init failed."), 1);
	find_player(parsing->map, &data->player, &data->camera);
	data->window = mlx_new_window(data->mlx, screen_width,
			screen_height, CUB3D);
	return (0);
}
