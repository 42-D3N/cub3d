/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:14:24 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/11 19:34:35 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/cub3d.h"

/**
 * @brief Check collision with 4 result possible :
 * 
 * Allow movement | Refuse x movement | Refuse y Movement | Refuse both
 */
static void	check_collision(t_data *data, int x, int y)
{
	if (data->parsing_data.map[x][y] == '1')
	{
		if (data->parsing_data.map[(int)data->player.old_pos_x][y] != '1')
			data->player.pos_x = data->player.old_pos_x;
		else if (data->parsing_data.map[x][(int)data->player.old_pos_y] != '1')
			data->player.pos_y = data->player.old_pos_y;
		else if (data->parsing_data.map[(int)data->player.old_pos_x] \
		[(int)data->player.old_pos_y] != '1')
		{
			data->player.pos_x = data->player.old_pos_x;
			data->player.pos_y = data->player.old_pos_y;
		}
	}
}

/**
 * @brief Update player position while straffing.
 * 
 * It takes incr (true or false if movement is forward or backward) and speed.
 * 
 * `speed` change if CTRL or SHIFT is pressed (see `move()`).
 */
static void	update_thrust(t_data *data, bool incr, float speed)
{
	if (incr == false)
	{
		data->player.pos_x += data->player.old_dir_x * speed;
		data->player.pos_y += data->player.old_dir_y * speed;
		check_collision(data, (int)data->player.pos_x, (int)data->player.pos_y);
	}
	else
	{
		data->player.pos_x -= data->player.old_dir_x * speed;
		data->player.pos_y -= data->player.old_dir_y * speed;
		check_collision(data, (int)data->player.pos_x, (int)data->player.pos_y);
	}
}

/**
 * @brief Update player position while straffing.
 * 
 * It takes left (true or false if movement is `a` or `d`) and speed.
 * 
 * `speed` change if CTRL or SHIFT is pressed (see `move()`).
 */
static void	update_strafe(t_data *data, bool left, float speed)
{
	if (left == false)
	{
		data->player.pos_x += -data->player.old_dir_y * speed;
		data->player.pos_y += data->player.old_dir_x * speed;
		check_collision(data, (int)data->player.pos_x, (int)data->player.pos_y);
	}
	else
	{
		data->player.pos_x += data->player.old_dir_y * speed;
		data->player.pos_y += -data->player.old_dir_x * speed;
		check_collision(data, (int)data->player.pos_x, (int)data->player.pos_y);
	}
}

/**
 * @brief Function that update camera plane and player dir depending of val.
 */
static void	update_camera(t_data *data, float val)
{
	data->player.dir_x = data->player.old_dir_x * cos(val) - \
		data->player.old_dir_y * sin(val);
	data->player.dir_y = data->player.old_dir_x * sin(val) + \
		data->player.old_dir_y * cos(val);
	data->camera.plane_x = data->camera.old_plane_x * cos(val) - \
		data->camera.old_plane_y * sin(val);
	data->camera.plane_y = data->camera.old_plane_x * sin(val) + \
		data->camera.old_plane_y * cos(val);
}

void	move(t_data *data)
{
	float	speed;

	speed = 0.1;
	if (data->keys[7])
		speed = 0.2;
	if (data->keys[8])
		speed = 0.05;
	data->player.old_pos_x = data->player.pos_x;
	data->player.old_pos_y = data->player.pos_y;
	data->player.old_dir_x = data->player.dir_x;
	data->player.old_dir_y = data->player.dir_y;
	data->camera.old_plane_x = data->camera.plane_x;
	data->camera.old_plane_y = data->camera.plane_y;
	if (data->keys[1] && !data->keys[3])
		update_thrust(data, false, speed);
	if (data->keys[3] && !data->keys[1])
		update_thrust(data, true, speed);
	if (data->keys[2] && !data->keys[4])
		update_strafe(data, false, speed);
	if (data->keys[4] && !data->keys[2])
		update_strafe(data, true, speed);
	if (data->keys[5] && !data->keys[6])
		update_camera(data, 0.05);
	if (data->keys[6] && !data->keys[5])
		update_camera(data, -0.05);
}
