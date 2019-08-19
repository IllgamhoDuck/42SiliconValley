/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:09:07 by hypark            #+#    #+#             */
/*   Updated: 2019/08/18 20:58:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/types.h>
#include <time.h>

static char			fill_file_mode(int mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISSOCK(mode))
		return ('s');
	else
		p_error("Unknown file mode has been found\n");
	return (0);
}

static char			*fill_permission(int mode)
{
	char			*permission;

	if (!(permission = (char *)malloc(sizeof(char) * 10)))
		p_error("Memory allocation failed at fill_permission");
	permission[0] = mode & S_IRUSR ? 'r' : '-';
	permission[1] = mode & S_IWUSR ? 'w' : '-';
	permission[2] = mode & S_IXUSR ? 'x' : '-';
	permission[3] = mode & S_IRGRP ? 'r' : '-';
	permission[4] = mode & S_IWGRP ? 'w' : '-';
	permission[5] = mode & S_IXGRP ? 'x' : '-';
	permission[6] = mode & S_IROTH ? 'r' : '-';
	permission[7] = mode & S_IWOTH ? 'w' : '-';
	permission[8] = mode & S_IXOTH ? 'x' : '-';
	permission[9] = '\0';
	return (permission);
}

static void			fill_user_group(t_file *file, struct stat *stat)
{
	struct passwd	*passwd;
	struct group	*group;

	passwd = getpwuid(stat->st_uid);
	group = getgrgid(stat->st_gid);
	file->uid = stat->st_uid;
	file->gid = stat->st_gid;
	file->user = passwd->pw_name;
	file->group = group->gr_name;
}

static void			fill_date(t_file *file)
{
	char			*time;

	time = ctime(&file->ctime);
	ft_strncpy(file->month, time + 4, 3);
	ft_strncpy(file->day, time + 8, 2);
	ft_strncpy(file->year, time + 20, 4);
	ft_strncpy(file->time, time + 11, 5);
	file->month[3] = '\0';
	file->day[2] = '\0';
	file->year[4] = '\0';
	file->time[5] = '\0';
}

void				fill_info_ls(t_ls *ls)
{
	struct stat		file_stat;
	char			*temp;
	char			*path;
	uint32_t		i;

	i = 0;
	while (i < ls->f_num)
	{
		temp = ft_strjoin(ls->prefix, "/");
		path = ft_strjoin(temp, ls->file[i]->name);
		if (lstat(path, &file_stat) < 0)
			p_error("lstat failed while reading the file status");
		ls->file[i]->mode = fill_file_mode(file_stat.st_mode);
		ls->file[i]->permission = fill_permission(file_stat.st_mode);
		ls->file[i]->link = file_stat.st_nlink;
		ls->file[i]->size = file_stat.st_size;
		ls->file[i]->atime = file_stat.st_atime;
		ls->file[i]->mtime = file_stat.st_mtime;
		ls->file[i]->ctime = file_stat.st_ctime;
		fill_user_group(ls->file[i], &file_stat);
		fill_date(ls->file[i]);
		free(temp);
		free(path);
		i++;
	}
}
