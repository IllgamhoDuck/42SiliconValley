/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:17:23 by hypark            #+#    #+#             */
/*   Updated: 2019/09/13 23:47:41 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				malloc_error(char *str)
{
	ft_printf("%2@Memory Allocation Failed at %s\n", str);
	exit(1);
}

void				print_error(char *str)
{
	ft_printf("%2@%s\n", str);
	exit(1);
}

void				ant_error(void)
{
	ft_printf("%2@ERROR\n");
	exit(1);
}
