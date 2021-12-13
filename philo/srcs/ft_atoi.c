/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:59 by lyie              #+#    #+#             */
/*   Updated: 2021/11/09 11:00:01 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <limits.h>

static int	ft_whitespace(char test)
{
	if ((test > 8 && test < 14) || test == 32)
		return (0);
	return (1);
}

static int	ft_checksize(int result, int i, char *str)
{
	long int	test;

	test = result;
	if ((test * 10 + (str[i] - '0') > INT_MAX))
		return (1);
	return (0);
}

static int	ft_ret_val(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str, int *ret)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (ft_whitespace(str[i]) == 0)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-')
		i++;
	if (str[i] < 48 || str[i] > 57)
		return (-1);
	*ret = str[i++] - '0';
	while (str[i] > 47 && str[i] < 58)
	{
		if (ft_checksize(*ret, i, (char *)str))
			return (ft_ret_val(sign));
		*ret = ((*ret) * 10) + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-1);
	*ret = *ret * sign;
	return (0);
}
