/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:41:33 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/17 18:13:00 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print(t_ls *ls)
{
	t_dir	*tmp;
	t_file	*tmp_file;

	tmp = ls->directories;
	ft_putstr("directories ----------------------------\n");
	while (tmp)
	{
		ft_putstr("\nDIRECTORY IS ");
		ft_putstr(tmp->name);
		ft_putstr("\n\n");
		tmp_file = tmp->files;
		while (tmp_file)
		{
			ft_putstr("Files: ");
			ft_putstr(tmp_file->name);
			ft_putchar('\n');
			tmp_file = tmp_file->next;
		}
		tmp = tmp->next;
	}
	ft_putstr("end ------------------------------------\n");
}
