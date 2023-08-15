/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ma.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:51:28 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/02 15:08:01 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	inic(t_data *kira)
{
	kira->e = 0;
	kira->p = 0;
	kira->c = 0;
	kira->n = 0;
	kira->m = 0;
	kira->error = 0;
}

void	check_wall(t_data *kira)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (kira->str[x][++y] != '\n')
	{
		if (kira -> str[x][y] != '1'
		|| kira -> str[kira -> height -1][y] != '1')
			ft_error(kira);
	}
	while (kira -> str[x])
	{
		y = 0;
		while (kira -> str[x][y])
		{
			if (kira -> str[x][y] == '\n')
				break ;
			y++;
		}
		if (y != kira -> width || kira -> str[x][y -1] != '1'
		|| kira -> str[x][0] != '1')
			ft_error(kira);
		x++;
	}
}

void	check_map(t_data *kira)
{
	int	i;
	int	j;

	i = 0;
	while (kira->str[i])
	{
		j = 0;
		while (kira->str[i][j])
		{
			if (kira -> str[i][j] == 'E')
				kira->e++;
			else if (kira -> str[i][j] == 'P')
				kira->p++;
			else if (kira -> str[i][j] == 'C')
				kira->c++;
			if (kira->str[i][j] != 'E' && kira->str[i][j] != 'P'
			&& kira->str[i][j] != 'C' && kira->str[i][j] != '1'
			&& kira->str[i][j] != '0' && kira->str[i][j] != '\n')
				kira->error++;
			j++;
		}
		i++;
	}
	if (kira->c < 1 || kira->p != 1 || kira->e != 1 || kira->error != 0)
		ft_error(kira);
}
