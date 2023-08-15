/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:31:41 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/11 11:56:40 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_name(char **av)
{
	int		name;
	char	*path_map;

	path_map = av[1];
	name = ft_strlen(path_map);
	if (path_map[name -1] != 'r' || path_map[name -2] != 'e'
		|| path_map[name -3] != 'b' || path_map[name -4] != '.')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	inic(t_data *kira)
{
	kira->e = 0;
	kira->p = 0;
	kira->c = 0;
	kira->n = 0;
	kira->m = 0;
	kira->error = 0;
}

int	key_destr(t_data *kira)
{
	(void)kira;
	mlx_destroy_window(kira->mlx_ptr, kira->mlx_win);
	exit(0);
}

void	ft_error(t_data *kira)
{
	(void)kira;
	ft_putstr_fd("Error\ngame not valid ! \n", 2);
	exit (1);
}

void	copy(t_data *kira)
{
	int	i;

	i = 0;
	kira->line = malloc(sizeof(char *) * (kira->height +1));
	if (kira->str == NULL)
		exit (1);
	while (kira->str[i])
	{
		kira->line[i] = ft_strdup(kira->str[i]);
		i++;
	}
	kira->line[i] = 0;
}
