/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:45:51 by hypark            #+#    #+#             */
/*   Updated: 2018/05/24 19:53:28 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		ft_cal_time(int hour)
{
	if (hour >= 12 && hour <= 23)
		printf("%d.00 P.M.", hour % 12 == 0 ? 12 : hour % 12);
	else
		printf("%d.00 A.M.", hour % 12 == 0 ? 12 : hour % 12);
}

void		ft_takes_place(int hour)
{
	if (hour < 0 || hour > 24)
		return ;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	ft_cal_time(hour);
	printf(" AND ");
	hour++;
	ft_cal_time(hour % 24);
	printf("\n");
}
