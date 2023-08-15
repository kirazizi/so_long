/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:50:33 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/01 19:33:13 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map1(t_data *kira, int i, int j)
{
	if (kira->str[i][j] != 'E' && kira->str[i][j] != 'P' &&
		kira->str[i][j] != 'C' && kira->str[i][j] != '1' &&
		kira->str[i][j] != '0' && kira->str[i][j] != 'N' &&
		kira ->str[i][j] != 'M' && kira->str[i][j] != '\n')
			kira->error++;
}

void	check_map2(t_data *kira)
{
	if (kira->c < 1 || kira->p != 1 || kira->e != 1
		|| kira->error != 0 || kira->n < 1 || kira->m < 1)
		ft_error(kira);
}

void	check_map(t_data *kira)
{
	int	i;
	int	j;

	i = -1;
	inic(kira);
	while (kira->str[++i])
	{
		j = 0;
		while (kira->str[i][j])
		{
			if (kira -> str[i][j] == 'E')
				kira->e++;
			else if (kira->str[i][j] == 'N')
				kira->n++;
			else if (kira->str[i][j] == 'M')
				kira->m++;
			else if (kira -> str[i][j] == 'P')
				kira->p++;
			else if (kira -> str[i][j] == 'C')
				kira->c++;
			check_map1(kira, i, j);
			j++;
		}
	}
	check_map2(kira);
}
