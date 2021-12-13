/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:33:50 by lyie              #+#    #+#             */
/*   Updated: 2021/11/23 16:15:57 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_print_dead(t_node *node)
{
	pthread_mutex_lock(node->print);
	printf("%lld %d died\n", ft_time(node), (node->id) + 1);
	pthread_mutex_unlock(node->print);
}

static void	ft_dead_routine(int *count, t_philos *data, t_node *node)
{
	(*count)++;
	pthread_mutex_lock(node->check_all);
	data->deaths = 1;
	pthread_mutex_unlock(node->check_all);
}

int	ft_are_they_dead(t_node *m)
{
	long long	new;
	int			i;

	i = -1;
	new = ft_time(m);
	pthread_mutex_lock(m->check_last_eat);
	if (new - m->last_meal > m->time_to_die)
	{
		pthread_mutex_unlock(m->check_last_eat);
		return (1);
	}
	pthread_mutex_unlock(m->check_last_eat);
	return (0);
}

int	ft_health_check(t_list *list, t_philos *data)
{
	t_node	*node;
	int		i;
	int		count;

	count = 0;
	i = -1;
	node = list->head;
	while (node)
	{
		if (ft_are_they_dead(node) == 1)
		{
			ft_dead_routine(&count, data, node);
			if (count == 1)
				ft_print_dead(node);
			return (1);
		}
		else if (ft_check_stop(data) == 1)
			return (1);
		node = node->next;
	}
	return (0);
}
