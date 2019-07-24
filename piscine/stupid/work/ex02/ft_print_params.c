/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:52:58 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 21:21:41 by hypark           ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc > 0)
	{
		while (i < (argc - 1))
		{
			ft_putstr(argv[i + 1]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
