/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:28:28 by lyie              #+#    #+#             */
/*   Updated: 2021/11/26 19:20:06 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list	t_list;

typedef struct s_node
{
	int					id;
	int					dead;
	long				last_meal;
	pthread_mutex_t		*fork1;
	pthread_mutex_t		*fork2;
	pthread_mutex_t		*time_lock;
	pthread_mutex_t		*check_all;
	pthread_mutex_t		*print;
	int					*deaths;
	pthread_mutex_t		*stop;
	int					*stops;
	long				no_philos;
	long				time_to_eat;
	long				time_to_sleep;
	long				time_to_die;
	long				max_eat;
	long long			*start;
	struct s_node		*next;
	t_list				*free_list;
	pthread_mutex_t		*check_last_eat;

}				t_node;

typedef struct s_list
{
	t_node	*head;
}				t_list;

typedef struct s_philos
{
	int					deaths;
	int					i;
	long				no_philos;
	long				time_to_eat;
	long long			timestamp;
	long				time_to_sleep;
	long				time_to_die;
	long				max_eat;
	pthread_mutex_t		*forks;
	int					stops;
	pthread_t			*philos;
	pthread_mutex_t		any_dead;
	pthread_mutex_t		stop;
	pthread_mutex_t		time_lock;
	pthread_mutex_t		*check_last_eat;
	pthread_mutex_t		print;
}					t_philos;

int			ft_atoi_long(const char *str, long *ret);
int			ft_mini_free(t_philos *data);
int			ft_freelist(t_node *head);
int			ft_init_alldata(t_philos *data, t_list *list);
int			ft_init_gen(t_philos *get, char **argv, int argc);
void		ft_dine_alone(t_node *m);
int			ft_health_check(t_list *list, t_philos *data);
int			ft_health_check(t_list *list, t_philos *data);
int			ft_check_stop(t_philos *data);
int			ft_check_deaths(t_node *m);
int			ft_am_i_dead(t_node *m);
int			ft_clear_up(t_philos *data, t_list *list, int ret);
t_node		*ft_newnode(void);
void		ft_lstadd_back(t_list *start, t_node *node);
void		ft_big_free(t_list *list, t_philos *data);
int			ft_atoi(const char *str, int *ret);
int			ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
long long	ft_time(t_node *node);
long long	ft_time_origin(long long start);
void		ft_usleep(long long duration, t_node *philo);
int			ft_error(char *error, int ret);
void		ft_go_eat(t_node *philo);
void		ft_go_sleep(t_node *philo);
void		ft_go_think(t_node *philo);
void		ft_m_free(t_node *m);

#endif
