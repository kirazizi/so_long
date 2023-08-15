/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ma.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:00:40 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/11 11:55:45 by sbzizal          ###   ########.fr       */
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

void	ft_error(t_data *kira)
{
	(void)kira;
	ft_putstr_fd("Error\ngame not valid ! \n", 2);
	exit (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
}
