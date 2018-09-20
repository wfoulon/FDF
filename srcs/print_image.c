/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:56:50 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/12 14:56:51 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			print_menu(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 1680, 115, 0xd6b017, " M E N U ");
	mlx_string_put(env->mlx, env->win, 1650, 150, 0xD3D3DA, "Sortir : Echap");
	mlx_string_put(env->mlx, env->win, 1650, 200, 0xD3D3DA,\
			"Projection Para : P");
	mlx_string_put(env->mlx, env->win, 1650, 250, 0xD3D3DA,\
			"Projection Iso : I");
	mlx_string_put(env->mlx, env->win, 1650, 300, 0xD3D3DA,\
			"Start : O");
	mlx_string_put(env->mlx, env->win, 1650, 350, 0xD3D3DA,\
			"Plus d'altitude : +");
	mlx_string_put(env->mlx, env->win, 1650, 400, 0xD3D3DA,\
			"Moins d'altitude : -");
	mlx_string_put(env->mlx, env->win, 1650, 450, 0xD3D3DA,\
			"Zoom : scroll arriere");
	mlx_string_put(env->mlx, env->win, 1650, 500, 0xD3D3DA,\
			"Dezoom : scroll avant");
	mlx_string_put(env->mlx, env->win, 1650, 550, 0xD3D3DA,\
			"Deplacement : fleches");
	mlx_string_put(env->mlx, env->win, 1650, 600, 0xD3D3DA,\
			"Rotation : R & T");
	return (0);
}

int			print_title(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 850, 30, 0xd6b017, "File name : ");
	mlx_string_put(env->mlx, env->win, 1000, 30, 0xd6b017, env->filename);
	mlx_string_put(env->mlx, env->win, 50, 300, 0x3A5FCD, "Current x : ");
	mlx_string_put(env->mlx, env->win, 50, 360, 0x3A5FCD, "Current y : ");
	mlx_string_put(env->mlx, env->win, 30, 1030, 0xD3D3DA,\
			"vogsphere@vogsphere.42.fr:intra/2017/ativities/fdf/wfoulon");
	return (print_menu(env));
}

void		print_image(t_env *env)
{
	print_image_back(env);
	print_image_supp(env);
	print_image_graph(env);
}
