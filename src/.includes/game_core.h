/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_core.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <tle-pape@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-07 12:19:39 by tle-pape          #+#    #+#             */
/*   Updated: 2025-11-07 12:19:39 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CORE_H
# define GAME_CORE_H

# define PUT_IMG mlx_put_image_to_window

# include "cub3d.h"

/**
 * @brief Function with hook that handle keypress and update datas.
 */
int		input_pressed(int key, t_data *data);

/**
 * @brief Function with hook that handle key releases and update datas.
 */
int		input_released(int key, t_data *data);

/**
 * @brief `move` handle movement by updating player position and camera.
 */
void	move(t_data *data);

#endif