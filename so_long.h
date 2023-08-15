/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:45:16 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/10 15:35:07 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_data{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	char	**str;
	int		px;
	int		py;
	int		x;
	int		y;
	void	*player;
	void	*wall;
	void	*ard;
	void	*coin;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*exit;
	int		width;
	int		height;
	char	**line;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
	void	*enemy5;
	void	*enemy6;
	void	*chouk;
	int		speed;
	int		speed1;
	int		first_coin_x;
	int		first_coin_y;
	int		en_x;
	int		en_y;
	int		count_move;
	int		count_coins;
	int		e;
	int		p;
	int		c;
	int		n;
	int		m;
	int		error;
}	t_data;

char	*get_next_line(int fd);
char	*ft_read(int fd, char *keep);
size_t	ft_strlen(char *str);
int		ft_strchr( char *str, char c);
char	*ft_strdup( char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check(t_data *zizi);
void	ft_kira(t_data *zizi);
void	ft_valid_or_not(t_data *zizi);
int		animation_coins(t_data *kira, int x, int y);
void	my_map(t_data *kira, int x, int y);
void	source( t_data	*kira);
int		render_map(t_data *kira);
void	end_valid(t_data *kira);
void	move_up(t_data *kira);
void	move_down(t_data *kira);
void	move_right(t_data *kira);
void	move_left(t_data *kira);
int		key_press(int key, t_data *kira);
void	ft_error(t_data *kira);
void	check_wall(t_data *kira);
void	check_map(t_data *kira);
void	copy(t_data *kira);
int		animation_enemy(t_data *kira, int x, int y);
void	enemy(t_data *kira);
char	*ft_itoa(int n);
int		key_destr(t_data *kira);
void	inic(t_data *kira);
void	check_name(char **av);
void	end_valid(t_data *kira);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif