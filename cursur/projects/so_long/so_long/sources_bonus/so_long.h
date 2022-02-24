/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:45:03 by ecamara           #+#    #+#             */
/*   Updated: 2022/01/18 12:09:29 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdio.h>
# include "../mlx/mlx.h"

typedef struct s_data
{
	int		x_p;
	int		y_p;
	char	*map;
	char	*check_map;
	char	*asset_map;
	void	**tiles;
	int		movement_c;
	int		max_x;
	int		max_y;
	void	*mlx;
	void	*win;
	void	*img;
	void	*mlx2;
	int		colect;
}t_data;

typedef struct s_error
{
	int		boo;
	int		boo2;
	int		boo3;
	int		error1;
	int		error2;
	int		error3;
	int		error4;
	int		dimensio_err;
}t_error;

/*------------- ERROR ----------- */

void	ft_imput_err(int argc, char *argv[]);
void	ft_check(t_data *data);
void	ft_init(t_error *error);
void	ft_check2(t_error *error, t_data *data);
void	ft_check3(t_error *error, t_data *data, int j, int i);
void	ft_check4(t_error *error, t_data *data);
void	ft_error(t_error *error, t_data *data);

/*---------- IMPUT_PROCESS -------- */

void	ft_asset_map(t_data *data);
//void	ft_create_map(t_data *data);
void	ft_map_read(char *name, t_data *data, int boo);

/* ------------ EVENTS --------------- */

void	ft_enemy_spawn(t_data *data);
void	ft_reaction(t_data *data);
int		ft_events(int keycode, t_data *data);
int		ft_events2(int keycode, t_data *data, int n);
int		ft_events3(int keycode, t_data *data);
int		ft_close(t_data *data);

/*------------- DISPLAY ------------- */

char	*ft_wallcase(int x, int y, t_data *data);
char	*ft_wallcase2(int x, int y, t_data *data, int n);
char	*ft_wallcase3(int x, int y, t_data *data, int n);
char	*ft_wallcase4(int x, int y, t_data *data, int n);
void	ft_dp_map(t_data *data);
void	ft_cases(t_data *data, int x, int y, void *img);
void	ft_frame(t_data *data);
void	ft_frame2(t_data *data, int x, int y);
void	ft_frame3(t_data *data, int x, int y);
void	ft_tile_case(t_data *data, int x, int y, int n);
void	ft_tile_case2(t_data *data, int x, int y, int n);
void	ft_tile_case3(t_data *data, int x, int y, int n);
void	ft_tile_case4(t_data *data, int x, int y, int n);
void	ft_bar(t_data *data);
void	ft_dp_bar(t_data *data);
void	ft_char_st(t_data *data);

/* --------------- EXTRA ------------- */

char	*ft_strjoin_sl(char **s1, char *s2, int boo, int i);
int		ft_random_num(int start, int end);
char	*ft_substr_sl(char **s, int start, int len, int w);
int		ft_next_line_sl(char *temp, int j);
int		ft_line(char *map);
int		ft_ix(int i, int j, int n);
int		ft_strlen_sl(char *str);

#endif