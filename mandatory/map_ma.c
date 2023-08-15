/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ma.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:15:42 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/11 12:12:22 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_map(t_data *kira, int x, int y)
{
	if (kira->str[y][x] == '0')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->ard,
			x * 40, y * 40);
	else if (kira->str[y][x] == '1')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->wall,
			x * 40, y * 40);
	else if (kira->str[y][x] == 'C')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->coin,
			x * 40 + 5, y * 40 + 5);
	else if (kira->str[y][x] == 'P')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->player,
			x * 40, y * 40);
	else if (kira->str[y][x] == 'E')
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->exit,
			x * 40, y * 40);
}

void	check_img(t_data *kira)
{
	if (!kira->wall || !kira->ard || !kira->coin || !kira->player
		|| !kira->exit)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}

void	source( t_data	*kira)
{
	int	width;
	int	height;

	kira -> wall = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/wa1.xpm",
			&width, &height);
	kira -> ard = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/map.xpm",
			&width, &height);
	kira -> exit = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/ex.xpm",
			&width, &height);
	kira -> coin = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/cn1.xpm",
			&width, &height);
	kira -> player = mlx_xpm_file_to_image(kira->mlx_ptr, "./src/sh.xpm",
			&width, &height);
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
