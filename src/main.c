/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:16:35 by yguzman           #+#    #+#             */
/*   Updated: 2016/12/06 12:00:49 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "event_key.h"
#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void		free_all(t_df *df)
{
	int		i;

	i = 0;
	while (i <= df->im.map_max_lon)
	{
		free(df->im.map[i]);
		++i;
	}
	free(df->im.map);
}

void		set_value(int keycode, t_df *data)
{
	if (FL == keycode)
		data->mv.x -= 5;
	if (FU == keycode)
		data->mv.y -= 5;
	if (FR == keycode)
		data->mv.x += 5;
	if (FD == keycode)
		data->mv.y += 5;
	if (W == keycode && data->zm.zoom < 50)
		data->zm.zoom += 1;
	if (S == keycode && data->zm.zoom > 2)
		data->zm.zoom -= 1;
	if (X == keycode && data->zm.haut < 100)
		data->zm.haut += 0.2;
	if (C == keycode && data->zm.haut > -100)
		data->zm.haut -= 0.2;
}

int			event_key(int keycode, void *dt)
{
	t_df	*data;

	data = (t_df *)dt;
	if (ESC == keycode)
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	set_value(keycode, data);
	load_img(data);
	fdf_disp(data);
	disp_img(data);
	return (0);
}

int			quit(void *data)
{
	t_df	*df;

	df = (t_df *)data;
	free_all(df);
	exit(EXIT_SUCCESS);
	return (-260);
}

int			main(int ac, char **av)
{
	t_df	data;

	if (get_data(ac, av, &data) == -1)
		return (-1);
	if (init_win(&data) == -1)
		return (-1);
	ft_putstr("z for zoom\ns for dezoom\narrow for move\n");
	ft_putstr("v && c height\n");
	init_matrice(&(data.matrice));
	init_pos_start(&data);
	load_img(&data);
	fdf_disp(&data);
	disp_img(&data);
	mlx_hook(data.ifm.win, 17, 1L << 17, &quit, &data);
	mlx_hook(data.ifm.win, 2, 1L, &event_key, &data);
	mlx_loop(data.ifm.id);
	return (0);
}
