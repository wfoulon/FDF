/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:43:06 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/12 11:43:08 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		moove_z(t_env *env, int i)
{
	if (i == 1)
		env->moove_z = env->moove_z * COEFF_Z * (env->moove_z < 1 ? 3 : 1);
	if (i == 0)
		env->moove_z = env->moove_z * COEFF_ZD;
	if (env->moove_z <= 0.02)
		env->moove_z = 0.02;
	refresh(env);
}

void		translation(t_env *env, int nb)
{
	if (nb == 0)
		env->trans_x--;
	else if (nb == 2)
		env->trans_x++;
	else if (nb == 3)
		env->trans_y--;
	else if (nb == 1)
		env->trans_y++;
	else
		;
	refresh(env);
}

void		rotation(t_env *env, int i)
{
	if (i == 4)
		env->rot_z++;
	else if (i == 5)
		env->rot_z--;
	refresh(env);
}

void		zoom(t_env *env)
{
	env->zoom = env->zoom * COEFF_ZOOM;
	refresh(env);
}

void		dezoom(t_env *env)
{
	env->zoom = env->zoom / COEFF_DEZOOM;
	refresh(env);
}
