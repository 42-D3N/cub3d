/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:01:00 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/11/06 20:21:05 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/raycasting.h"

void	player_init(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 0;
}

void	reset_map_pos(t_player *player)
{
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
}

void	camera_init(t_camera *camera)
{
	camera->plane_x = 0;
	camera->plane_y = 0;
}

void	update_ray(t_camera *camera, t_player *player, t_ray *ray, int x)
{
	camera->x_position = 2 * x / (double)screen_width - 1;
	ray->ray_dir_x = player->dir_x + camera->plane_x * camera->x_position;
	ray->ray_dir_y = player->dir_y + camera->plane_y * camera->x_position;
}
