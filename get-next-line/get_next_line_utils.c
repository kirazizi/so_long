/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:06:07 by sbzizal           #+#    #+#             */
/*   Updated: 2023/01/28 12:18:42 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr( char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strdup( char *s)
{
	int		i;
	char	*src;
	char	*dst;

	src = (char *)s;
	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*src;

	if (!s1)
		s1 = ft_strdup("");
	if (s2)
	{
		src = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!src)
			return (NULL);
		i = -1;
		while (s1[++i])
			src[i] = s1[i];
		i = -1;
		while (s2[++i])
			src[ft_strlen(s1) + i] = s2[i];
		src[ft_strlen(s1) + i] = '\0';
		if (src[0] == '\0')
			return (free (src), free(s1), NULL);
		free (s1);
		return (src);
	}
	return (NULL);
}
