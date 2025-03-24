/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:22:14 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/24 13:13:14 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(t_game *game)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (game->map.x + 1));
	if (!res)
		ft_error(game, "Error\n");
	i = 0;
	while (game->map.map[i])
	{
		res[i] = ft_strdup(game->map.map[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	else if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'P')
		map[y][x] = 'F';
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		return ;
	}
	if (map[y - 1][x] != '1')
		flood_fill(map, y - 1, x);
	if (map[y + 1][x] != '1')
		flood_fill(map, y + 1, x);
	if (map[y][x - 1] != '1')
		flood_fill(map, y, x - 1);
	if (map[y][x + 1] != '1')
		flood_fill(map, y, x + 1);
}

void	check_flood_fill(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				ft_error(game, "Error\nInvalid map\n");
			}
			x++;
		}
		y++;
	}
}
