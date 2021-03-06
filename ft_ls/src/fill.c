/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:09:07 by hypark            #+#    #+#             */
/*   Updated: 2019/08/21 04:17:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/types.h>
#include <time.h>

char				fill_file_mode(uint32_t op, int mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode) && !(op & OP_BL))
		return ('l');
	else if (S_ISLNK(mode) && op & OP_BL)
		return ('d');
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

char				*fill_permission(int mode)
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

void				fill_user_group(t_file *file, struct stat *stat)
{
	struct passwd	*passwd;
	struct group	*group;
	uint32_t		len;

	file->uid = stat->st_uid;
	file->gid = stat->st_gid;
	passwd = getpwuid(file->uid);
	group = getgrgid(file->gid);
	if (passwd != NULL)
	{
		len = ft_strlen(passwd->pw_name);
		file->user = ft_strsub(passwd->pw_name, 0, len);
	}
	else
		file->user = ft_strnew(1);
	if (group != NULL)
	{
		len = ft_strlen(group->gr_name);
		file->group = ft_strsub(group->gr_name, 0, len);
	}
	else
		file->group = ft_strnew(1);
}

void				fill_date(t_file *file, struct stat *stat, uint32_t op)
{
	char			*time;

	file->atime = stat->st_atime;
	file->atimensec = stat->st_atimespec.tv_nsec;
	file->mtime = stat->st_mtime;
	file->mtimensec = stat->st_mtimespec.tv_nsec;
	file->ctime = stat->st_ctime;
	file->ctimensec = stat->st_ctimespec.tv_nsec;
	if (op & OP_U)
	{
		time = ctime(&file->atime);
		fill_atime(file, time);
	}
	else
	{
		time = ctime(&file->mtime);
		fill_mtime(file, time);
	}
}

void				fill_info_ls(t_ls *ls)
{
	struct stat		file_stat;
	char			*temp;
	char			*path;
	uint32_t		i;

	i = -1;
	while (++i < ls->f_num)
	{
		temp = ft_strjoin(ls->prefix, "/");
		path = ft_strjoin(temp, ls->file[i]->name);
		if (lstat(path, &file_stat) >= 0)
		{
			ls->file[i]->mode = fill_file_mode(ls->op, file_stat.st_mode);
			ls->file[i]->permission = fill_permission(file_stat.st_mode);
			ls->file[i]->link = file_stat.st_nlink;
			ls->file[i]->size = file_stat.st_size;
			ls->file[i]->block = file_stat.st_blocks;
			ls->file[i]->major = major(file_stat.st_rdev);
			ls->file[i]->minor = minor(file_stat.st_rdev);
			fill_user_group(ls->file[i], &file_stat);
			fill_date(ls->file[i], &file_stat, ls->op);
		}
		free(temp);
		free(path);
	}
}
