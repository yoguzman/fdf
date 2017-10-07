/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:51:19 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/25 20:23:32 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

float		*fill_map(char **map_char, t_df *data, float *map)
{
	int		i;

	if (map_char == NULL)
		return (NULL);
	i = 0;
	if ((map = malloc(sizeof(float) * (ft_tablen(map_char)))) == NULL)
		return (NULL);
	while (map_char[i])
	{
		map[i] = (float)ft_atoi(map_char[i]);
		if (map[i] < -1000000 || map[i] > 1000000)
			return (ft_puterr_null("Put a height between -1M && 1M\n"));
		++i;
	}
	if (data->im.map_max_la == 0)
		data->im.map_max_la = i - 1;
	if (data->im.map_max_la != i - 1)
		return (ft_puterr_null("sets the same number of number per line\n"));
	if (data->im.map_max_la < 1)
		return (ft_puterr_null("put minimum 2 column\n"));
	free(map_char[0]);
	free(map_char);
	return (map);
}

float		**read_and_fill(int fd, int nb_line, t_df *data)
{
	float	**map;
	char	*line;
	int		ret;

	if ((map = malloc(sizeof(float *) * (nb_line))) == NULL)
		return (NULL);
	data->im.map_max_lon = nb_line - 1;
	data->im.map_max_la = 0;
	nb_line = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (pars_map(line) == -1)
			return (NULL);
		if ((map[nb_line] = fill_map(ft_strsplit(line, ' '),
									data, map[nb_line])) == NULL)
			return (NULL);
		++nb_line;
		free(line);
	}
	if (nb_line < 2)
		return (ft_puterr_null("put minimum 2 line\n"));
	if (ret == -1)
		return (NULL);
	return (map);
}

int			get_data(int ac, char **av, t_df *data)
{
	int		fd;
	int		nb_line;
	float	**map;

	if ((fd = check_arg(ac, av, &nb_line)) == -1)
		return (-1);
	if ((map = read_and_fill(fd, nb_line, data)) == NULL)
		return (-1);
	data->im.map = map;
	return (0);
}
