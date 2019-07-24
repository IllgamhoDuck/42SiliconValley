/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 23:09:49 by hypark            #+#    #+#             */
/*   Updated: 2018/05/28 23:26:29 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int			ft_tab_len(char **tab)
{
	int		i;
	int		tab_len;

	i = 0;
	tab_len = 0;
	while (tab[i] != 0)
	{
		tab_len++;
		i++;
	}
	return (tab_len);
}

void		ft_str_c(char **tab, int i)
{
	char	*temp;

	temp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = temp;
}

void		ft_sort_wordtab(char **tab)
{
	int		tab_len;
	int		i;
	int		sort_done;

	sort_done = 0;
	tab_len = ft_tab_len(tab);
	while (sort_done == 0)
	{
		i = 0;
		sort_done = 1;
		while (i < (tab_len - 1))
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				sort_done = 0;
				ft_str_c(tab, i);
			}
			i++;
		}
	}
}
