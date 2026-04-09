/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:28:59 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/11/10 20:34:50 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPEDEF_H
# define CUB3D_TYPEDEF_H

# include "cub3d.h"

typedef struct s_img_data
{
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		*start;
}	t_img_data;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	old_pos_x;
	double	old_pos_y;

	int		map_x;
	int		map_y;

	double	dir_x;
	double	dir_y;
	double	old_dir_x;
	double	old_dir_y;

	char	**map;
}	t_player;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;

	double	side_dist_x;
	double	side_dist_y;

	double	delta_dist_x;
	double	delta_dist_y;

	int		step_x;
	int		step_y;

	int		side;

	double	perp_wall_dist;
	double	wall_hit;
}	t_ray;

typedef struct s_draw
{
	int		line_height;
	int		pitch;

	int		start;
	int		end;

	double	wall_coord;
	double	texture_step;

	int		texture_x;
	int		texture_y;

	double	texture_iterate;
}	t_draw;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	old_plane_x;
	double	old_plane_y;

	double	x_position;
	t_ray	ray;
}	t_camera;

typedef struct s_parsing
{
	int		floor[3];
	int		ceiling[3];
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	**map;
	char	**file;
}	t_parsing;

/**
 * @brief Data contain all datas.
 * 
 * `mlx` is the mlx pointer.
 * 
 * `window` is the window pointer (mlx).
 * 
 * `keys[9]` represent all keys : `ESC`, `w`, `a`, `s`, `d`, `LARR`, `RARR`
 * , `SHIFT`, `CTRL`.
 * 
 * `floor/ceiling_color` are trgb codes.
 * 
 * `player` contain player datas.
 * 
 * `camera` contain camera datas.
 * 
 * `draw` contain datas for drawing pixels.
 * 
 * `textures[4]` contain all 4 textures.
 * 
 * `t_parsing_data` contain datas like file, map, raw rgb etc...
 */
typedef struct s_data
{
	void		*mlx;
	void		*window;

	int			keys[9];

	int			floor_color;
	int			ceiling_color;
	t_player	player;
	t_camera	camera;
	t_draw		draw;
	t_img_data	textures[4];
	t_img_data	canvas;
	t_parsing	parsing_data;
}	t_data;

#endif