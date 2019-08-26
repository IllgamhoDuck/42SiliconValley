/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdc_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:44:42 by hypark            #+#    #+#             */
/*   Updated: 2019/08/25 20:55:40 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

char *g_mdc_op[5] = {"-p", "-q", "-r", "-s", NULL};

/*
** Reverses the format of the	output.	 This helps with visual	diffs.
** Does nothing when combined	with the -ptx options.
** i == 0  means option -p
** ssl->op &= ~OF_R;
*/

static void			mdc_option_check(t_ssl *ssl, char *s)
{
	int8_t			i;

	i = -1;
	while (g_mdc_op[++i] != NULL)
	{
		if (ft_strcmp(g_mdc_op[i], s) == 0)
		{
			ssl->op |= 1 << i;
			return ;
		}
	}
	unknown_option(s);
}

void				mdc_hash_size(t_ssl *ssl)
{
	ssl->hash_size = g_mdc_hash_size[ssl->mdc];
}

static int			mdc_option_s(t_ssl *ssl, int ac, char **av, uint8_t i)
{
	if (i + 1 < ac)
	{
		mdc_string_process(ssl, av[i + 1]);
		ssl->op |= OP_S;
	}
	else
		s_usage_error(ssl);
	return (i + 1);
}

/*
** input_checker checks the input is valid and store the information
** If there is no files at main parameter the stdin will be used
** t_reader is for standard input fd = 0
** if no main parameter than start stdin
** if -p option is here than parse the standard input
** original md5 stops when -p and no stdin
*/

void				mdc_read_input(int ac, char **av, t_ssl *ssl)
{
	uint8_t			i;

	i = 1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-s") == 0)
			i = mdc_option_s(ssl, ac, av, i);
		else if (ft_strcmp(av[i], "-p") == 0)
		{
			mdc_option_check(ssl, av[i]);
			mdc_stdin_process(ssl);
		}
		else if (av[i][0] == '-')
			mdc_option_check(ssl, av[i]);
		else
		{
			if (!(ssl->files = (char **)malloc(sizeof(char *) * ac - i + 1)))
				malloc_error("ssl->file");
			while (i < ac)
				ssl->files[ssl->total++] = av[i++];
			ssl->files[ssl->total] = NULL;
		}
	}
	if (ssl->total == 0)
		ssl->p_stdin = 1;
}
