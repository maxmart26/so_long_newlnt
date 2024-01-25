/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:15:29 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/22 16:39:05 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>

# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

# define WINDOW_TITLE "Welcome to catland !"
# define WINDOW_WIDTH 992
# define WINDOW_HEIGHT 640

# define RED_PIXEL "\033[1;31m"
# define GREEN_PIXEL "\033[0;32m"

# define WALL '1'
# define FLOOR '0'
# define COIN 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define ENEMY 'W'

# define UP 1
# define LEFT 2
# define RIGHT 3
# define DOWN 4

# define WALL_XPM "assets/wall/wall.xpm"
# define FLOOR_XPM "assets/floor/floor.xpm"
# define COIN_XPM "assets/coin/fish.xpm"
# define OPEN_EXIT_XPM "assets/exit/open_exit.xpm"
# define CLOSE_EXIT_XPM "assets/exit/close_exit.xpm"
# define P_UP_XPM "assets/player/cat_up.xpm"
# define P_DOWN_XPM "assets/player/cat_down.xpm"
# define P_LEFT_XPM "assets/player/cat_left.xpm"
# define P_RIGHT_XPM "assets/player/cat_right.xpm"
# define E_RIGHT_XPM "assets/enemy/wolf_right.xpm"
# define E_LEFT_XPM "assets/enemy/wolf_left.xpm"

typedef struct s_pos
{
	int				x;
	int				y;
	struct s_pos	*next;
}					t_pos;

typedef struct s_img
{
	void			*xpm_img;
	int				x;
	int				y;
}					t_img;

typedef struct s_map
{
	char			**all;
	int				rows;
	int				cols;
	int				coins;
	int				exit;
	int				players;
	int				enemies;
	t_pos			player;
	t_pos			enemy;
}					t_map;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				map_alloc;
	int				player_sprite;
	int				enemy_sprite;
	int				movements;
	int				life;
	long long		lm;
	t_map			map;
	t_img			wall;
	t_img			floor;
	t_img			coin;
	t_img			open_exit;
	t_img			close_exit;
	t_img			player_up;
	t_img			player_down;
	t_img			player_left;
	t_img			player_right;
	t_img			e_right;
	t_img			e_left;
}					t_data;

int					render_map(t_data *data);
void				map_init(t_data *data, char *argv);
void				check_empty_line(char *map);
char				*ft_strappend(char **s1, char *s2);
void				which_sprite(t_data *data, int y, int x);
void				render_player(t_data *data, int y, int x);
void				render_sprite(t_data *data, t_img sprite, int y, int x);
void				init_values(t_data *data);
void				render_window(t_data *data);
void				init_sprites(t_data *data);
t_img				ft_sprite(void *mlx, char *path);
int					handle_input(int keysym, t_data *data);
void				player_move(t_data *data, int y, int x, int player_sprite);
int					close_window(t_data *data);
void				free_all(t_data *data);
void				destroy_sprites(t_data *data);
void				free_map(t_data *data);
void				check_map(t_data *data);
void				check_rows(t_data *data);
void				check_cols(t_data *data);
int					count_params(t_data *data);
void				verif_params(t_data *data);
void				render_enemy(t_data *data, int y, int x);
void				check_life(t_data *data);
void				print_life(t_data *data);
void				check_enemy(t_data *data, int y, int x);
void				check_args(int ac, char **argv);
int					is_ber_file(const char *argv);
void				enemy_move(t_data *data, int y, int x);
void				enemy_pos(t_data *data);
long long			get_millitimestamps(void);
long long			millitimestamp(void);
int					render_enemy_map(t_data *data);
void				is_player(t_data *data, int y, int x);
void				is_enemy(t_data *data);
void				check_pos_params(t_data *data);
int					check_rectangle(t_data *data);
t_pos				*ft_lstnew2(int y, int x);
int					check_path(t_data *data);
int					find_player(t_data *data);
void				ft_get_case_possible(t_data *data, int y, int x,
						t_pos **case_possible);
int					ft_find_case(t_data *data, t_pos *case_possible, char c);
int					ft_nb_coins(t_data *data);
void				ft_free_list(t_pos *case_possible);
int					ft_is_new(t_pos *case_possible, int y, int x);
t_pos				*ft_lstlast2(t_pos *lst);
void				ft_lstadd_back2(t_pos **lst, t_pos *new);

#endif
