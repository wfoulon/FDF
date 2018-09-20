/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:29:48 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/13 17:29:49 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_image_back(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, (env->back_img)->img, 0, 0);
}

void		print_image_supp(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, (env->sup_img)->img, 320, 80);
}

void		print_image_graph(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, (env->img)->img, 360, 100);
}

void		print_coords(int x, int y, t_env *env)
{
	char *c;
	char *d;

	print_image(env);
	print_title(env);
	env->x = x - 360;
	env->y = y - 100;
	c = ft_itoa(env->x);
	d = ft_itoa(env->y);
	mlx_string_put(env->mlx, env->win, 190, 300, 0x3A5FCD, c);
	mlx_string_put(env->mlx, env->win, 190, 360, 0x3A5FCD, d);
	free(c);
	free(d);
}
