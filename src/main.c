/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:55:02 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/17 20:49:04 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	init_structure(t_ls *ls, int flag)
{
	if (!(ls = ft_memalloc(sizeof(t_ls))))
		ft_error(ls, &free_all, MALLOC);
	ls->flag = flag;
}

int		main(int ac, char **av)
{
	t_ls			ls;
	int				flag;
	int				i;
	int				flag_on;

	(void)ac;
	flag_on = 0;
	//recuperer les flags
	init_flag(&flag, av);
	// créer la structure et ajouter le int flag
	init_structure(&ls, flag);
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
		{
			flag_on = 1;
			i++;
			continue;
		}
		av[i] = ft_strcat(av[i], "/");
		get_elements(&ls,av[i]);
		i++;
	}
	print(&ls);
	return (0);
}
