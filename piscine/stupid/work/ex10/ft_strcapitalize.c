/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:34:07 by hypark            #+#    #+#             */
/*   Updated: 2018/05/22 11:31:42 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_lowupcase(char *cap, int *cap_on)
{
	if (*cap >= 'a' && *cap <= 'z')
	{
		if (*cap_on == 1)
		{
			*cap -= 32;
			*cap_on = 0;
		}
	}
	else if (*cap >= 'A' && *cap <= 'Z')
	{
		if (*cap_on == 0)
			*cap += 32;
		else
			*cap_on = 0;
	}
	else if (*cap >= '0' && *cap <= '9')
		*cap_on = 0;
	else
		*cap_on = 1;
}

char		*ft_strcapitalize(char *str)
{
	char	*cap;
	int		cap_on;

	cap = str;
	cap_on = 1;
	while (*cap != '\0')
	{
		ft_lowupcase(cap, &cap_on);
		cap++;
	}
	return (str);
}
