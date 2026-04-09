/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:46:30 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/11/10 21:27:45 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

void	player_init(t_player *player);
void	reset_map_pos(t_player *player);
void	camera_init(t_camera *camera);
void	xpm_img_init(void *mlx, t_img_data *img, char *img_path);
// void	empty_img_init(void *mlx, t_img_data *img, int width, int height);
int		get_color(t_img_data *img, int x, int y);
void	update_ray(t_camera *camera, t_player *player, t_ray *ray, int x);

int		input_pressed(int key, t_data *data);
int		input_released(int key, t_data *data);

void	dda(t_player *player, t_ray *ray);
void	compute_display(t_data *data, t_ray *ray, t_draw *draw, int x);

#endif