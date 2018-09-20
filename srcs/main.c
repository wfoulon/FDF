/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:35:15 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/10 13:35:27 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*get_file_name(char *av1)
{
	char	*str;

	str = NULL;
	if (ft_is_present(av1, '/') == 1)
	{
		str = ft_strrchr(av1, '/');
		str++;
	}
	else
		str = av1;
	return (ft_strsub(str, 0, ft_strlen(str) - 4));
}

void		rescale(t_env *env, t_node **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (x < env->len_x)
		{
			map[y][x].x = FENE_X / 8 + x * FENE_X * 6 / (8 * env->len_x - 1);
			map[y][x].y = FENE_Y / 8 + y * FENE_Y * 6 / (8 * env->len_y - 1);
			x++;
		}
		y++;
	}
}

int			ft_exit(t_env *e)
{
	e = NULL;
	exit(0);
}

void		ft_hook(t_env *env)
{
	mlx_hook(env->win, 2, 1L << 0, key_funct, &env->mlx);
	mlx_mouse_hook(env->win, &mouse_funct, &env->mlx);
	mlx_expose_hook(env->win, &print_title, &env->mlx);
	mlx_hook(env->win, 17, 1l > 17, ft_exit, env);
	mlx_loop(env->mlx);
}

int			main(int argc, char **argv)
{
	t_env *env;

	if (!(env = ft_error(argc, argv)))
		return (0);
	rescale(env, env->map);
	get_map(env, env->map);
	print_image(env);
	ft_hook(env);
	return (0);
}
