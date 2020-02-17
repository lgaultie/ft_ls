/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:46:14 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/17 19:33:10 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		is_it_directory(t_ls *ls, char *name, char *av)
{
	struct stat	fileStat;
	char 		*path;
	char 		*file;

	if (!(path = ft_strjoin("./", av)))
		ft_error(ls, &free_all, MALLOC);
	if (!(file = ft_strjoin(path, name)))
		ft_error(ls, &free_all, MALLOC);
	stat(file, &fileStat);

	////////////////////////////
	printf("file = %s\n", file);
	printf("Number of Links: \t%d\n",fileStat.st_nlink);
	printf("File inode: \t\t%llu\n",fileStat.st_ino);
	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
	printf("\n");
	////////////////////////
	if (S_ISDIR(fileStat.st_mode))
	{
		// on n'enregistre pas le dossier courant
		if (ft_strcmp(name, ".") != 0)
		add_directory(ls, file);
	}
	else
	{
		add_file(ls, name);
	}
}

void		get_elements(t_ls *ls, char *av)
{
	DIR				*dir;
	struct dirent	*dit;

	(void)ls;
	if (!(dir = opendir(av)))
	{
		//on essaye d'ouvrir un fichier, il faut juste print son nom.
		ft_putstr(av);
		ft_putchar('\n');
		return ;
	}
	while ((dit = readdir(dir)) != NULL)
	{
		is_it_directory(ls, dit->d_name, av);
	}
	closedir(dir);
}
