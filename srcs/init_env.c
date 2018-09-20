/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:55:46 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/10 12:55:50 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		new_1(t_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->back_img = NULL;
	env->sup_img = NULL;
	env->len_x = 0;
	env->len_y = 0;
}

void		new_2(t_env *env)
{
	env->x = 0;
	env->y = 0;
	env->zoom = 1.0;
	env->trans_x = 0;
	env->trans_y = 0;
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
	env->moove_z = 1.0;
	env->filename = "";
	env->proj = 0;
	env->color_bool = 0;
	env->mat.x = 0;
	env->mat.y = 0;
	env->mat.z = 0;
	env->mat.c = 0;
}

t_env		*new_env(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	if (!(env->coord = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	new_1(env);
	new_2(env);
	env->coord->z_min = 0;
	env->coord->z_max = 0;
	return (env);
}

t_env		*init_env(int fd, char *av1)
{
	t_env	*env;

	if (!(env = new_env()))
		return (NULL);
	if (!(env->map = fill_map(fd, env)))
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, SIZE_X, SIZE_Y, "Wfoulon's FDF");
	env->img = init_img(env, FENE_X, FENE_Y);
	env->back_img = init_img(env, SIZE_X, SIZE_Y);
	env->sup_img = init_img(env, SUPP_X, SUPP_Y);
	env->filename = get_file_name(av1);
	return (env);
}
