/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:59:38 by lyie              #+#    #+#             */
/*   Updated: 2021/11/09 10:59:41 by lyie             ###   ########.fr       */
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

static int	ft_checksize(long result, int i, const char *str)
{
	long int	test;

	test = result;
	if (((test * 10 + (str[i] - '0')) > INT_MAX))
		return (1);
	return (0);
}

int	ft_atoi_long(const char *str, long *mil_secs)
{
	int	i;

	i = 0;
	if (ft_whitespace(str[i]) == 0)
		i++;
	if (str[i] < 48 || str[i] > 57)
		return (1);
	*mil_secs = str[i++] - '0';
	while (str[i] > 47 && str[i] < 58)
	{
		if (ft_checksize(*mil_secs, i, str) == 1)
			return (1);
		*mil_secs = ((*mil_secs) * 10) + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (1);
	return (0);
}
