/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:55:02 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/14 23:59:08 by lgaultie         ###   ########.fr       */
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

	(void)ac;
	//recuperer les flags
	init_flag(&flag, av);
	// créer la structure et ajouter le int flag
	init_structure(&ls, flag);
	return (0);
}
