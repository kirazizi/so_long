/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:35:10 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/03 12:46:01 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy1(t_data *kira, int *flag)
{
	*flag = 1;
	if (kira -> str[kira->en_y][kira->en_x -1] == '1'
		|| kira -> str[kira->en_y][kira->en_x -1] == 'C'
		|| kira -> str[kira->en_y][kira->en_x -1] == 'E'
		|| kira -> str[kira->en_y][kira->en_x -1] == 'M')
				*flag = 0;
	else if (flag && kira -> str[kira->en_y][kira->en_x -1] == '0')
	{
		kira -> str[kira->en_y][kira->en_x] = '0';
		kira->en_x--;
		kira -> str[kira->en_y][kira->en_x] = 'N';
	}
	else if (kira -> str[kira->en_y][kira->en_x -1] == 'P')
		exit(0);
}

void	enemy(t_data *kira)
{
	static int	i;
	static int	flag;

	if (i == 20)
	{
		if (!flag && (kira -> str[kira->en_y][kira->en_x + 1] == '0'))
		{
			kira -> str[kira->en_y][kira->en_x] = '0';
			kira->en_x++;
			kira -> str[kira->en_y][kira->en_x] = 'N';
		}
		else if (kira -> str[kira->en_y][kira->en_x +1] == 'P')
			exit(0);
		else if (kira -> str[kira->en_y][kira->en_x +1] == '1'
		|| kira -> str[kira->en_y][kira->en_x +1] == '0'
		|| kira -> str[kira->en_y][kira->en_x +1] == 'C'
		|| kira -> str[kira->en_y][kira->en_x + 1] == 'E'
		|| kira -> str[kira->en_y][kira->en_x +1] == 'M')
			enemy1(kira, &flag);
	}
	i += 20;
	if (i == 360)
		i = 0;
}
