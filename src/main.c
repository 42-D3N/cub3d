/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:55:14 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/11/12 15:46:19 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".includes/cub3d.h"
#include <time.h>
#include <SDL2/SDL.h>

int	end_program(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx);
	free_par_data(&data->parsing_data);
	mlx_destroy_image(data->mlx, data->textures[0].img);
	mlx_destroy_image(data->mlx, data->textures[1].img);
	mlx_destroy_image(data->mlx, data->textures[2].img);
	mlx_destroy_image(data->mlx, data->textures[3].img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	render(t_data *data)
{
	int	x;

	x = 0;
	move(data);
	if (data->keys[0] == 1)
		end_program(data);
	while (x < screen_width)
	{
		reset_map_pos(&data->player);
		update_ray(&data->camera, &data->player, &data->camera.ray, x);
		dda(&data->player, &data->camera.ray);
		compute_display(data, &data->camera.ray, &data->draw, x);
		x++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_dprintf(2, "Error\nWrong argument number.\n");
		exit(1);
	}
	if (parsing(&data.parsing_data, argv))
	{
		free_par_data(&data.parsing_data);
		exit(1);
	}
	data.mlx = mlx_init();
	if (data_init(&data, &data.parsing_data))
	{
		free_par_data(&data.parsing_data);
		ft_dprintf(2, "Error\nmlx_init failed.\n");
		exit(1);
	}
	mlx_hook(data.window, 2, 1L << 0, &input_pressed, &data);
	mlx_hook(data.window, 3, 1L << 1, &input_released, &data);
	mlx_hook(data.window, 17, 1L << 17, &end_program, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_do_key_autorepeatoff(data.mlx);
	mlx_loop(data.mlx);
}
