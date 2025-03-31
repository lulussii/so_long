/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:21:18 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/31 08:57:10 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *argv)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

char	**split_map(char *argv, int count)
{
	char	**map;
	int		fd;
	int		i;

	i = 0;
	if (!count)
		return (0);
	fd = open(argv, O_RDONLY);
	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	while (i < count)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[count] = NULL;
	close(fd);
	return (map);
}

void	check_map(t_game *game, char *argv)
{
	check_ber(argv, game);
	game->map.y = count_lines(argv);
	game->map.map = split_map(argv, game->map.y);
	if (!game->map.map)
		ft_error(game, "Error\nThe map seems empty...\n");
	check_size(game);
	check_walls(game);
	check_content(game);
	game->copy_map = ft_copy_map(game);
	find_position_character(game);
	flood_fill(game->copy_map, game->chara_y, game->chara_x);
	check_flood_fill(game->copy_map, game);
}
