/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:07 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/11/10 21:28:20 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/raycasting.h"

int	get_color(t_img_data *img, int x, int y)
{
	return (img->start[img->size_line / 4 * y + x]);
}

void	xpm_img_init(void *mlx, t_img_data *img, char *img_path)
{
	img->img = NULL;
	img->img = mlx_xpm_file_to_image(mlx, img_path, &img->width, &img->height);
	if (img->img)
		img->start = (int *)mlx_get_data_addr(img->img, &img->bpp,
				&img->size_line, &img->endian);
}

void	put_pixel_img(t_img_data *img, int color, int x, int y)
{
	img->start[img->size_line / 4 * y + x] = color;
}
