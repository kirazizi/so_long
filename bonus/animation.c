/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:19:52 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/01 19:33:07 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_enemy_pos(t_data *kira)
{
	int	i;
	int	j;

	i = 0;
	while (kira->str[i])
	{
		j = 0;
		while (kira->str[i][j])
		{
			if (kira->str[i][j] == 'N')
			{
				kira->en_x = j;
				kira->en_y = i;
				return ;
			}	
			j++;
		}
		i++;
	}
}

int	animation_enemy(t_data *kira, int x, int y)
{	
	get_enemy_pos(kira);
	if (kira->speed1 <= 10)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->enemy1,
			x * 40, y * 40);
	else if (kira->speed1 <= 20)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->enemy2,
			x * 40, y * 40);
	else if (kira->speed1 <= 40)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->enemy3,
			x * 40, y * 40);
	else if (kira->speed1 <= 60)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->enemy4,
			x * 40, y * 40);
	else if (kira->speed1 <= 80)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->enemy5,
			x * 40, y * 40);
	else if (kira->speed1 <= 100)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->enemy6,
			x * 40, y * 40);
	if (x == kira->en_x && y == kira->en_y)
		kira->speed1 += 10;
	if (kira->speed1 == 110)
		kira->speed1 = 0;
	return (0);
}

void	get_coin_pos(t_data *kira)
{
	int	i;
	int	j;

	i = 0;
	while (kira->str[i])
	{
		j = 0;
		while (kira->str[i][j])
		{
			if (kira->str[i][j] == 'C')
			{
				kira->first_coin_x = j;
				kira->first_coin_y = i;
				return ;
			}	
			j++;
		}
		i++;
	}
}

int	animation_coins(t_data *kira, int x, int y)
{	
	get_coin_pos(kira);
	if (kira->speed <= 20)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->coin1,
			x * 40 + 5, y * 40 + 5);
	else if (kira->speed <= 40)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->coin2,
			x * 40 + 5, y * 40 + 5);
	else if (kira->speed <= 60)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->coin3,
			x * 40 + 5, y * 40 + 5);
	else if (kira->speed <= 80)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->coin4,
			x * 40 + 5, y * 40 + 5);
	else if (kira->speed <= 100)
		mlx_put_image_to_window(kira->mlx_ptr, kira->mlx_win, kira->coin5,
			x * 40 + 5, y * 40 + 5);
	if (x == kira->first_coin_x && y == kira->first_coin_y)
		kira->speed += 10;
	if (kira->speed == 110)
		kira->speed = 0;
	return (0);
}
