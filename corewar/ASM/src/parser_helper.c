/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:22:15 by anjansse          #+#    #+#             */
/*   Updated: 2019/11/17 11:56:14 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

static void			read_file(int fd, char **line, int *size, void **free_value)
{
	get_next_line(fd, line);
	while (**line == COMMENT_CHAR || !**line)
	{
		free(*line);
		get_next_line(fd, line);
	}
	*free_value = *line;
	if (ft_strnequ(*line, ".comment", 8) == 0 &&
			ft_strnequ(*line, ".name", 5) == 0)
		send_error(RED"put the correct .name / .comment\n"RESET);
	while (**line && **line != '"')
		(*line)++;
	if (**line)
		(*line)++;
	*size = ft_strlen(*line) - 1;
}

/*
** Reads first line of file described by fd and feeds result into dst.
*/

t_error				get_name(char **dst, int fd)
{
	int			size;
	char		*line;
	char		*name;
	void		*free_value;

	line = NULL;
	free_value = NULL;
	read_file(fd, &line, &size, &free_value);
	if (size < 0 || line[size] != '"' || size > PROG_NAME_LENGTH + 1)
		return (ft_strdup(RED"Name not valid"RESET));
	name = ft_strsub(line, 0, size);
	*dst = name;
	free(free_value);
	return (NULL);
}

/*
** Reads second line of file described by fd and feeds result into dst.
*/

t_error				get_comment(char **dst, int fd)
{
	int			size;
	char		*line;
	char		*comment;
	void		*free_value;

	line = NULL;
	free_value = NULL;
	read_file(fd, &line, &size, &free_value);
	if (size < 0 || line[size] != '"' || size > COMMENT_LENGTH + 1)
		return (ft_strdup(RED"Comment not valid"RESET));
	comment = ft_strsub(line, 0, size);
	*dst = comment;
	free(free_value);
	return (NULL);
}

/*
** Reads file line per line until EOF and feeds concatenation of all into
** dst.
*/

t_error				get_content(char **dst, int fd)
{
	char		*content;
	char		*tmp;
	char		*data;

	content = ft_strdup("");
	while (get_next_line(fd, &tmp) > 0)
	{
		data = ft_strjoinfree1(content, tmp);
		content = ft_strjoin(data, "\n");
		free(data);
		free(tmp);
	}
	*dst = content;
	return (NULL);
}
