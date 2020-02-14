/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:55:22 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/14 23:59:48 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <stdio.h>

# define FLAG_L 1
# define FLAG_BIG_R 2
# define FLAG_A 4
# define FLAG_R 8
# define FLAG_T 16

# define MALLOC "Invalid malloc.\n"

typedef struct			s_file
{
	char				*name;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

typedef struct			s_dir
{
	char				*name;
	struct s_file		*prev;
	struct s_file		*next;
}						t_dir;

typedef struct			s_ls
{
	int					flag;
	t_file				*files;
	t_file				*curr_file;
	t_dir				*directories;
	t_dir				*curr_dir;
}						t_ls;

void					init_flag(int *flag, char **av);
void					free_all();

#endif
