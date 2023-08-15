/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ma.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:33:38 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/02 13:33:40 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_kira(t_data *zizi)
{
	int	x;
	int	y;

	x = 0;
	while (zizi->line[x])
	{
		y = 0;
		while (zizi->line[x][y])
		{
			if (zizi->line[x][y] == '0')
			{
				if (zizi -> line[x][y +1] == 'P' || zizi -> line[x][y -1] == 'P'
				|| zizi->line[x +1][y] == 'P' || zizi-> line[x -1][y] == 'P')
					zizi->line[x][y] = 'P';
			}
			else if (zizi->line[x][y] == 'C')
			{
				if (zizi -> line[x][y +1] == 'P' || zizi -> line[x][y -1] == 'P'
				|| zizi->line[x +1][y] == 'P' || zizi-> line[x -1][y] == 'P')
					zizi->line[x][y] = 'P';
			}
			y++;
		}
		x++;
	}
}

int	ft_check(t_data *zizi)
{
	int	x;
	int	y;

	x = 0;
	while (zizi->line[x])
	{
		y = 0;
		while (zizi->line[x][y])
		{
			y++;
			if (zizi->line[x][y] == '0')
			{
				if (zizi->line[x][y +1] == 'P' || zizi -> line[x][y -1] == 'P'
				|| zizi->line[x +1][y] == 'P' || zizi-> line[x -1][y] == 'P')
					return (1);
			}
			else if (zizi->line[x][y] == 'C')
				if (zizi->line[x][y +1] == 'P' || zizi -> line[x][y -1] == 'P'
				|| zizi->line[x +1][y] == 'P' || zizi-> line[x -1][y] == 'P')
					return (1);
		}
		x++;
	}
	return (0);
}

void	check_exit(t_data *zizi)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (zizi->line[x])
	{
		y = 0;
		while (zizi->line[x][y])
		{
			y++;
			if (zizi->line[x][y] == 'E')
			{
				if (zizi->line[x][y +1] == 'P' || zizi->line[x][y -1] == 'P'
				|| zizi->line[x +1][y] == 'P' || zizi->line[x -1][y] == 'P')
				{
				}
				else
					ft_error(zizi);
			}
		}
		x++;
	}
}

void	ft_valid_or_not(t_data *zizi)
{
	int	x;
	int	y;

	x = 0;
	while (zizi->line[x])
	{
		y = 0;
		while (zizi->line[x][y])
		{
			y++;
			if (zizi->line[x][y] == 'C')
				ft_error(zizi);
		}
		x++;
	}
	check_exit(zizi);
}
