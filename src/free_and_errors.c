/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:53:13 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/11 13:09:29 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(t_game *game)
{
	if (game->walls)
		mlx_destroy_image(game->mlx, game->walls);
	if (game->character)
		mlx_destroy_image(game->mlx, game->character);
	if (game->collectibles)
		mlx_destroy_image(game->mlx, game->collectibles);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->background)
		mlx_destroy_image(game->mlx, game->background);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map.map)
		free_map(game->map.map, game->map.y);
	if (game->copy_map)
		free_map(game->copy_map, game->map.y);
	free(game);
}

void	ft_error(t_game *game, char *str)
{
	write(2, str, ft_strlen(str));
	free_all(game);
	exit(1);
}
