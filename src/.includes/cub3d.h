/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:19:40 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/11/11 19:10:50 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# include "../../mlx_linux/mlx.h"
# include "../../mlx_linux/mlx_int.h"
# include "../.libft/libft.h"
# include "structs.h"
# include "parsing.h"
# include "raycasting.h"
# include "game_core.h"

# define screen_width 1280
# define screen_height 720
# define texture_size 128
# define CUB3D "CUB3D"

# define ESC 65307
# define LARR 65361
# define RARR 65363
# define L_CTRL 65507
# define L_SHFT 65505

enum e_keys
{
	ESC_K,
	W_K,
	A_K,
	S_K,
	D_K,
	LEFT_K,
	RIGHT_K,
	CTRL_K,
	SHIFT_K
};

int	data_init(t_data *data, t_parsing *parsing);

#endif