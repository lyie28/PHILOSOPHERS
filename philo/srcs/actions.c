/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:30:17 by user42            #+#    #+#             */
/*   Updated: 2021/12/13 11:52:00 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_fork_printer(t_node *m)
{
	pthread_mutex_lock(m->print);
	if (ft_check_deaths(m) == 0)
		printf("%lld %d has taken a fork\n", ft_time(m), (m->id) + 1);
	pthread_mutex_unlock(m->print);
}

void	ft_dine_alone(t_node *m)
{
	pthread_mutex_lock(m->fork1);
	if (ft_check_deaths(m) == 0)
	{
		pthread_mutex_lock(m->print);
		printf("%lld %d has taken a fork\n", ft_time(m), (m->id) + 1);
		pthread_mutex_unlock(m->print);
	}
	while (ft_check_deaths(m) == 0)
		;
	pthread_mutex_unlock(m->fork1);
}

void	ft_go_eat(t_node *m)
{
	if (m->no_philos == 1)
		ft_dine_alone(m);
	while (ft_check_deaths(m) == 0)
	{
		pthread_mutex_lock(m->fork1);
		ft_fork_printer(m);
		pthread_mutex_lock(m->fork2);
		ft_fork_printer(m);
		pthread_mutex_lock(m->check_last_eat);
		m->last_meal = ft_time(m);
		pthread_mutex_unlock(m->check_last_eat);
		pthread_mutex_lock(m->print);
		if (ft_check_deaths(m) == 0)
			printf("%ld %d is eating\n", m->last_meal, (m->id) + 1);
		pthread_mutex_unlock(m->print);
		ft_usleep(m->time_to_eat, m);
		pthread_mutex_unlock(m->fork1);
		pthread_mutex_unlock(m->fork2);
		break ;
	}
}

void	ft_go_sleep(t_node *m)
{
	while (ft_check_deaths(m) == 0)
	{
		pthread_mutex_lock(m->print);
		if (ft_check_deaths(m) == 0)
			printf("%lld %d is sleeping\n", ft_time(m), (m->id) + 1);
		pthread_mutex_unlock(m->print);
		ft_usleep(m->time_to_sleep, m);
		break ;
	}
}

void	ft_go_think(t_node *m)
{
	if (ft_check_deaths(m) == 0)
	{
		pthread_mutex_lock(m->print);
		if (ft_check_deaths(m) == 0)
			printf("%lld %d is thinking\n", ft_time(m), (m->id) + 1);
		pthread_mutex_unlock(m->print);
	}
}
