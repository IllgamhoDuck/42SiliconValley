/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 20:11:27 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 21:22:22 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void		ft_sort(char **str, int nb)
{
	char	finish;
	char	*temp;
	int		i;

	finish = 0;
	while (finish == 0)
	{
		i = 0;
		finish = 1;
		while (i < nb - 1)
		{
			if (ft_strcmp(str[i + 2], str[i + 1]) < 0)
			{
				finish = 0;
				temp = str[i + 1];
				str[i + 1] = str[i + 2];
				str[i + 2] = temp;
			}
			i++;
		}
	}
}

int			main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc > 0)
	{
		if (argc > 2)
			ft_sort(argv, argc - 1);
		while (i < (argc - 1))
		{
			ft_putstr(argv[i + 1]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
