/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:52:47 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/31 08:32:03 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *argv, t_game *game)
{
	char	*cmp;
	int		len;
	int		strcmp;

	len = ft_strlen(argv);
	if (len < 5)
	{
		write(2, "Invalid file\n", 13);
		free_all(game);
		exit(1);
	}
	cmp = ft_strrchr(argv, '.');
	strcmp = ft_strncmp(cmp, ".ber", 4);
	if (strcmp || strcmp == -1)
	{
		write(2, "Invalid file\n", 13);
		free_all(game);
		exit(1);
	}
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	j = 0;
	len = ft_strlen(game->map.map[j]);
	while (game->map.map[0][j] != '\n')
	{
		if (game->map.map[0][j++] != '1')
			ft_error(game, "Error\nThe map must be surrounded by walls...\n");
	}
	j = 0;
	while (game->map.map[game->map.y - 1][j])
	{
		if (game->map.map[game->map.y - 1][j++] != '1')
			ft_error(game, "Error\nThe map must be surrounded by walls...\n");
	}
	while (i < game->map.y - 1)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][len - 2] != '1')
			ft_error(game, "Error\nThe map must be surrounded by walls...\n");
		i++;
	}
}

int	check_collectibles(t_game *game, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < game->map.y - 1)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_content(t_game *game)
{
	int	i;
	int	j;

	if (check_collectibles(game, 'C') < 1)
		ft_error(game,
			"Error\nThe map must contain at least one collectible\n");
	if (check_collectibles(game, 'P') != 1)
		ft_error(game,
			"Error\nThe map must contain exactly one start position\n");
	if (check_collectibles(game, 'E') != 1)
		ft_error(game, "Error\nThe map must contain exactly one exit\n");
	i = 0;
	while (i < game->map.y - 1)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1'
				&& game->map.map[i][j] != 'E' && game->map.map[i][j] != 'C'
				&& game->map.map[i][j] != 'P' && game->map.map[i][j] != '\n')
				ft_error(game, "Error\nUnexcepted value in map content\n");
			j++;
		}
		i++;
	}
}

void	check_size(t_game *game)
{
	int	i;
	int	nbr_lines;

	i = 0;
	nbr_lines = game->map.y;
	while (i < nbr_lines - 2)
	{
		if (ft_strlen(game->map.map[0]) != ft_strlen(game->map.map[i]))
			ft_error(game, "Error\nThe map must be rectangular.\n");
		i++;
	}
	if (ft_strlen(game->map.map[nbr_lines - 1]) != ft_strlen(game->map.map[0])
		- 1)
		ft_error(game, "Error\nThe map must be rectangular.\n");
	game->map.x = ft_strlen(game->map.map[0]) - 1;
	if (game->map.x > 32 || game->map.y > 17)
	{
		ft_error(game, "Error\nThe map is too big.\n");
	}
}
