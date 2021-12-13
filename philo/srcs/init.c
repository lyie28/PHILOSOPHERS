/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:15:52 by lyie              #+#    #+#             */
/*   Updated: 2021/11/26 19:20:53 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	ft_init_loop(t_philos *get, char **argv, int argc)
{
	get->no_philos = 0;
	if (ft_atoi_long(argv[1], &get->no_philos) != 0)
		return (1);
	if (get->no_philos < 1 || get->no_philos > 200)
		return (1);
	if (ft_atoi_long(argv[2], &get->time_to_die) != 0)
		return (1);
	if (ft_atoi_long(argv[3], &get->time_to_eat) != 0)
		return (1);
	if (ft_atoi_long(argv[4], &get->time_to_sleep) != 0)
		return (1);
	if (get->time_to_die == 0 || get->time_to_sleep == 0
		|| get->time_to_eat == 0)
		return (1);
	if (argc == 6)
	{
		if (ft_atoi_long(argv[5], &get->max_eat) != 0)
			return (1);
	}
	else
		get->max_eat = -1;
	if (get->max_eat == 0)
		return (2);
	return (0);
}

int	ft_init_gen(t_philos *get, char **argv, int argc)
{
	int	ret;

	get->deaths = 0;
	get->stops = 0;
	ret = ft_init_loop(get, argv, argc);
	if (ret != 0)
		return (ret);
	get->forks = malloc (sizeof(pthread_mutex_t) * get->no_philos);
	if (!get->forks)
		return (1);
	get->check_last_eat = malloc (sizeof(pthread_mutex_t) * get->no_philos);
	if (!get->check_last_eat)
	{
		free(get->forks);
		return (1);
	}
	get->philos = malloc (sizeof(pthread_t) * get->no_philos);
	if (!get->philos)
	{
		free(get->forks);
		free(get->check_last_eat);
		return (1);
	}
	get->timestamp = ft_time_origin(0);
	return (0);
}

static void	ft_cont_init_alldata(t_philos *data, t_node *new, int i)
{
	if (i % 2 == 0)
	{
		new->fork1 = &data->forks[i];
		new->fork2 = &data->forks[(i + 1) % data->no_philos];
	}
	else
	{
		new->fork1 = &data->forks[(i + 1) % data->no_philos];
		new->fork2 = &data->forks[i];
	}
	new->time_to_eat = data->time_to_eat;
	new->time_to_sleep = data->time_to_sleep;
	new->time_to_die = data->time_to_die;
	new->max_eat = data->max_eat;
	new->stops = &data->stops;
	new->stop = &data->stop;
	new->time_lock = &data->time_lock;
	new->dead = 0;
}

int	ft_init_alldata(t_philos *data, t_list *list)
{
	int		i;
	t_node	*new;

	i = -1;
	list->head = NULL;
	while (++i < data->no_philos)
	{
		new = ft_newnode();
		if (!new)
			return (1);
		new->start = &data->timestamp;
		new->deaths = &data->deaths;
		new->last_meal = 0;
		new->id = i;
		new->print = &data->print;
		new->check_all = &data->any_dead;
		new->no_philos = data->no_philos;
		new->check_last_eat = &(data->check_last_eat[i]);
		ft_cont_init_alldata(data, new, i);
		ft_lstadd_back(list, new);
	}
	return (0);
}
