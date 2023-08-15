/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:21:54 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/11 11:56:54 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_map(t_data *kira, int x, int y)
{
	if (kira->str[y][x] == '0')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->ard,
			x * 40, y * 40);
	if (kira->str[y][x] == '1')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->wall,
			x * 40, y * 40);
	if (kira->str[y][x] == 'C')
		animation_coins(kira, x, y);
	if (kira->str[y][x] == 'P')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->player,
			x * 40, y * 40);
	if (kira->str[y][x] == 'E')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->exit,
			x * 40, y * 40);
	if (kira->str[y][x] == 'M')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->chouk,
			x * 40, y * 40 +9);
	if (kira->str[y][x] == 'N')
	{
		enemy(kira);
		animation_enemy(kira, x, y);
	}
}

void	check_img(t_data *kira)
{
	if (!kira->wall || !kira->chouk || !kira->ard || !kira->coin1
		|| !kira->coin2 || !kira->coin3 || !kira->coin4 || !kira->coin5
		|| !kira->coin6 || !kira->player || !kira->enemy1 || !kira->enemy2
		|| !kira->enemy3 || !kira->enemy4 || !kira->exit || !kira->enemy5
		|| !kira->enemy6)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}

void	source( t_data	*kira)
{
	int	w;
	int	h;

	kira->wall = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/wa1.xpm", &w, &h);
	kira->chouk = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/chk.xpm", &w, &h);
	kira->ard = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/map1.xpm", &w, &h);
	kira->exit = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/ex.xpm", &w, &h);
	kira->coin1 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/cn1.xpm", &w, &h);
	kira->coin2 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/cn2.xpm", &w, &h);
	kira->coin3 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/cn3.xpm", &w, &h);
	kira->coin4 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/cn4.xpm", &w, &h);
	kira->coin5 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/cn5.xpm", &w, &h);
	kira->coin6 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/cn6.xpm", &w, &h);
	kira->player = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/sh.xpm", &w, &h);
	kira->enemy1 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/e1.xpm", &w, &h);
	kira->enemy2 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/e2.xpm", &w, &h);
	kira->enemy3 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/e3.xpm", &w, &h);
	kira->enemy4 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/e4.xpm", &w, &h);
	kira->enemy5 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/e5.xpm", &w, &h);
	kira->enemy6 = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/e6.xpm", &w, &h);
	check_img(kira);
}

int	render_map(t_data *kira)
{
	int	y;
	int	x;

	y = 0;
	while (kira->str[y])
	{
		x = 0;
		while (kira->str[y][x])
		{
			if (kira->str[y][x] == 'P')
			{
				kira->px = x;
				kira->py = y;
			}
			my_map(kira, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	end_valid(t_data *kira)
{
	int	coins;
	int	j;
	int	i;

	i = 0;
	coins = 0;
	while (kira -> str[i])
	{
		j = 0;
		while (kira -> str[i][j])
		{
			if (kira -> str[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	if (coins == 0)
	{
		ft_putstr_fd("YOU WON\n", 1);
		exit(0);
	}
}
