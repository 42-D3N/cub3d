/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:46:05 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/11/11 22:00:57 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/raycasting.h"

static void	compute_perp_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

static void	compute_height(t_draw *draw, t_ray *ray)
{
	draw->line_height = (int)(screen_height / ray->perp_wall_dist);
	draw->start = -draw->line_height / 2 + screen_height / 2 + draw->pitch;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->line_height / 2 + screen_height / 2 + draw->pitch;
	if (draw->end >= screen_height)
		draw->end = screen_height - 1;
}

static void	get_texture_x(t_draw *draw, t_ray *ray, \
	t_img_data *img, t_player *player)
{
	if (ray->side == 0)
		ray->wall_hit = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_hit = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_hit -= floor(ray->wall_hit);
	draw->texture_x = ray->wall_hit * img->width;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		draw->texture_x = img->width - draw->texture_x - 1;
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		draw->texture_x = img->width - draw->texture_x - 1;
}

static void	*pick_texture(t_data *data, t_ray *ray, int side)
{
	if (side == 0)
	{
		if (ray->ray_dir_x < 0)
			return (&data->textures[0]);
		else
			return (&data->textures[2]);
	}
	else
	{
		if (ray->ray_dir_y < 0)
			return (&data->textures[3]);
		else
			return (&data->textures[1]);
	}
}

void	compute_display(t_data *data, t_ray *ray, t_draw *draw, int x)
{
	int			i;
	int			color;
	t_img_data	*texture;

	i = 0;
	compute_perp_dist(ray);
	compute_height(draw, ray);
	texture = pick_texture(data, ray, ray->side);
	get_texture_x(draw, ray, texture, &data->player);
	draw->texture_step = 1.0 * texture->height / draw->line_height;
	draw->texture_iterate = (draw->start - draw->pitch - screen_height / 2
			+ draw->line_height / 2) * draw->texture_step;
	while (i < draw->start)
		mlx_pixel_put(data->mlx, data->window, x, i++, data->ceiling_color);
	while (i < draw->end)
	{
		draw->texture_y = (int)draw->texture_iterate & (texture->height - 1);
		draw->texture_iterate += draw->texture_step;
		color = get_color(texture, draw->texture_x, draw->texture_y);
		mlx_pixel_put(data->mlx, data->window, x, i, color);
		i++;
	}
	while (++i < screen_height - 1)
		mlx_pixel_put(data->mlx, data->window, x, i, data->floor_color);
}
