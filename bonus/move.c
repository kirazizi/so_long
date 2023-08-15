/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:17:03 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/03 12:39:41 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *kira)
{
	char	*move;

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
		kira->count_move++;
		move = ft_itoa(kira->count_move);
		mlx_string_put(kira->mlx_ptr, kira->mlx_win, 10,
			(kira -> height * 40) + 0, 0xFFFFFF, move);
		free(move);
	}
	else if (kira -> str[kira->py -1][kira->px] == 'E')
		end_valid(kira);
	else if (kira -> str[kira->py -1][kira->px] == 'N'
	|| kira -> str[kira->py -1][kira->px] == 'M')
		exit(0);
}

void	move_down(t_data *kira)
{
	char	*move;

	if (kira -> str[kira->py +1][kira->px] == '0'
	|| kira -> str[kira->py +1][kira->px] == 'C')
	{
		kira -> str[kira->py][kira->px] = '0';
		kira->py++;
		kira -> str[kira->py][kira->px] = 'P';
		mlx_clear_window(kira -> mlx_ptr, kira -> mlx_win);
		render_map(kira);
		kira->count_move++;
		move = ft_itoa(kira->count_move);
		mlx_string_put(kira->mlx_ptr, kira->mlx_win, 10,
			(kira -> height * 40) + 0, 0xFFFFFF, move);
		free(move);
	}
	else if (kira -> str[kira->py +1][kira->px] == 'E')
		end_valid(kira);
	else if (kira -> str[kira->py +1][kira->px] == 'N'
	|| kira -> str[kira->py +1][kira->px] == 'M')
		exit(0);
}

void	move_right(t_data *kira)
{
	char	*move;

	if (kira -> str[kira->py][kira->px +1] == '0'
	|| kira -> str[kira->py][kira->px +1] == 'C')
	{
		kira -> str[kira->py][kira->px] = '0';
		kira->px++;
		kira -> str[kira->py][kira->px] = 'P';
		mlx_clear_window(kira -> mlx_ptr, kira -> mlx_win);
		render_map(kira);
		kira->count_move++;
		move = ft_itoa(kira->count_move);
		mlx_string_put(kira->mlx_ptr, kira->mlx_win, 10,
			(kira -> height * 40) + 0, 0xFFFFFF, move);
		free(move);
	}
	else if (kira -> str[kira->py][kira->px + 1] == 'E')
		end_valid(kira);
	else if (kira -> str[kira->py][kira->px +1] == 'N'
	|| kira -> str[kira->py][kira->px +1] == 'M')
		exit(0);
}

void	move_left(t_data *kira)
{
	char	*move;

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
		kira->count_move++;
		move = ft_itoa(kira->count_move);
		mlx_string_put(kira->mlx_ptr, kira->mlx_win, 10,
			(kira -> height * 40) + 0, 0xFFFFFF, move);
		free(move);
	}
	else if (kira -> str[kira->py][kira->px -1] == 'E')
		end_valid(kira);
	else if (kira -> str[kira->py][kira->px -1] == 'N'
	|| kira -> str[kira->py][kira->px -1] == 'M')
		exit(0);
}

int	key_press(int key, t_data *kira)
{
	if (key == 13 || key == 126)
		move_up(kira);
	else if (key == 1 || key == 125)
		move_down(kira);
	else if (key == 2 || key == 124)
		move_right(kira);
	else if (key == 0 || key == 123)
		move_left(kira);
	else if (key == 53)
	{
		mlx_destroy_window(kira->mlx_ptr, kira->mlx_win);
		exit(0);
	}
	else
		ft_putstr_fd("try just this botton ( W, S, D, A, ESC )\n", 1);
	return (0);
}
