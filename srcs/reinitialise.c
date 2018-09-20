/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinitialise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:38:49 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/11 15:38:51 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		refresh(t_env *env)
{
	ft_bzero(env->img->data, env->img->bpp * FENE_X \
			+ env->img->sizeline * FENE_Y);
	mlx_destroy_image(env->mlx, env->img);
	env->img = init_img(env, FENE_X, FENE_Y);
	get_map(env, env->map);
	print_image_graph(env);
}

void		to_other(t_env *env, int i)
{
	if (i != env->proj)
	{
		env->proj = i;
		env->zoom = 1.0;
		env->trans_x = 0;
		env->trans_y = 0;
		env->moove_z = 1.0;
		env->rot_z = 0;
		refresh(env);
	}
}

void		reinitialise(t_env *env)
{
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
	env->trans_x = 0;
	env->trans_y = 0;
	env->zoom = 1.0;
	env->moove_z = 1.0;
	refresh(env);
}

void		ft_fill_len(t_env *env, int lenght, int count)
{
	env->len_x = lenght;
	env->len_y = count;
}

int			ft_free(char **split, t_node **map, int *bo, char *line)
{
	if (!(map = convert_map(split, map, bo)))
	{
		free(line);
		ft_free_tab(split);
		free(map);
		return (0);
	}
	free(line);
	ft_free_tab(split);
	return (1);
}
