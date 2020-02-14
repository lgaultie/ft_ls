/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:56:57 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/14 23:57:13 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	activate_flag(int *flag, char c)
{
	if (c == 'h')
		ft_putstr("print help\n");
	c == 'l' ? *flag |= FLAG_L : 0;
	c == 'R' ? *flag |= FLAG_BIG_R : 0;
	c == 'a' ? *flag |= FLAG_A : 0;
	c == 'r' ? *flag |= FLAG_R : 0;
	c == 't' ? *flag |= FLAG_T : 0;
}

void	init_flag(int *flag, char **av)
{
	char	*flags;
	int		i;
	int		j;

	*flag = 0;
	flags = "hlRart\0";
	j = 0;
	av++;
	while (av[j])
	{
		i = 0;
		while (av[j][0] == '-' && flags[i])
		{
			if (ft_strchr(av[j], flags[i]))
				activate_flag(flag, flags[i]);
			i++;
		}
		j++;
	}
}
