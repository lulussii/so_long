/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:36:40 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/24 13:21:49 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_position_character(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->chara_x = x;
				game->chara_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	count_collectibles(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	close_game(t_game *game)
{
	free_all(game);
	exit(0);
}

void	move_character(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->chara_x + x;
	new_y = game->chara_y + y;
	if (game->map.map[new_y][new_x] == '1')
		return ;
	else if (game->map.map[new_y][new_x] == 'C')
		game->nbr_collectibles--;
	else if (game->map.map[new_y][new_x] == 'E')
	{
		if (game->nbr_collectibles == 0)
		{
			close_game(game);
			ft_printf("Félicitations, vous avez fini le jeu en %i coups\n",
				game->count_moves);
		}
		else
			return ;
	}
	game->map.map[game->chara_y][game->chara_x] = '0';
	game->map.map[new_y][new_x] = 'P';
	ft_printf("%i\n", game->count_moves);
	game->count_moves++;
	render_images(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	find_position_character(game);
	if (keycode == 119 || keycode == 65362)
		move_character(game, 0, -1);
	else if (keycode == 97 || keycode == 65361)
		move_character(game, -1, 0);
	else if (keycode == 115 || keycode == 65364)
		move_character(game, 0, 1);
	else if (keycode == 100 || keycode == 65363)
		move_character(game, 1, 0);
	else if (keycode == 65307)
		close_game(game);
	return (0);
}
