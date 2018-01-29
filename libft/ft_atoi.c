/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:39:45 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/27 14:32:00 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long long			ft_atoi(const char *str)
{
	unsigned int	i;
	int				neg;
	long long		ans;

	neg = 1;
	ans = 0;
	i = 0;
	while (ft_escape(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		ans = ans * 10 + (str[i] - 48);
		i++;
	}
	return (ans * neg);
}