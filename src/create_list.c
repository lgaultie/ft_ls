/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:17:46 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/17 18:09:09 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	add_file(t_ls *ls, char *name)
{
	t_file	*tmp;
	t_file	*new;

	tmp = ls->curr_dir->files;
	if (!(new = ft_memalloc(sizeof(t_file))))
		ft_error(ls, &free_all, MALLOC);
	if (tmp != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
	{
		new->prev = NULL;
		ls->curr_dir->files = new;
	}
	new->next = NULL;
	if (!(new->name = ft_strdup(name)))
		ft_error(ls, &free_all, MALLOC);
	ls->curr_dir->curr_file = new;
}

void	add_directory(t_ls *ls, char *name)
{
	t_dir	*tmp;
	t_dir	*new;

	tmp = ls->directories;
	if (!(new = ft_memalloc(sizeof(t_dir))))
		ft_error(ls, &free_all, MALLOC);
	if (tmp != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
	{
		new->prev = NULL;
		ls->directories = new;
	}
	new->next = NULL;
	if (!(new->name = ft_strdup(name)))
		ft_error(ls, &free_all, MALLOC);
	ls->curr_dir = new;
}
