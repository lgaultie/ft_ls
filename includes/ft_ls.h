/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:55:22 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/17 18:08:28 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

# include <stdio.h>

# define FLAG_L 1
# define FLAG_BIG_R 2
# define FLAG_A 4
# define FLAG_R 8
# define FLAG_T 16

# define MALLOC "Invalid malloc.\n"
# define WRONG_FILE "Couldn't open file.\n"

typedef struct			s_file
{
	char				*name;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

//directory: avec les fichiers du repertoire

typedef struct			s_dir
{
	char				*name;
	t_file				*files;
	t_file				*curr_file;
	struct s_dir		*prev;
	struct s_dir		*next;
}						t_dir;

// dossier courant avec les fichiers du dossier courant

typedef struct			s_ls
{
	int					flag;
	t_dir				*directories;
	t_dir				*curr_dir;
	t_file				*files;
	t_file				*curr_file;
}						t_ls;

void					init_flag(int *flag, char **av);
void					free_all();
void					get_elements(t_ls *ls, char *av);
void					add_directory(t_ls *ls, char *name);
void					add_file(t_ls *ls, char *name);

// print function to debug
void	print(t_ls *ls);

#endif
