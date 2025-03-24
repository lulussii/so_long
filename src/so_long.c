/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:10:32 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/24 17:12:02 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sort_images(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->walls, x * 120,
			y * 120);
	else if (game->map.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->character, x
			* 120, y * 120);
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectibles, x
			* 120, y * 120);
	else if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x * 120, y
			* 120);
	else if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->background, x
			* 120, y * 120);
}

void	render_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			sort_images(game, y, x);
			x++;
		}
		y++;
	}
}

void	load_textures(t_game *game)
{
	int	x;

	game->background = mlx_xpm_file_to_image(game->mlx, "assets/background.xpm",
			&x, &x);
	game->character = mlx_xpm_file_to_image(game->mlx, "assets/cow.xpm", &x,
			&x);
	game->walls = mlx_xpm_file_to_image(game->mlx, "assets/bush.xpm", &x, &x);
	game->collectibles = mlx_xpm_file_to_image(game->mlx, "assets/flower.xpm",
			&x, &x);
	game->exit = mlx_xpm_file_to_image(game->mlx, "assets/box.xpm", &x, &x);
	if (!game->background || !game->character || !game->walls
		|| !game->collectibles || !game->exit)
		ft_error(game, "Error\nImage not found\n");
}

void	init_game(t_game *game, char **argv)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->background = NULL;
	game->character = NULL;
	game->walls = NULL;
	game->collectibles = NULL;
	game->exit = NULL;
	game->map.map = NULL;
	game->copy_map = NULL;
	game->count_moves = 1;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game, "Error\nProblem with MLX\n");
	check_map(game, argv[1]);
	game->nbr_collectibles = count_collectibles(game);
	load_textures(game);
	game->mlx_win = mlx_new_window(game->mlx, game->map.x * 120, game->map.y
			* 120, "so_long");
	if (!game->mlx_win)
		ft_error(game, "Error\nProblem with MLX\n");
	render_images(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		write(2, "Error: Invalid number of arguments.\n", 36);
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_game(game, argv);
	mlx_hook(game->mlx_win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->mlx_win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
