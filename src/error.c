/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:01:16 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/25 17:29:29 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <unistd.h>

int			count_line(int fd, int *nb_line)
{
	int		ret;
	int		i;
	char	buff[BUFF_SIZE + 1];

	*nb_line = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		i = 0;
		buff[ret] = '\0';
		while (buff[i])
		{
			if (buff[i] == '\n')
				++(*nb_line);
			++i;
		}
	}
	if (ret < 0)
		return (-1);
	close(fd);
	return (0);
}

int			check_open(char **av)
{
	int		fd;

	if ((fd = open(av[1], O_RDONLY)) < 3)
	{
		ft_putstr_fd("fdf: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": No such valide file\n", 2);
		return (-1);
	}
	return (fd);
}

int			check_arg(int ac, char **av, int *nb_line)
{
	int		fd;

	if (ac != 2)
	{
		ft_putstr_fd("you have ", 2);
		ft_putnbr_fd(ac - 1, 2);
		ft_putstr_fd(" arg, you need one arg !!", 2);
		ft_putstr_fd("\nUSAGE : ./fdf map.txt\n", 2);
		return (-1);
	}
	if ((fd = check_open(av)) == -1)
		return (-1);
	if (count_line(fd, nb_line) == -1)
		return (-1);
	if ((fd = check_open(av)) == -1)
		return (-1);
	return (fd);
}

int			pars_map(char *map_char)
{
	int		j;

	j = 0;
	while (map_char[j])
	{
		if (map_char[j] == '-' && (j == 0 || map_char[j - 1] == ' ') &&
									(ft_isdigit(map_char[j + 1]) == 1))
			;
		else if (ft_isdigit(map_char[j]) == 0 && map_char[j] != ' ')
			return (ft_puterr("bad char in file\n"));
		++j;
	}
	return (0);
}
