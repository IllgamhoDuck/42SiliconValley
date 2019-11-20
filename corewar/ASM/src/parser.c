/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:22:07 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/17 11:47:21 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Verifies that the filename is valid with .s extension.
*/

t_error			verify_filename(char *filename)
{
	int			len;

	len = ft_strlen(filename);
	if (len <= 3)
		return (ft_strdup("file name too short"));
	if (filename[len - 1] != 's' || filename[len - 2] != '.')
		return (ft_strdup("incorrect file extension"));
	return (NULL);
}

/*
** Fills the champ struct with the content of file described by fd.
*/

t_error			fill_champ(t_champ *champ, int fd)
{
	t_error		err;

	err = get_name(&champ->name, fd);
	if (err)
		return (err);
	err = get_comment(&champ->comment, fd);
	if (err)
		return (err);
	err = get_content(&champ->content, fd);
	if (err)
		return (err);
	return (NULL);
}

/*
** Parses the file into a t_champ struct, does various verifications of input
** and returns err in case of error.
*/

t_error			parser(t_champ *champ, char *filename)
{
	int			fd;
	t_error		err;

	err = verify_filename(filename);
	if (err)
		return (err);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_strdup(strerror(errno)));
	champ->fname = ft_strsub(filename, 0, ft_strlen(filename) - 2);
	err = fill_champ(champ, fd);
	close(fd);
	if (err)
		return (err);
	return (NULL);
}
