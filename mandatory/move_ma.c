/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ma.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:12:29 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/03 12:34:04 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_data *kira)
{
	if (kira -> str[kira->py -1][kira->px] == '0'
	|| kira -> str[kira->py -1][kira->px] == 'C')
	{
		if (kira -> str[kira->py -1][kira->px] == 'E')
			end_valid(kira);
	kira -> str[kira->py][kira->px] = '0';
		kira->py--;
		kira -> str[kira->py][kira->px] = 'P';
		mlx_clear_window(kira -> mlx_ptr, kira -> mlx_win);
		render_map(kira);
		ft_putstr_fd("total movement: ", 1);
		ft_putnbr_fd(++kira->count_move, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (kira -> str[kira->py -1][kira->px] == 'E')
		end_valid(kira);
}

void	down(t_data *kira)
{
	if (kira -> str[kira->py +1][kira->px] == '0'
	|| kira -> str[kira->py +1][kira->px] == 'C')
	{
		kira -> str[kira->py][kira->px] = '0';
		kira->py++;
		kira -> str[kira->py][kira->px] = 'P';
		mlx_clear_window(kira -> mlx_ptr, kira -> mlx_win);
		render_map(kira);
		ft_putstr_fd("total movement: ", 1);
		ft_putnbr_fd(++kira->count_move, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (kira -> str[kira->py +1][kira->px] == 'E')
		end_valid(kira);
}

void	right(t_data *kira)
{
	if (kira -> str[kira->py][kira->px +1] == '0'
	|| kira -> str[kira->py][kira->px +1] == 'C')
	{
		kira -> str[kira->py][kira->px] = '0';
		kira->px++;
		kira -> str[kira->py][kira->px] = 'P';
		mlx_clear_window(kira -> mlx_ptr, kira -> mlx_win);
		render_map(kira);
		ft_putstr_fd("total movement: ", 1);
		ft_putnbr_fd(++kira->count_move, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (kira -> str[kira->py][kira->px + 1] == 'E')
		end_valid(kira);
}

void	left(t_data *kira)
{
	if (kira -> str[kira->py][kira->px -1] == '0'
	|| kira -> str[kira->py][kira->px -1] == 'C')
	{
		if (kira -> str[kira->py][kira->px -1] == 'E')
			end_valid(kira);
		kira -> str[kira->py][kira->px] = '0';
		kira->px--;
		kira -> str[kira->py][kira->px] = 'P';
		mlx_clear_window(kira -> mlx_ptr, kira -> mlx_win);
		render_map(kira);
		ft_putstr_fd("total movement: ", 1);
		ft_putnbr_fd(++kira->count_move, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (kira -> str[kira->py][kira->px -1] == 'E')
		end_valid(kira);
}

int	key_press(int key, t_data *kira)
{
	if (key == 13 || key == 126)
		up(kira);
	else if (key == 1 || key == 125)
		down(kira);
	else if (key == 2 || key == 124)
		right(kira);
	else if (key == 0 || key == 123)
		left(kira);
	else if (key == 53)
	{
		mlx_destroy_window(kira->mlx_ptr, kira->mlx_win);
		exit(0);
	}
	else
		ft_putstr_fd("button not working\n", 1);
	return (0);
}
