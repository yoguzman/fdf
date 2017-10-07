/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:45:41 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/29 14:52:42 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include <math.h>
#include "mlx.h"

void		init_matrice(t_matrice *matrice)
{
	matrice->m1 = (float)sqrt((float)2) / (float)2;
	matrice->m4 = (float)((float)1 / (float)sqrt((float)6));
	matrice->m6 = (float)sqrt((float)2 / (float)3);
}

void		init_pos_start(t_df *data)
{
	data->mv.x = 250;
	data->mv.y = -100;
	data->zm.zoom = 25;
	data->zm.haut = 1;
}

int			init_win(t_df *data)
{
	data->res.x = 680;
	data->res.y = 400;
	if ((data->ifm.id = mlx_init()) == NULL)
		return (-1);
	if ((data->ifm.win = mlx_new_window(data->ifm.id, data->res.x,
										data->res.y, "TONPER")) == NULL)
		return (-1);
	return (0);
}
