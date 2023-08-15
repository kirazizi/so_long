/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:14:17 by sbzizal           #+#    #+#             */
/*   Updated: 2023/02/10 15:20:38 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy(t_data *kira)
{
	int	i;

	i = 0;
	kira->line = malloc(sizeof(char *) * (kira->height +1));
	if (kira->line == NULL)
		exit(1);
	while (kira->str[i])
	{
		kira->line[i] = ft_strdup(kira->str[i]);
		i++;
	}
	kira->line[i] = 0;
}

int	key_destr(t_data *kira)
{
	(void)kira;
	mlx_destroy_window(kira->mlx_ptr, kira->mlx_win);
	exit(0);
}

int	read_content(t_data *kira, char **av)
{
	int		i;
	int		fd;
	char	*line;

	kira->str = malloc(sizeof(char *) * (kira -> height + 1));
	if (kira->str == NULL)
		exit (1);
	fd = open(av[1], O_RDWR, 0777);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		kira->str[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	kira->str[i] = 0;
	return (0);
}

int	read_map(t_data *kira, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDWR, 0777);
	if (fd < 0)
		ft_error(kira);
	line = get_next_line(fd);
	kira -> height = 0;
	while (line)
	{
		kira -> height++;
		if (kira -> height == 1)
			kira -> width = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	read_content(kira, av);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*kira;

	kira = malloc(sizeof(t_data));
	if (kira == NULL || ac != 2)
		ft_error(kira);
	kira->count_move = 0;
	kira->mlx_ptr = mlx_init();
	check_name(av);
	read_map(kira, av);
	if (!kira->str[0])
		ft_error(kira);
	check_wall(kira);
	inic(kira);
	check_map(kira);
	copy(kira);
	while (ft_check(kira))
		ft_kira(kira);
	ft_valid_or_not(kira);
	kira->mlx_win = mlx_new_window(kira->mlx_ptr, kira -> width * 40,
			kira -> height * 40, "so_long");
	source(kira);
	render_map(kira);
	mlx_hook(kira->mlx_win, 2, 0, key_press, kira);
	mlx_hook(kira->mlx_win, 17, 0, key_destr, kira);
	mlx_loop(kira->mlx_ptr);
}
