/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:39:44 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/10 13:39:45 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error_conform(void)
{
	ft_putstr("le fichier n'est pas conforme\n");
}

void		error_file(void)
{
	ft_putstr("le fichier n'existe pas\n");
}

void		error_image(void)
{
	ft_putstr("il semblerait que les images soient mal stockées\n");
}

t_env		*ft_error(int argc, char **argv)
{
	int		fd;
	t_env	*env;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf <filename>\n");
		return (NULL);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		error_file();
		return (NULL);
	}
	if (!(ft_strstr(argv[1], ".fdf")) || !(env = init_env(fd, argv[1])))
	{
		error_conform();
		return (NULL);
	}
	if (fill_img(env) == 0)
	{
		error_image();
		return (NULL);
	}
	return (env);
}
