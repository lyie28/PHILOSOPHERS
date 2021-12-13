/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:58:20 by lyie              #+#    #+#             */
/*   Updated: 2021/11/23 16:57:32 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_max_eat_routine(t_node *m, int i)
{
	if (i == m->max_eat)
	{
		pthread_mutex_lock(m->stop);
		(*m->stops)++;
		pthread_mutex_unlock(m->stop);
	}
}

static void	*ft_action(void *pointer)
{
	t_node		*m;
	int			i;

	i = 1;
	m = (t_node *)pointer;
	while (ft_check_deaths(m) == 0)
	{
		ft_go_eat(m);
		if (m->max_eat > 0 && i >= m->max_eat)
		{
			ft_max_eat_routine(m, i);
			pthread_mutex_lock(m->stop);
			if ((*m->stops) == m->no_philos)
			{
				pthread_mutex_unlock(m->stop);
				return (NULL);
			}
			pthread_mutex_unlock(m->stop);
		}
		ft_go_sleep(m);
		ft_go_think(m);
		if (m->max_eat > 0)
			i++;
	}
	return (NULL);
}

static int	ft_launch_threads(t_list *list, t_philos *data, int check)
{
	t_node	*node;
	int		i;

	i = 0;
	node = list->head;
	while (i < data->no_philos && node)
	{
		if ((i % 2) == check)
			pthread_create(&data->philos[i], NULL, *ft_action, (void *)(node));
		node = node->next;
		i++;
	}
	return (0);
}

void	ft_main_loop(t_philos *data)
{
	int		i;

	i = -1;
	while (++i < data->no_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->check_last_eat[i], NULL);
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->time_lock, NULL);
	pthread_mutex_init(&data->stop, NULL);
	pthread_mutex_init(&data->any_dead, NULL);
}

int	main(int argc, char **argv)
{
	t_philos	data;
	t_list		*list;
	int			ret;

	if (argc < 5 || argc > 6)
		return (ft_error("Error: arguments\n", 1));
	ret = ft_init_gen(&data, argv, argc);
	if (ret == 1)
		return (ft_error("ERROR\n", 1));
	if (ret == 2)
		return (0);
	list = malloc(sizeof(t_list));
	if (!list)
		return (ft_mini_free(&data));
	if (ft_init_alldata(&data, list) != 0)
		return (ft_mini_free(&data));
	ft_main_loop(&data);
	ft_launch_threads(list, &data, 0);
	ft_launch_threads(list, &data, 1);
	while (ft_health_check(list, &data) == 0)
		;
	return (ft_clear_up(&data, list, ret));
}
