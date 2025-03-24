/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:39:01 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/24 17:09:43 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ----- LIBRARIES ----- */

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ----- STRUCTURE ----- */

typedef struct s_resources
{
	char		**map;
	int			x;
	int			y;
}				t_resources;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	void		*background;
	void		*character;
	void		*walls;
	void		*collectibles;
	void		*exit;
	int			nbr_collectibles;
	int			chara_x;
	int			chara_y;
	int			count_moves;
	char		**copy_map;
	int			fd;
	t_resources	map;
}				t_game;

/* ----- FREE_AND_ERROR ----- */

void			free_map(char **map, int len);
void			free_all(t_game *game);
void			ft_error(t_game *game, char *str);

/* ----- PARSING ----- */

int				count_lines(char *argv);
void			check_ber(char *argv, t_game *game);
void			check_walls(t_game *game);
int				check_collectibles(t_game *game, char c);
void			check_content(t_game *game);
void			check_size(t_game *game);
char			**split_map(char *argv, int count);
void			check_map(t_game *game, char *argv);

/* ----- INPUT ----- */

void			find_position_character(t_game *game);
int				handle_keypress(int keycode, t_game *game);
void			move_character(t_game *game, int x, int y);
int				count_collectibles(t_game *game);
int				close_game(t_game *game);

/* ----- SO_LONG ----- */

void			render_images(t_game *game);

/* ----- FLOOD_FILL ----- */

char			**ft_copy_map(t_game *game);
void			check_flood_fill(char **map, t_game *game);
void			flood_fill(char **map, int y, int x);

# ifndef IMAGE_SIZE
#  define IMAGE_SIZE 120

# endif

#endif