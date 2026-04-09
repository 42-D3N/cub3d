/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:00:15 by tle-pape          #+#    #+#             */
/*   Updated: 2025/11/06 20:28:08 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

/**
 * @brief A copy of split that keep multiple newlines.
 */
char	**ft_spacelit(char const *s, char c);

/**
 * @brief A simple function that check if `c` is a white space.
 */
int		ft_is_whitespace(char c);

/**
 * @brief Free a char **.
 */
void	free_arr(char **arr);

/**
 * @brief Free all datas in `map_data`.
 */
void	*free_par_data(t_parsing *parsing_data);

/**
 * @brief Set all data to 0 in map_data.
 */
void	all_zero(t_parsing **parsing_data);

/**
 * @brief Setup and execute flood_fill.
 */
bool	flood_fill_setup(char **map, char ***returned_map);

/**
 * @brief Print all data in map_data.
 */
void	debug_info(t_parsing *datas);

/**
 * @brief Print map infos with a title.
 */
void	print_map(char **map, char *title);

////// Getter functions. Can be found in corresponding files. \\\\\\

/**
 * @brief This function takes the map from file and store it in `map`.
 */
bool	get_map(char ***map, char **file);

/**
 * @brief This function takes the fd and read the file.
 */
bool	get_file(int fd, char ***file);

/**
 * @brief Takes the `map_data`, get the 2 RGB code and store it.
 */
bool	get_allrgb(t_parsing *parsing_data);

/**
 * @brief Takes the `map_data` and store the texture paths.
 */
bool	get_texture(t_parsing *parsing_data);

/**
 * @brief Check the validity of the map.
 */
bool	map_checker(t_parsing *parsing_data);

/**
 * @brief Parse and store datas.
 */
int	parsing(t_parsing *parsing_data, char **argv);

#endif
